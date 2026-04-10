///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H1H1hhfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mHsm,mHsm,sign_mHsmsq,sign_mHsmsq)*H1H1hh
 
     (cos_t, s);
}
double DT::H1H1hG0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mHsm,mG0,sign_mHsmsq,sign_mG0sq)*H1H1hG0
 
     (cos_t, s);
}
double DT::H1H1G0G0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mG0,mG0,sign_mG0sq,sign_mG0sq)*H1H1G0G0
 
     (cos_t, s);
}
double DT::H1H1GCHGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mGch,mGch,sign_mGchsq,sign_mGchsq)*H1H1GCHGch
 
     (cos_t, s);
}
double DT::H1H1hZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mHsm,MZ,sign_mHsmsq,1)*H1H1hZ(cos_t, s);
}
double DT::H1H1G0Zfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mG0,MZ,sign_mG0sq,1)*H1H1G0Z(cos_t, s);
}
double DT::H1H1GCHWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mGch,MW,sign_mGchsq,1)*H1H1GCHW(cos_t, s);
}
double DT::H1H1Gchwfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH1,mH1,mGch,MW,sign_mGchsq,1)*H1H1Gchw(cos_t, s);
}
double DT::H1H1ZZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MZ,MZ)*H1H1ZZ(cos_t, s);
}
double DT::H1H1wWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MW,MW)*H1H1wW(cos_t, s);
}
double DT::H1H1Eefl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,Me,Me)*H1H1Ee(cos_t, s);
}
double DT::H1H1Mmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MM,MM)*H1H1Mm(cos_t, s);
}
double DT::H1H1TAtafl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MTA,MTA)*H1H1TAta(cos_t, s);
}
double DT::H1H1Uufl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MU,MU)*H1H1Uu(cos_t, s);
}
double DT::H1H1Ccfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MC,MC)*H1H1Cc(cos_t, s);
}
double DT::H1H1Ttfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MT,MT)*H1H1Tt(cos_t, s);
}
double DT::H1H1Ddfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MD,MD)*H1H1Dd(cos_t, s);
}
double DT::H1H1Ssfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MS,MS)*H1H1Ss(cos_t, s);
}
double DT::H1H1Bbfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH1,mH1,MB,MB)*H1H1Bb(cos_t, s);
}
