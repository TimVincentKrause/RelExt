#pragma once

#include <limits>
#include <iostream>
#include <cmath>

#include "../data_structures.hpp"


namespace DT{

// Jacobi object
struct Jacobi{
    // size of Matrix
    const size_t n;
    // contains current Matrix do be diagonalised
    MatDoub a;
    // outputs normalised eigenvectors
    MatDoub v;
    // vector containing the eigenvalues of a
    VecDoub d;
    // number of needed Jacobi rotations
    size_t nrot;
    const double EPS = std::numeric_limits<double>::epsilon();


    // in the original there is a numerical limit epsilon on double
    Jacobi(MatDoub aa);

    // sort the eigenvalues I guess
    void eigsrt(VecDoub &d, MatDoub *v=NULL);

    //void rot(MatDoub &a, const double s, const double tau, const size_t i, const size_t j, const size_t k, const size_t l);
};
} // namespace DT
