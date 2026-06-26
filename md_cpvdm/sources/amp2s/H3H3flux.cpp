///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H3H3hhfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mHsm,mHsm,sign_mHsmsq,sign_mHsmsq)*H3H3hh(cos_t, s);
}
double DT::H3H3hG0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mHsm,mG0,sign_mHsmsq,sign_mG0sq)*H3H3hG0(cos_t, s);
}
double DT::H3H3G0G0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mG0,mG0,sign_mG0sq,sign_mG0sq)*H3H3G0G0(cos_t, s);
}
double DT::H3H3GCHGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mGch,mGch,sign_mGchsq,sign_mGchsq)*H3H3GCHGch(cos_t, s);
}
double DT::H3H3hZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mHsm,MZ,sign_mHsmsq,1)*H3H3hZ(cos_t, s);
}
double DT::H3H3G0Zfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mG0,MZ,sign_mG0sq,1)*H3H3G0Z(cos_t, s);
}
double DT::H3H3GCHWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mGch,MW,sign_mGchsq,1)*H3H3GCHW(cos_t, s);
}
double DT::H3H3Gchwfl(const double &cos_t, const double &s){
	using namespace PAR;
	return signedflux(s, mH3,mH3,mGch,MW,sign_mGchsq,1)*H3H3Gchw(cos_t, s);
}
double DT::H3H3ZZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MZ,MZ)*H3H3ZZ(cos_t, s);
}
double DT::H3H3wWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MW,MW)*H3H3wW(cos_t, s);
}
double DT::H3H3Eefl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,Me,Me)*H3H3Ee(cos_t, s);
}
double DT::H3H3Mmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MM,MM)*H3H3Mm(cos_t, s);
}
double DT::H3H3TAtafl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MTA,MTA)*H3H3TAta(cos_t, s);
}
double DT::H3H3Uufl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MU,MU)*H3H3Uu(cos_t, s);
}
double DT::H3H3Ccfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MC,MC)*H3H3Cc(cos_t, s);
}
double DT::H3H3Ttfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MT,MT)*H3H3Tt(cos_t, s);
}
double DT::H3H3Ddfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MD,MD)*H3H3Dd(cos_t, s);
}
double DT::H3H3Ssfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MS,MS)*H3H3Ss(cos_t, s);
}
double DT::H3H3Bbfl(const double &cos_t, const double &s){
	using namespace PAR;
	return flux(s, mH3,mH3,MB,MB)*H3H3Bb(cos_t, s);
}
