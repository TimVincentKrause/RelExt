///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H1H3hhfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mHsm,mHsm,sign_mHsmsq,sign_mHsmsq)*H1H3hh
 
     (cos_t, s);
}
double DT::H1H3hG0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mHsm,mG0,sign_mHsmsq,sign_mG0sq)*H1H3hG0
 
     (cos_t, s);
}
double DT::H1H3G0G0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mG0,mG0,sign_mG0sq,sign_mG0sq)*H1H3G0G0
 
     (cos_t, s);
}
double DT::H1H3GCHGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mGch,mGch,sign_mGchsq,sign_mGchsq)*H1H3GCHGch
 
     (cos_t, s);
}
double DT::H1H3hZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mHsm,MZ,sign_mHsmsq,1)*H1H3hZ(cos_t, s);
}
double DT::H1H3G0Zfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mG0,MZ,sign_mG0sq,1)*H1H3G0Z(cos_t, s);
}
double DT::H1H3GCHWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mGch,MW,sign_mGchsq,1)*H1H3GCHW(cos_t, s);
}
double DT::H1H3Gchwfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mH1,mH3,mGch,MW,sign_mGchsq,1)*H1H3Gchw(cos_t, s);
}
double DT::H1H3ZZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MZ,MZ)*H1H3ZZ(cos_t, s);
}
double DT::H1H3wWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MW,MW)*H1H3wW(cos_t, s);
}
double DT::H1H3VEvefl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,Mnue,Mnue)*H1H3VEve(cos_t, s);
}
double DT::H1H3VMvmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,Mnum,Mnum)*H1H3VMvm(cos_t, s);
}
double DT::H1H3VTvtfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,Mnut,Mnut)*H1H3VTvt(cos_t, s);
}
double DT::H1H3Eefl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,Me,Me)*H1H3Ee(cos_t, s);
}
double DT::H1H3Mmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MM,MM)*H1H3Mm(cos_t, s);
}
double DT::H1H3TAtafl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MTA,MTA)*H1H3TAta(cos_t, s);
}
double DT::H1H3Uufl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MU,MU)*H1H3Uu(cos_t, s);
}
double DT::H1H3Ccfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MC,MC)*H1H3Cc(cos_t, s);
}
double DT::H1H3Ttfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MT,MT)*H1H3Tt(cos_t, s);
}
double DT::H1H3Ddfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MD,MD)*H1H3Dd(cos_t, s);
}
double DT::H1H3Ssfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MS,MS)*H1H3Ss(cos_t, s);
}
double DT::H1H3Bbfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mH1,mH3,MB,MB)*H1H3Bb(cos_t, s);
}
