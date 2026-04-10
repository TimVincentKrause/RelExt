///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::H1HchGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mHsm,mGch,sign_mHsmsq,sign_mGchsq)*H1HchGch
 
     (cos_t, s);
}
double DT::H1HcG0Gchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mG0,mGch,sign_mG0sq,sign_mGchsq)*H1HcG0Gch
 
     (cos_t, s);
}
double DT::H1HchWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mHsm,MW,sign_mHsmsq,1)*H1HchW(cos_t, s);
}
double DT::H1HcG0Wfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mG0,MW,sign_mG0sq,1)*H1HcG0W(cos_t, s);
}
double DT::H1HcGchAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mGch,0,sign_mGchsq,1)*H1HcGchA(cos_t, s);
}
double DT::H1HcGchZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*signedflux(s, mH1,mHc,mGch,MZ,sign_mGchsq,1)*H1HcGchZ(cos_t, s);
}
double DT::H1HcAWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,0,MW)*H1HcAW(cos_t, s);
}
double DT::H1HcZWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MZ,MW)*H1HcZW(cos_t, s);
}
double DT::H1HcveEfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,Mnue,Me)*H1HcveE(cos_t, s);
}
double DT::H1HcvmMfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,Mnum,MM)*H1HcvmM(cos_t, s);
}
double DT::H1HcvtTAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,Mnut,MTA)*H1HcvtTA(cos_t, s);
}
double DT::H1HcuDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MU,MD)*H1HcuD(cos_t, s);
}
double DT::H1HcuSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MU,MS)*H1HcuS(cos_t, s);
}
double DT::H1HcuBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MU,MB)*H1HcuB(cos_t, s);
}
double DT::H1HccDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MC,MD)*H1HccD(cos_t, s);
}
double DT::H1HccSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MC,MS)*H1HccS(cos_t, s);
}
double DT::H1HccBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MC,MB)*H1HccB(cos_t, s);
}
double DT::H1HctDfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MT,MD)*H1HctD(cos_t, s);
}
double DT::H1HctSfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MT,MS)*H1HctS(cos_t, s);
}
double DT::H1HctBfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*2*flux(s, mH1,mHc,MT,MB)*H1HctB(cos_t, s);
}
