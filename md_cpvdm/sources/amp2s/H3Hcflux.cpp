///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H3HchGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mHsm,mGch,sign_mHsmsq,sign_mGchsq)*H3HchGch

     (cos_t, s);
}
double DT::H3HcG0Gchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mG0,mGch,sign_mG0sq,sign_mGchsq)*H3HcG0Gch

     (cos_t, s);
}
double DT::H3HchWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mHsm,MW,sign_mHsmsq,1)*H3HchW(cos_t, s);
}
double DT::H3HcG0Wfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mG0,MW,sign_mG0sq,1)*H3HcG0W(cos_t, s);
}
double DT::H3HcGchAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mGch,0,sign_mGchsq,1)*H3HcGchA(cos_t, s);
}
double DT::H3HcGchZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH3,mHc,mGch,MZ,sign_mGchsq,1)*H3HcGchZ(cos_t, s);
}
double DT::H3HcAWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,0,MW)*H3HcAW(cos_t, s);
}
double DT::H3HcZWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MZ,MW)*H3HcZW(cos_t, s);
}
double DT::H3HcveEfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,Mnue,Me)*H3HcveE(cos_t, s);
}
double DT::H3HcvmMfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,Mnum,MM)*H3HcvmM(cos_t, s);
}
double DT::H3HcvtTAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,Mnut,MTA)*H3HcvtTA(cos_t, s);
}
double DT::H3HcuDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MU,MD)*H3HcuD(cos_t, s);
}
double DT::H3HcuSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MU,MS)*H3HcuS(cos_t, s);
}
double DT::H3HcuBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MU,MB)*H3HcuB(cos_t, s);
}
double DT::H3HccDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MC,MD)*H3HccD(cos_t, s);
}
double DT::H3HccSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MC,MS)*H3HccS(cos_t, s);
}
double DT::H3HccBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MC,MB)*H3HccB(cos_t, s);
}
double DT::H3HctDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MT,MD)*H3HctD(cos_t, s);
}
double DT::H3HctSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MT,MS)*H3HctS(cos_t, s);
}
double DT::H3HctBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH3,mHc,MT,MB)*H3HctB(cos_t, s);
}
