#include "../include/numerical/matrix_operations.hpp"

namespace DT{

// sortiert die Eigenwerte und Eigenzustände aufsteigend
void Jacobi::eigsrt(VecDoub &d, MatDoub *v){
    size_t k;
    size_t n = d.size();
    // go through every element in d
    for (size_t i=0; i<n-1;i++){
        double p = d[k=i];
        // look if there is an element which is smaller
        for (size_t j=i;j<n;j++){
            if (d[j]<=p) {p=d[k=j];}
        }
        // switch the elements
        if (k !=i) {
            d[k] = d[i];
            d[i] =p;
            // redefine the eigenvectors too
            if (v !=NULL) {
                for (size_t j=0; j<n; j++) {
                    p = (*v)[j][i];
                    (*v)[j][i] = (*v)[j][k];
                    (*v)[j][k]=p;
                }
            }
        }
    }
}

inline void rot(MatDoub &a, const double s, const double tau, const size_t i, const size_t j, const size_t k, const size_t l){
    double g = a[i][j];
    double h = a[k][l];
    a[i][j]=g-s*(h+g*tau);
    a[k][l]=h+s*(g-h*tau);
}



Jacobi::Jacobi(MatDoub aa) : n(aa.rows()), a(aa), v(n,n), d(n), nrot(0) {
    // first define some parameters for later use
    size_t i,j,ip, iq;
    double thresh, theta, sm, tau, t, s, h,g,c;
    VecDoub b(n), z(n);

    // initialize the identity matrix
    for (ip=0; ip<n; ip++){
        for (iq=0; iq<n; iq++){
            v[ip][iq]=0.0;
            v[ip][ip]=1.0;
        }
    }
    // initialize b and d to diagonal of a and initialize z
    for (ip=0; ip<n; ip++){
        b[ip] = d[ip] = a[ip][ip];
        // this accumulates t a_pq in a'_pp = a_pp -t a_pq
        z[ip]= 0.0; //so we initialize it with 0
    }

    // this sums of the off-diagonal elements to calculate
    // the threshold value for later
    // Why 50?
    for (i=1; i<=50; i++){
        //a.print();
        sm = 0.0;
        for (ip=0;ip<n-1;ip++){
            for (iq=ip+1;iq<n;iq++){
                sm += std::abs(a[ip][iq]);
            }
        }

        // normal return w/ relies on quadratic convergence to machine underflow (?)
        if (sm == 0.0) {
            eigsrt(d,&v);
            return;
        }

        //set the thresh value. This only impacts the first three sweeps
        if (i < 4){
            thresh = 0.2*sm/(n*n);
        } else {
            thresh = 0.0;
        }


        // iterate over all off-diagonal elements
        for (ip=0;ip<n-1;ip++){
            for (iq=ip+1;iq<n;iq++){
                // what is this g? I think comparison of the element
                g=100.0*std::abs(a[ip][iq]);
                // after 4 sweeps set element to 0.0 if g is small compared to diagonal elements
                // this is done to minimize roundoff errors
                if (i > 4 && g <= EPS*std::abs(d[ip]) && g <= EPS*std::abs(d[iq])){
                    a[ip][iq] = 0.0;

                // if the off-diagonal element is big compared to the threshhold
                } else if (std::abs(a[ip][iq]) > thresh) {


                    // we now calculate t needed to calculate one step

                    // h difference of a_qq and a_pp, in formula for theta
                    h=d[iq]-d[ip];

                    // if the comparison element of the off-diagonal is small
                    // thenw e set t = 1/2theta for overflow protection
                    if (g <= EPS*std::abs(h)){
                        t=(a[ip][iq])/h;
                    } else {
                        // just the formula to calculate t
                        theta = 0.5*h/(a[ip][iq]);
                        t = 1.0/(std::abs(theta)+std::sqrt(1.0+theta*theta));
                        if (theta < 0.0) {t=-t;};
                    }
                    // now definition of the values
                    c = 1.0/std::sqrt(1.0+t*t);
                    s=t*c;
                    tau = s/(1.0+c);
                    h = t*a[ip][iq];

                    //do one step
                    z[ip] -= h;
                    z[iq] += h;
                    d[ip] -= h;
                    d[iq] += h;
                    a[ip][iq] =0.0;


                    //Case of rotations 0 <= j < p
                    for (j=0; j<ip; j++) {rot(a,s,tau,j,ip,j,iq);}
                    //Case of rotations p < j < q
                    for (j=ip+1; j<iq; j++) {rot(a,s,tau,ip,j,j,iq);}
                    //Case of rotations q < j < n
                    for (j=iq+1; j<n; j++) {rot(a,s,tau,ip,j,iq,j);}
                    //Rotation for the eigenvectors
                    for (j=0; j<n; j++) {rot(v,s,tau,j,ip,j,iq);}
                    ++nrot;
                }
            }
        }
        // update d with sum of t apq, and reinitialize z
        for (ip=0;ip<n; ip++) {
            b[ip]+= z[ip];
            d[ip] = b[ip];
            z[ip]=0.0;
        }
    }
    throw("Too many iterations in routine jacobi");

}



} // namespace DT