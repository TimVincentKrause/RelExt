///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include <cmath>

#include <string>

#include <vector>

namespace DT{
namespace PAR{
	// external parameters
	double MZ = 91.1876;
	double aEWM1 = 0.00775795;
	double Gf = 0.0000116637;
	double aS = 0.1172;
	double mHsm = 125.09;
	double mG0 = 91.1876;
	double mGch = 79.947;
	double mHc = 200.;
	double mHm = 200.;
	double alph1 = -0.1;
	double alph2 = -0.1;
	double alph3 = 0.1;
	double mH1 = 100.;
	double mH2 = 200.;
	double m22sq = 100;
	double mssq = 100;
	double L1 = 1;
	double L2 = 0.1;
	double L3 = 1;
	double L4 = 1;
	double L5 = 1;
	double L6 = 0.1;
	double L7 = 1;
	double L8 = 0.1;
	double Treal = 1;
	double Timag = 1;
	double ME = 0;
	double MM = 0.1057;
	double MTA = 1.777;
	double MU = 0;
	double MD = 0;
	double MS = 0;
	double MC = 1.2;
	double MB = 4.23;
	double MT = 172.5;
	double GG = 1.21358;
	double Mnue = 0.;
	double Mnum = 0.;
	double Mnut = 0.;
	double WT = 2.;
	double WZ = 2.4952;
	double WW = 2.085;
	double WHsm = 1.;
	double WH1 = 0.;
	double WH2 = 1.;
	double WH3 = 1.;
	double WHc = 1.;
	double E = 2.71828;
	double Pi = 3.14159;
	double EL = 0.312233;
	double ee = 0.312233;
	double gs = 1.21358;
	double G = 1.21358;
	double FAGS = 1.21358;

	// internal parameters
	double Me;
	double MW;
	double EE;
	double CW2;
	double SW2;
	double CW;
	double SW;
	double g1;
	double g2;
	double v;
	double RR1x1;
	double RR1x2;
	double RR1x3;
	double RR2x1;
	double RR2x2;
	double RR2x3;
	double RR3x1;
	double RR3x2;
	double RR3x3;
	double mH3;
	double m11sq;
	double CKM1x1;
	double CKM1x2;
	double CKM1x3;
	double CKM2x1;
	double CKM2x2;
	double CKM2x3;
	double CKM3x1;
	double CKM3x2;
	double CKM3x3;
	double yu1;
	double yu2;
	double yu3;
	double yd1;
	double yd2;
	double yd3;
	double yl1;
	double yl2;
	double yl3;
	double I1a1;
	double I1a2;
	double I1a3;
	double I2a1;
	double I2a2;
	double I2a3;
	double I3a1;
	double I3a2;
	double I3a3;
	double I4a1;
	double I4a2;
	double I4a3;
	double I5a1;
	double I5a2;
	double I5a3;
	double I6a1;
	double I6a2;
	double I6a3;
	double I7a1;
	double I7a2;
	double I7a3;
	// thermal parameters
	std::vector<double> temp_therm;
	std::vector<double> Mnue_therm;
	std::vector<double> Mnum_therm;
	std::vector<double> Mnut_therm;
	std::vector<double> Me_therm;
	std::vector<double> MM_therm;
	std::vector<double> MTA_therm;
	std::vector<double> MU_therm;
	std::vector<double> MC_therm;
	std::vector<double> MT_therm;
	std::vector<double> MD_therm;
	std::vector<double> MS_therm;
	std::vector<double> MB_therm;
	std::vector<double> MZ_therm;
	std::vector<double> MW_therm;
	std::vector<double> mHsmsq_therm;
	std::vector<double> mG0sq_therm;
	std::vector<double> mGchsq_therm;
	std::vector<double> mH1_therm;
	std::vector<double> mH2_therm;
	std::vector<double> mH3_therm;
	std::vector<double> mHc_therm;
	std::vector<double> v_therm;

	// handstuff

	double mHsm0 = 125.09;
	double MW0;
	double MZ0 = 91.1876;
	double v0;
	bool do_goldstone_channels = false;
	double Tcrit;

	// Custom R's
	std::vector<double> R00_therm;
	std::vector<double> R01_therm;
	std::vector<double> R02_therm;
	std::vector<double> R10_therm;
	std::vector<double> R11_therm;
	std::vector<double> R12_therm;
	std::vector<double> R20_therm;
	std::vector<double> R21_therm;
	std::vector<double> R22_therm;



	// custom Thermal masses / Thermal self-energies
	double THMZ;
	double THMW;
	double THmHsm;
	double THmG0;
	double THmGch;
	double THmH1;
	double THmH2;
	double THmH3;
	double THmHc;

	// negative mass -> sign of Higgs and goldstones
	double sign_mHsmsq;
	double sign_mG0sq;
	double sign_mGchsq;

	std::vector<double> THMZ_therm;
	std::vector<double> THMW_therm;
	std::vector<double> THmHsm_therm;
	std::vector<double> THmG0_therm;
	std::vector<double> THmGch_therm;
	std::vector<double> THmH1_therm;
	std::vector<double> THmH2_therm;
	std::vector<double> THmH3_therm;
	std::vector<double> THmHc_therm;


	std::vector<double> mG0sq_pot_therm;
	std::vector<double> mGchsq_pot_therm;
	std::vector<double> mHm_pot_therm;
	std::vector<double> mHsmsq_pot_therm;
	std::vector<double> mH1_pot_therm;
	std::vector<double> mH2_pot_therm;
	std::vector<double> mH3_pot_therm;
	std::vector<double> mHc_pot_therm;



	// tokens
	double token1;
	double token2;
	double token3;
	double token4;
	double token5;
	double token6;
	double token7;
	double token8;
	double token9;
	double token10;
	double token11;
	double token12;
	double token13;
	double token14;
	double token15;
	double token16;
	double token17;
	double token18;
	double token19;
	double token20;
	double token21;
	double token22;
	double token23;
	double token24;
	double token25;
	double token26;
	double token27;
	double token28;
	double token29;
	double token30;
	double token31;
	double token32;
	double token33;
	double token34;
	double token35;
	double token36;
	double token37;
	double token38;
	double token39;
	double token40;
	double token41;
	double token42;
	double token43;
	double token44;
	double token45;
	double token46;
	double token47;
	double token48;
	double token49;
	double token50;
	double token51;
	double token52;
	double token53;
	double token54;
	double token55;
	double token56;
	double token57;
	double token58;
	double token59;
	double token60;
	double token61;
	double token62;
	double token63;
	double token64;
	double token65;
	double token66;
	double token67;
	double token68;
	double token69;
	double token70;
	double token71;
	double token72;
	double token73;
	double token74;
	double token75;
	double token76;
	double token77;
	double token78;
	double token79;
	double token80;
	double token81;
	double token82;
	double token83;
	double token84;
	double token85;
	double token86;
	double token87;
	double token88;
	double token89;
	double token90;
	double token91;
	double token92;
	double token93;
	double token94;
	double token95;
	double token96;
	double token97;
	double token98;
	double token99;
	double token100;
	double token101;
	double token102;
	double token103;
	double token104;
	double token105;
	double token106;
	double token107;
	double token108;
	double token109;
	double token110;
	double token111;
	double token112;
	double token113;
	double token114;
	double token115;
	double token116;
	double token117;
	double token118;
	double token119;
	double token120;
	double token121;
	double token122;
	double token123;
	double token124;
	double token125;
	double token126;
	double token127;
	double token128;
	double token129;
}
}
