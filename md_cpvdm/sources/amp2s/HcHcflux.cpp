///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "../../model.hpp"
#include "utils.hpp"

double DT::HcHcGchGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mGch,mGch,sign_mGchsq,sign_mGchsq)*HcHcGchGch

     (cos_t, s);
}
double DT::HcHcGchWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mGch,MW,sign_mGchsq,1)*HcHcGchW(cos_t, s);
}
double DT::HcHcWWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MW,MW)*HcHcWW(cos_t, s);
}
double DT::HcHChhfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mHsm,mHsm,sign_mHsmsq,sign_mHsmsq)*HcHChh

     (cos_t, s);
}
double DT::HcHChG0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mHsm,mG0,sign_mHsmsq,sign_mG0sq)*HcHChG0

     (cos_t, s);
}
double DT::HcHCG0G0fl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mG0,mG0,sign_mG0sq,sign_mG0sq)*HcHCG0G0

     (cos_t, s);
}
double DT::HcHCGCHGchfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mGch,mGch,sign_mGchsq,sign_mGchsq)*HcHCGCHGch

     (cos_t, s);
}
double DT::HcHChAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mHsm,0,sign_mHsmsq,1)*HcHChA(cos_t, s);
}
double DT::HcHChZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mHsm,MZ,sign_mHsmsq,1)*HcHChZ(cos_t, s);
}
double DT::HcHCG0Zfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mG0,MZ,sign_mG0sq,1)*HcHCG0Z(cos_t, s);
}
double DT::HcHCGCHWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mGch,MW,sign_mGchsq,1)*HcHCGCHW(cos_t, s);
}
double DT::HcHCGchwfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*signedflux(s, mHc,mHc,mGch,MW,sign_mGchsq,1)*HcHCGchw(cos_t, s);
}
double DT::HcHCAAfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,0,0)*HcHCAA(cos_t, s);
}
double DT::HcHCAZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,0,MZ)*HcHCAZ(cos_t, s);
}
double DT::HcHCZZfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MZ,MZ)*HcHCZZ(cos_t, s);
}
double DT::HcHCwWfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MW,MW)*HcHCwW(cos_t, s);
}
double DT::HcHCVEvefl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,Mnue,Mnue)*HcHCVEve(cos_t, s);
}
double DT::HcHCVMvmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,Mnum,Mnum)*HcHCVMvm(cos_t, s);
}
double DT::HcHCVTvtfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,Mnut,Mnut)*HcHCVTvt(cos_t, s);
}
double DT::HcHCEefl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,Me,Me)*HcHCEe(cos_t, s);
}
double DT::HcHCMmfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MM,MM)*HcHCMm(cos_t, s);
}
double DT::HcHCTAtafl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MTA,MTA)*HcHCTAta(cos_t, s);
}
double DT::HcHCUufl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MU,MU)*HcHCUu(cos_t, s);
}
double DT::HcHCCcfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MC,MC)*HcHCCc(cos_t, s);
}
double DT::HcHCTtfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MT,MT)*HcHCTt(cos_t, s);
}
double DT::HcHCDdfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MD,MD)*HcHCDd(cos_t, s);
}
double DT::HcHCSsfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MS,MS)*HcHCSs(cos_t, s);
}
double DT::HcHCBbfl(const double &cos_t, const double &s){
	using namespace PAR;
	return 2*flux(s, mHc,mHc,MB,MB)*HcHCBb(cos_t, s);
}
