///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H2HchGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mHsm,mGch,sign_mHsmsq,sign_mGchsq)*H2HchGch

     (cos_t, s);
}
double DT::H2HcG0Gchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mG0,mGch,sign_mG0sq,sign_mGchsq)*H2HcG0Gch

     (cos_t, s);
}
double DT::H2HchWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mHsm,MW,sign_mHsmsq,1)*H2HchW(cos_t, s);
}
double DT::H2HcG0Wfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mG0,MW,sign_mG0sq,1)*H2HcG0W(cos_t, s);
}
double DT::H2HcGchAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mGch,0,sign_mGchsq,1)*H2HcGchA(cos_t, s);
}
double DT::H2HcGchZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH2,mHc,mGch,MZ,sign_mGchsq,1)*H2HcGchZ(cos_t, s);
}
double DT::H2HcAWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,0,MW)*H2HcAW(cos_t, s);
}
double DT::H2HcZWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MZ,MW)*H2HcZW(cos_t, s);
}
double DT::H2HcveEfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,Mnue,Me)*H2HcveE(cos_t, s);
}
double DT::H2HcvmMfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,Mnum,MM)*H2HcvmM(cos_t, s);
}
double DT::H2HcvtTAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,Mnut,MTA)*H2HcvtTA(cos_t, s);
}
double DT::H2HcuDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MU,MD)*H2HcuD(cos_t, s);
}
double DT::H2HcuSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MU,MS)*H2HcuS(cos_t, s);
}
double DT::H2HcuBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MU,MB)*H2HcuB(cos_t, s);
}
double DT::H2HccDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MC,MD)*H2HccD(cos_t, s);
}
double DT::H2HccSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MC,MS)*H2HccS(cos_t, s);
}
double DT::H2HccBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MC,MB)*H2HccB(cos_t, s);
}
double DT::H2HctDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MT,MD)*H2HctD(cos_t, s);
}
double DT::H2HctSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MT,MS)*H2HctS(cos_t, s);
}
double DT::H2HctBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH2,mHc,MT,MB)*H2HctB(cos_t, s);
}
