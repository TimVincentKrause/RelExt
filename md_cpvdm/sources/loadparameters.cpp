///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "general_model.hpp"
#include "../model.hpp"
#include <vector>
#include <string>
namespace DT{
	void ModelInfo::load_parameters(const double x){
		using namespace PAR;
		double xinv = 1/x;

		if (therm_contr == false){xinv = 0; do_goldstone_channels = false;}
		else {
    		if ( (MDM * xinv - Tcrit > 1e-3))
    		    do_goldstone_channels = true;
    		else
    		    do_goldstone_channels = false;
		}
		// std::cout << "dg? = " << do_goldstone_channels << std::endl;
		// std::cout << "v = " << v << std::endl;
		// std::cout << "MDM = " << MDM << std::endl;

		if (v_therm.size() == 0){
			std::cerr << "Error empty vev string!\n";
			std::abort();
		} else {

			// Create Mass Matrix to calculate R
			//MatDoub mass_matrix(3, 3);


			// the first case should be the T=0, v~246 case.
			if (temp_therm[1] >= MDM * xinv || MDM == 0){
				//std::cout << "x >= MDM / T\n";
				v = v_therm[0];
				Mnue = Mnue_therm[0];
				Mnum = Mnum_therm[0];
				Mnut = Mnut_therm[0];
				Me = Me_therm[0];
				MM = MM_therm[0];
				MTA = MTA_therm[0];
				MU = MU_therm[0];
				MC = MC_therm[0];
				MT = MT_therm[0];
				MD = MD_therm[0];
				MS = MS_therm[0];
				MB = MB_therm[0];
				MZ = MZ_therm[0];
				MW = MW_therm[0];
				mH1 = mH1_pot_therm[0];
				mH2 = mH2_pot_therm[0];
				mH3 = mH3_pot_therm[0];
				mHc = mHc_pot_therm[0];
				mHm = mHm_pot_therm[0];

				// can get negative
				mHsm = pow(std::abs(mHsmsq_pot_therm[0]),0.5);
				//mG0 = pow(std::abs(mG0sq_therm[0] + g2*g2 * v*v /4),0.5);
				//mGch = pow(std::abs(mGchsq_therm[0] + g2*g2 * v*v /4),0.5);
				mG0 = pow(std::abs(mG0sq_pot_therm[0]),0.5); //+MZ*MZ
				mGch = pow(std::abs(mGchsq_pot_therm[0]),0.5); //+MW*MW


				if (scal_therm_prop == true)
				{
    				// THmHsm = THmHsm_therm[0];
    				// THmG0 =  THmG0sq_therm[0];
    				// THmGch = THmGchsq_therm[0];
    				// THmH1 =  THmH1_therm[0];
    				// THmH2 =  THmH2_therm[0];
    				// THmH3 =  THmH3_therm[0];
    				// THmHc =  THmHc_therm[0];
        		    THMZ =   THMZ_therm[0];
                    THMW =   THMW_therm[0];
				}
				else
				{
				    // THmHsm = mHsm;
    				// THmG0 =  mG0;
    				// THmGch = mGch;
    				// THmH1 =  mH1;
    				// THmH2 =  mH2;
    				// THmH3 =  mH3;
    				// THmHc =  mHc;
         			THMZ =   MZ;//THMZ_therm[0];
                    THMW =   MW;//THMW_therm[0];
				}

				// Rotation Matrix
				RR1x1 = R00_therm[0];
				RR1x2 = R01_therm[0];
				RR1x3 = R02_therm[0];
				RR2x1 = R10_therm[0];
				RR2x2 = R11_therm[0];
				RR2x3 = R12_therm[0];
				RR3x1 = R20_therm[0];
				RR3x2 = R21_therm[0];
				RR3x3 = R22_therm[0];


			} else if (temp_therm[temp_therm.size()-2] <= MDM * xinv ){
				//std::cout  << "x <= MDM / T\n";
				v = v_therm[v_therm.size()-1];
				Mnue = Mnue_therm[v_therm.size()-1];
				Mnum = Mnum_therm[v_therm.size()-1];
				Mnut = Mnut_therm[v_therm.size()-1];
				Me = Me_therm[v_therm.size()-1];
				MM = MM_therm[v_therm.size()-1];
				MTA = MTA_therm[v_therm.size()-1];
				MU = MU_therm[v_therm.size()-1];
				MC = MC_therm[v_therm.size()-1];
				MT = MT_therm[v_therm.size()-1];
				MD = MD_therm[v_therm.size()-1];
				MS = MS_therm[v_therm.size()-1];
				MB = MB_therm[v_therm.size()-1];
				MZ = MZ_therm[v_therm.size()-1];
				MW = MW_therm[v_therm.size()-1];
				mH1 = mH1_pot_therm[v_therm.size()-1];
				mH2 = mH2_pot_therm[v_therm.size()-1];
				mH3 = mH3_pot_therm[v_therm.size()-1];
				mHc = mHc_pot_therm[v_therm.size()-1];
				mHm = mHm_pot_therm[v_therm.size()-1];

				// can get negative
				mHsm = pow(std::abs(mHsmsq_pot_therm[v_therm.size()-1]),0.5);
				// mG0 = pow(std::abs(mG0sq_therm[v_therm.size()-1] + g2*g2 * v*v /4),0.5);
				// mGch = pow(std::abs(mGchsq_therm[v_therm.size()-1] + g2*g2 * v*v /4),0.5);
				mG0 = pow(std::abs(mG0sq_pot_therm[v_therm.size()-1]),0.5); // + MZ*MZ
				mGch = pow(std::abs(mGchsq_pot_therm[v_therm.size()-1]),0.5); //+ MW*MW
				// if (mHsmsq_pot_therm[v_therm.size()-1] < 0){
				// 	sign_mHsmsq = -1.;
				// } else {sign_mHsmsq = 1.;}
				// if (mG0sq_pot_therm[v_therm.size()-1] < 0){
				// 	sign_mG0sq = -1.;
				// } else {sign_mG0sq = 1.;}
				// if (mGchsq_pot_therm[v_therm.size()-1] < 0){
				// 	sign_mGchsq = -1.;
				// } else {sign_mGchsq = 1.;}


				if (scal_therm_prop == true)
				{
    				// THmHsm = THmHsm_therm[v_therm.size()-1];
    				// THmG0 =  THmG0sq_therm[v_therm.size()-1];
    				// THmGch = THmGchsq_therm[v_therm.size()-1];
    				// THmH1 =  THmH1_therm[v_therm.size()-1];
    				// THmH2 =  THmH2_therm[v_therm.size()-1];
    				// THmH3 =  THmH3_therm[v_therm.size()-1];
    				// THmHc =  THmHc_therm[v_therm.size()-1];
                    THMZ =   THMZ_therm[v_therm.size()-1];
                    THMW =   THMW_therm[v_therm.size()-1];
				}
				else
				{
				    // THmHsm = mHsm;
    				// THmG0 =  mG0;
    				// THmGch = mGch;
    				// THmH1 =  mH1;
    				// THmH2 =  mH2;
    				// THmH3 =  mH3;
    				// THmHc =  mHc;
    				THMZ =   MZ;//THMZ_therm[v_therm.size()-1];
                    THMW =   MW;//THMW_therm[v_therm.size()-1];
				}


				// Rotation Matrix
				RR1x1 = R00_therm[v_therm.size()-1];
				RR1x2 = R01_therm[v_therm.size()-1];
				RR1x3 = R02_therm[v_therm.size()-1];
				RR2x1 = R10_therm[v_therm.size()-1];
				RR2x2 = R11_therm[v_therm.size()-1];
				RR2x3 = R12_therm[v_therm.size()-1];
				RR3x1 = R20_therm[v_therm.size()-1];
				RR3x2 = R21_therm[v_therm.size()-1];
				RR3x3 = R22_therm[v_therm.size()-1];



			} else {
				//std::cout << "x_in = "<< x << "\n";
				for (size_t i = temp_therm.size()-1; i >=0; i--){
				//for (size_t i = 0; i < temp_therm.size()-1; i++){
					//std::cout << "MDM/T = "<< MDM / temp_therm[i] << "\n";
					//std::cout << "asldk" << std::endl;
					if (MDM / temp_therm[i] >= x){
					    if (true)
						{
						    //i +=1;
							v =  v_therm[i];
							Mnue = Mnue_therm[i];
							Mnum = Mnum_therm[i];
							Mnut = Mnut_therm[i];
							Me = Me_therm[i];
							MM = MM_therm[i];
							MTA = MTA_therm[i];
							MU = MU_therm[i];
							MC = MC_therm[i];
							MT = MT_therm[i];
							MD = MD_therm[i];
							MS = MS_therm[i];
							MB = MB_therm[i];
							MZ = MZ_therm[i];
							MW = MW_therm[i];
							mH1 = mH1_pot_therm[i];
							mH2 = mH2_pot_therm[i];
							mH3 = mH3_pot_therm[i];
							mHc = mHc_pot_therm[i];
							mHm = mHm_pot_therm[i];
							mHsm = pow(std::abs(mHsmsq_pot_therm[i]),0.5);
							mG0 = pow(std::abs(mG0sq_pot_therm[i]),0.5);
							mGch = pow(std::abs(mGchsq_pot_therm[i]),0.5);

							if (scal_therm_prop == true)
							{
                                THMZ = THMZ_therm[i];
                                THMW = THMW_therm[i];
							}
							else
							{THMZ =   MZ; THMW =   MW;}


							RR1x1 = R00_therm[i];
							RR1x2 = R01_therm[i];
							RR1x3 = R02_therm[i];
							RR2x1 = R10_therm[i];
							RR2x2 = R11_therm[i];
							RR2x3 = R12_therm[i];
							RR3x1 = R20_therm[i];
							RR3x2 = R21_therm[i];
							RR3x3 = R22_therm[i];

							break;

						}

						else
						{
    						v =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], v_therm[i-1] , v_therm[i]);
    						Mnue = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], Mnue_therm[i-1],Mnue_therm[i]);
    						Mnum = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], Mnum_therm[i-1],Mnum_therm[i]);
    						Mnut = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], Mnut_therm[i-1],Mnut_therm[i]);
    						Me = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], Me_therm[i-1],Me_therm[i]);
    						MM = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MM_therm[i-1],MM_therm[i]);
    						MTA = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MTA_therm[i-1],MTA_therm[i]);
    						MU = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MU_therm[i-1],MU_therm[i]);
    						MC = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MC_therm[i-1],MC_therm[i]);
    						MT = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MT_therm[i-1],MT_therm[i]);
    						MD = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MD_therm[i-1],MD_therm[i]);
    						MS = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MS_therm[i-1],MS_therm[i]);
    						MB = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MB_therm[i-1],MB_therm[i]);
    						MZ = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MZ_therm[i-1],MZ_therm[i]);
    						MW = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], MW_therm[i-1],MW_therm[i]);
    						mH1 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH1_pot_therm[i-1],mH1_pot_therm[i]);
    						mH2 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH2_pot_therm[i-1],mH2_pot_therm[i]);
    						mH3 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH3_pot_therm[i-1],mH3_pot_therm[i]);
    						mHc = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mHc_pot_therm[i-1],mHc_pot_therm[i]);
    						mHm = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mHm_pot_therm[i-1],mHm_pot_therm[i]);
    						double mHsmsq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mHsmsq_pot_therm[i-1],mHsmsq_pot_therm[i]);
    						double mG0sq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mG0sq_pot_therm[i-1],mG0sq_pot_therm[i]);
    						double mGchsq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mGchsq_pot_therm[i-1],mGchsq_pot_therm[i]);
    						mHsm = pow(std::abs(mHsmsq),0.5);
    						mG0 = pow(std::abs(mG0sq),0.5);
    						mGch = pow(std::abs(mGchsq),0.5);

    						if (scal_therm_prop == true)
    						{
                                THMZ =   linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THMZ_therm[i-1], THMZ_therm[i]);
                                THMW =   linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THMW_therm[i-1], THMW_therm[i]);
    						}
    						else
    						{THMZ =   MZ; THMW =   MW;}


    						RR1x1 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R00_therm[i-1],R00_therm[i]);
    						RR1x2 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R01_therm[i-1],R01_therm[i]);
    						RR1x3 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R02_therm[i-1],R02_therm[i]);
    						RR2x1 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R10_therm[i-1],R10_therm[i]);
    						RR2x2 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R11_therm[i-1],R11_therm[i]);
    						RR2x3 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R12_therm[i-1],R12_therm[i]);
    						RR3x1 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R20_therm[i-1],R20_therm[i]);
    						RR3x2 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R21_therm[i-1],R21_therm[i]);
    						RR3x3 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], R22_therm[i-1],R22_therm[i]);

    						break;
						}
					}
				}
			}

			sign_mGchsq = 1.; sign_mHsmsq = 1.; sign_mG0sq = 1.;
            THmHsm = mHsm;
			THmG0 =  mG0;
			THmGch = mGch;
			THmH1 =  mH1;
			THmH2 =  mH2;
			THmH3 =  mH3;
			THmHc =  mHc;


			// if (std::abs(MC) <1e-5) {MC = 0;}
			// if (std::abs(MZ) <1e-5) {MZ = 0;}
			// because of differnet Gauge
			//THmG0 =  std::sqrt(THmG0 + MZ*MZ);
			//THmGch = std::sqrt(THmGch + MW*MW);

			//to get the same Matrix as Scanner S we do some reordering
			// if R11 <0: multyply row 1 with (-1)  (field redefinition h1 -> -h1)
			// if R33 <0: multiply row 3 with (-1)  (field redefinition h3 -> -h3)
			// if Det(R) =-1: multiply row 2 with (-1)  (field redefinition h2 -> -h2)
			if (RR1x1 < 0){
				RR1x1 = -RR1x1; RR1x2 = -RR1x2; RR1x3 = -RR1x3;
			}
			if (RR3x3 < 0){
				RR3x1 = -RR3x1; RR3x2 = -RR3x2; RR3x3 = -RR3x3;
			}
			double DetR = -(RR1x3*RR2x2*RR3x1) + RR1x2*RR2x3*RR3x1 + RR1x3*RR2x1*RR3x2 - RR1x1*RR2x3*RR3x2 - RR1x2*RR2x1*RR3x3 + RR1x1*RR2x2*RR3x3;
			// relativistically -1, but assuming some numerical error and that it is only 1 or -1
			if (DetR <0){
				RR2x1 = -RR2x1; RR2x2 = -RR2x2; RR2x3 = -RR2x3;
			}


			if (std::abs(RR1x1) < 1e-10) { RR1x1 = 0;}
			if (std::abs(RR1x2) < 1e-10) { RR1x2 = 0;}
			if (std::abs(RR1x3) < 1e-10) { RR1x3 = 0;}

			if (std::abs(RR2x1) < 1e-10) { RR2x1 = 0;}
			if (std::abs(RR2x2) < 1e-10) { RR2x2 = 0;}
			if (std::abs(RR2x3) < 1e-10) { RR2x3 = 0;}

			if (std::abs(RR3x1) < 1e-10) { RR3x1 = 0;}
			if (std::abs(RR3x2) < 1e-10) { RR3x2 = 0;}
			if (std::abs(RR3x3) < 1e-10) { RR3x3 = 0;}

			// Parametrisation of the rotation matrix in terms of angles
			double c2 = std::sqrt(1-RR1x3*RR1x3);

			if (c2 == 0){
				alph2 = -Pi/2; // theoretically the parametrization should be worng, but otherwise we rephase our particles unnecessary
				alph1 = Pi/2;
				alph3 = 0;
			} else{
				alph1 = std::asin(RR1x2/c2);
				alph2 = std::asin(RR1x3);
				alph3 = std::asin(RR2x3/c2);
			}

			// mass_matrix.print();
			// std::cout << "T = " << MDM * xinv << " | a1 =" << alph1 << " | a2 =" << alph2 << " | a3 =" << alph3 <<  "\n";
			// std::cout << std::setw(9) << RR1x1 << ",\t" << RR1x2 << ",\t" << RR1x3 <<",\n";
			// std::cout << std::setw(9) << RR2x1 << ",\t" << RR2x2 << ",\t" << RR2x3 <<",\n";
			// std::cout << std::setw(9) << RR3x1 << ",\t" << RR3x2 << ",\t" << RR3x3 <<",\n";


			// I have to autamize this!!
			FAGS = sqrt(4*M_PI*aS); gs = FAGS; G = FAGS;
			MW0 = pow(pow(MZ0,2)/2.+pow(-(aEWM1*Pi*pow(2,-0.5)*pow(Gf,-1)*pow(MZ0,2))+pow(MZ0,4)/4.,0.5),0.5);
			EE = 2*pow(aEWM1,0.5)*pow(Pi,0.5);
			CW2 = pow(MW0,2)*pow(MZ0,-2);
			SW2 = 1-CW2;
			CW = pow(CW2,0.5);
			SW = pow(SW2,0.5);
			g1 = EE*pow(CW,-1);
			g2 = EE*pow(SW,-1);
			v0 = 0.8408964152537146*pow(Gf,-0.5);

			m11sq = -0.5*pow(mHsm0,2);
			CKM1x1 = 0.97428;
			CKM1x2 = 0.2253;
			CKM1x3 = 0.00347;
			CKM2x1 = 0.2252;
			CKM2x2 = 0.97345;
			CKM2x3 = 0.041;
			CKM3x1 = 0.00862;
			CKM3x2 = 0.0403;
			CKM3x3 = 0.999152;

			// lets try and use the yukawas of RelExt
			// yu1 = 0;
			// yu2 = 0.00689242;
			// yu3 = 0.990786;
			// yd1 = 0;
			// yd2 = 0;
			// yd3 = 0.0242958;
			// yl1 = 0;
			// yl2 = 0.000607108;
			// yl3 = 0.0102065;

			// // //the yukawas of BSMPT
			yu1 = MU_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yu2 = MC_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yu3 = MT_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yd1 = MD_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yd2 = MS_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yd3 = MB_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yl1 = Me_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yl2 = MM_therm[0] * pow(2,0.5)*pow(v_therm[0],-1);
			yl3 = MTA_therm[0]* pow(2,0.5)*pow(v_therm[0],-1);

			// std::cout << "yu1 = " << yu1 << "\n";
			// std::cout << "yu2 = " << yu2 << "\n";
			// std::cout << "yu3 = " << yu3 << "\n";
			// std::cout << "yd1 = " << yd1 << "\n";
			// std::cout << "yd2 = " << yd2 << "\n";
			// std::cout << "yd3 = " << yd3 << "\n";
			// std::cout << "yl1 = " << yl1 << "\n";
			// std::cout << "yl2 = " << yl2 << "\n";
			// std::cout << "yl3 = " << yl3 << "\n";
			I1a1 = 1;
			I1a2 = 1;
			I1a3 = 1;
			I2a1 = CKM1x1*yd1+CKM2x1*yd2+CKM3x1*yd3;
			I2a2 = CKM1x2*yd1+CKM2x2*yd2+CKM3x2*yd3;
			I2a3 = CKM1x3*yd1+CKM2x3*yd2+CKM3x3*yd3;
			I3a1 = 1;
			I3a2 = 1;
			I3a3 = 1;
			I4a1 = 1;
			I4a2 = 1;
			I4a3 = 1;
			I5a1 = CKM1x1*yu1+CKM1x2*yu2+CKM1x3*yu3;
			I5a2 = CKM2x1*yu1+CKM2x2*yu2+CKM2x3*yu3;
			I5a3 = CKM3x1*yu1+CKM3x2*yu2+CKM3x3*yu3;
			I6a1 = CKM1x1*yu1+CKM1x2*yu2+CKM1x3*yu3;
			I6a2 = CKM2x1*yu1+CKM2x2*yu2+CKM2x3*yu3;
			I6a3 = CKM3x1*yu1+CKM3x2*yu2+CKM3x3*yu3;
			I7a1 = CKM1x1*yd1+CKM2x1*yd2+CKM3x1*yd3;
			I7a2 = CKM1x2*yd1+CKM2x2*yd2+CKM3x2*yd3;
			I7a3 = CKM1x3*yd1+CKM2x3*yd2+CKM3x3*yd3;
			EL = EE;
			ME = Me;


			// if (therm_contr == false){
			// 	MC = 1.2;
			// 	MB = 4.23;
			// 	MT = 172.5;
			// 	Mnue = 0.;
			// 	Mnum = 0.;
			// 	Mnut = 0.;
			// 	Me = 0.;
			// 	MM = 0.1057;
			// 	MTA = 1.777;
			// 	MU = 0.;
			// 	MD = 0.;
			// 	MS = 0.;
			// }

			std::cout << "x= " << x << " | v= " << v << " | g?= " << do_goldstone_channels << " | MDM*xinv = " << (MDM * xinv) << " | Tcrit = " << Tcrit << " | M-T = " << (MDM * xinv - Tcrit) << std::endl; //4.74586805555556
			load_tokens();
		}


			// Include also the Mass Matrix rotation and the Diagonalisation Matrix R calculation from BSMPT


	//	}
	}


	void ModelInfo::read_thermal_parameters(std::string tvev_input_file){
		using namespace PAR;
		std::unique_ptr<DataReader> rdr_therm = std::make_unique<DataReader>(tvev_input_file, 1);

		rdr_therm->read_column(temp_therm, "Temp");
		rdr_therm->read_column(v_therm, "omega_1",0,1e-3);

		rdr_therm->read_column(Mnue_therm, "mL_0sq",0.5,1e-3);
		rdr_therm->read_column(Mnum_therm, "mL_1sq",0.5,1e-3);
		rdr_therm->read_column(Mnut_therm, "mL_2sq",0.5,1e-3);
		rdr_therm->read_column(Me_therm, "mL_3sq",0.5,1e-3);
		rdr_therm->read_column(MM_therm, "mL_5sq",0.5,1e-3);
		rdr_therm->read_column(MTA_therm, "mL_7sq",0.5,1e-3);

		rdr_therm->read_column(MU_therm, "mQ_0sq",0.5,1e-3);
		rdr_therm->read_column(MD_therm, "mQ_2sq",0.5,1e-3);
		rdr_therm->read_column(MS_therm, "mQ_4sq",0.5,1e-3);
		rdr_therm->read_column(MC_therm, "mQ_6sq",0.5,1e-3);
		rdr_therm->read_column(MB_therm, "mQ_8sq",0.5,1e-3);
		rdr_therm->read_column(MT_therm, "mQ_10sq",0.5,1e-3);

		rdr_therm->read_column(MW_therm, "mG_1sq",0.5,1e-3);
		rdr_therm->read_column(THMW_therm, "mG_1sq_T",0.5,1e-3);
		rdr_therm->read_column(MZ_therm, "mG_3sq",0.5,1e-3);
		rdr_therm->read_column(THMZ_therm, "mG_3sq_T",0.5,1e-3);

		// next part assumes that dark matter particles don't change their place
		// (But this is for tree level masses and these are unused.( currently))
		//Goldstone-masses can be negative -> add eps
		rdr_therm->read_column(mGchsq_therm, "mS_0sq", 0,20);
		rdr_therm->read_column(mG0sq_therm, "mS_2sq",0,20);
		rdr_therm->read_column(mHsmsq_therm, "mS_3sq",0.5,0.5);

		rdr_therm->read_column(mH1_therm, "mS_4sq",0.5,0.5);

		size_t posmHc = rdr_therm->get_mHc_pos();

		if (posmHc == 1){
			rdr_therm->read_column(mHc_therm, "mS_5sq",0.5);
			rdr_therm->read_column(mH2_therm, "mS_7sq",0.5);
			rdr_therm->read_column(mH3_therm, "mS_8sq",0.5);
		} else if (posmHc == 2){
			rdr_therm->read_column(mH2_therm, "mS_5sq",0.5);
			rdr_therm->read_column(mHc_therm, "mS_6sq",0.5);
			rdr_therm->read_column(mH3_therm, "mS_8sq",0.5);
		} else if (posmHc == 3){
			rdr_therm->read_column(mH2_therm, "mS_5sq",0.5);
			rdr_therm->read_column(mH3_therm, "mS_6sq",0.5);
			rdr_therm->read_column(mHc_therm, "mS_8sq",0.5);
		}

		// Thermal Masses
		rdr_therm->read_column(THmGchsq_therm, "m_thm_Gpsq",0,20);
		rdr_therm->read_column(THmG0sq_therm, "m_thm_G0sq",0,20);
		rdr_therm->read_column(THmHsm_therm, "m_thm_Hsmsq",0.5,0.5);
		rdr_therm->read_column(THmH1_therm, "m_thm_H1sq",0.5,0.5);
		rdr_therm->read_column(THmH2_therm, "m_thm_H2sq",0.5,0.5);
		rdr_therm->read_column(THmH3_therm, "m_thm_H3sq",0.5,0.5);
		rdr_therm->read_column(THmHc_therm, "m_thm_Hpsq",0.5,0.5);
		//rdr_therm->read_column(THmHm_therm, "m_thm_Hmsq",0.5,2);

		std::cout << "daisy" << take_daisy_phys << std::endl;
		if (take_daisy_phys)
		{
		    // daisy Rotation angle
    		rdr_therm->read_column(R00_therm, "R_thm_00",0,1e-10);
    		rdr_therm->read_column(R01_therm, "R_thm_01",0,1e-10);
    		rdr_therm->read_column(R02_therm, "R_thm_02",0,1e-10);

    		rdr_therm->read_column(R10_therm, "R_thm_10",0,1e-10);
    		rdr_therm->read_column(R11_therm, "R_thm_11",0,1e-10);
    		rdr_therm->read_column(R12_therm, "R_thm_12",0,1e-10);

    		rdr_therm->read_column(R20_therm, "R_thm_20",0,1e-10);
    		rdr_therm->read_column(R21_therm, "R_thm_21",0,1e-10);
    		rdr_therm->read_column(R22_therm, "R_thm_22",0,1e-10);
    		// daisy Masses as physical masses
    		// rdr_therm->read_column(mGchsq_pot_therm, "m_thm_Gmsq",0,20);
    		// rdr_therm->read_column(mG0sq_pot_therm, "m_thm_G0sq",0,20);
    		// rdr_therm->read_column(mHsmsq_pot_therm, "m_thm_Hsmsq",0,0.5);
    		rdr_therm->read_column(mGchsq_pot_therm, "m_pot_Gmsq",0,20);
    		rdr_therm->read_column(mG0sq_pot_therm, "m_pot_G0sq",0,20);
    		rdr_therm->read_column(mHsmsq_pot_therm, "m_pot_Hsmsq",0,0.5);
    		rdr_therm->read_column(mH1_pot_therm, "m_thm_H1sq",0.5,2);
    		rdr_therm->read_column(mH2_pot_therm, "m_thm_H2sq",0.5,2);
    		rdr_therm->read_column(mH3_pot_therm, "m_thm_H3sq",0.5,2);
    		rdr_therm->read_column(mHc_pot_therm, "m_thm_Hpsq",0.5,2);
    		rdr_therm->read_column(mHm_pot_therm, "m_thm_Hmsq",0.5,2);
		}
		else
		{
    		// potential Rotation angle
    		rdr_therm->read_column(R00_therm, "R_pot_00",0,1e-10);
    		rdr_therm->read_column(R01_therm, "R_pot_01",0,1e-10);
    		rdr_therm->read_column(R02_therm, "R_pot_02",0,1e-10);

    		rdr_therm->read_column(R10_therm, "R_pot_10",0,1e-10);
    		rdr_therm->read_column(R11_therm, "R_pot_11",0,1e-10);
    		rdr_therm->read_column(R12_therm, "R_pot_12",0,1e-10);

    		rdr_therm->read_column(R20_therm, "R_pot_20",0,1e-10);
    		rdr_therm->read_column(R21_therm, "R_pot_21",0,1e-10);
    		rdr_therm->read_column(R22_therm, "R_pot_22",0,1e-10);
    		// Potential Masses
    		rdr_therm->read_column(mGchsq_pot_therm, "m_pot_Gmsq",0,20);
    		rdr_therm->read_column(mG0sq_pot_therm, "m_pot_G0sq",0,20);
    		rdr_therm->read_column(mHsmsq_pot_therm, "m_pot_Hsmsq",0,0.5);
    		rdr_therm->read_column(mH1_pot_therm, "m_pot_H1sq",0.5,2);
    		rdr_therm->read_column(mH2_pot_therm, "m_pot_H2sq",0.5,2);
    		rdr_therm->read_column(mH3_pot_therm, "m_pot_H3sq",0.5,2);
    		rdr_therm->read_column(mHc_pot_therm, "m_pot_Hpsq",0.5,2);
    		rdr_therm->read_column(mHm_pot_therm, "m_pot_Hmsq",0.5,2);
		}

		// size_t idx = M00_therm.size()-1;
		// std::cout << std::setw(9) << M00_therm[idx] << ",\t" << M01_therm[idx] << ",\t" << M02_therm[idx] <<",\n";
		// std::cout << std::setw(9) << M10_therm[idx] << ",\t" << M11_therm[idx] << ",\t" << M12_therm[idx] <<",\n";
		// std::cout << std::setw(9) << M20_therm[idx] << ",\t" << M21_therm[idx] << ",\t" << M22_therm[idx] <<",\n";

		// to get parameters at T=0 for a start
		load_parameters(1e8);
	}

	void ModelInfo::save_parameters(){
		using namespace PAR;

		// load_parameters(1e10);
		// std::cout << "a1 = " << alph1 << "\n";
		// std::cout << "a2 = " << alph2 << "\n";
		// std::cout << "a3 = " << alph3 << "\n";

		// std::cout << std::setw(9) << RR1x1 << ",\t" << RR1x2 << ",\t" << RR1x3 <<",\n";
		// std::cout << std::setw(9) << RR2x1 << ",\t" << RR2x2 << ",\t" << RR2x3 <<",\n";
		// std::cout << std::setw(9) << RR3x1 << ",\t" << RR3x2 << ",\t" << RR3x3 <<",\n";


		std::ofstream output_file;
		std::cout << "saving parameters\n";
		output_file.open("../dataOutput/savepars.tsv");

		// get all parameters from the parametermap
		//for (auto &it : parmap){std::cout << it.first << " = " << *it.second << "\n";};

		std::vector<std::string> header = {"m11sq","Mnue", "Mnum", "Mnut", "Me","MM", "MTA","MU","MC","MT","MD","MS","MB","MZ","THMZ","MW","THMW","mHsm","sign_mHsmsq","THmHsm","mG0","sign_mG0sq","THmG0","mGch","sign_mGchsq","THmGch","mH1","THmH1","mH2","THmH2","mH3","THmH3","mHc","THmHc","mHm","RR1x1", "RR1x2","RR1x3","RR2x1","RR2x2","RR2x3","RR3x1","RR3x2","RR3x3","alph1","alph2","alph3","yu1","yu2","yu3","yd1","yd2","yd3","yl1","yl2","yl3","MDM"};

		std::vector<std::string> header_T = {"Temp","x_i","v"};


		// T x and v
		for (size_t j=0; j< header_T.size();j++) {output_file << header_T[j] << "\t";}
		// parmap
		for (auto &it : parmap) {output_file << it.first << "\t";}
		// loadpar-values
		for (size_t j=0; j< header.size();j++) {output_file << header[j] << "\t";}



		size_t kj = 0;
		for (auto it : bath_masses) {
		output_file << "DSm" << kj << "\t";
		kj +=1;
        }
        kj = 0;
        for (auto it : bath_masses) {
		output_file << "DSdof" << kj << "\t";
		kj +=1;
        }

		output_file << "\n";

		for (double T_i = 0; T_i<500; T_i+=0.2){
			double x_i = MDM / T_i;
			load_parameters(x_i);

			// define; would be nicer with pointers
			std::vector<double> values_T = {T_i,x_i,v};
			std::vector<double> values = {m11sq,Mnue, Mnum, Mnut, Me,MM, MTA,MU,MC,MT,MD,MS,MB,MZ,THMZ,MW,THMW,mHsm,sign_mHsmsq,THmHsm,mG0,sign_mG0sq,THmG0,mGch,sign_mGchsq,THmGch,mH1,THmH1,mH2,THmH2,mH3,THmH3,mHc,THmHc,mHm,RR1x1, RR1x2,RR1x3,RR2x1,RR2x2,RR2x3,RR3x1,RR3x2,RR3x3,alph1,alph2,alph3,yu1,yu2,yu3,yd1,yd2,yd3,yl1,yl2,yl3,MDM};

			// output every row
			output_file << std::setprecision(16);
			for (size_t j=0; j< values_T.size();j++){output_file << values_T[j] << "\t";}
			for (auto &it : parmap) {output_file << *it.second << "\t";}
			for (size_t j=0; j< values.size();j++){output_file << values[j] << "\t";}
			for (auto it : bath_masses) {
			output_file << *DSmasses[it] << "\t";
            }
            for (auto it : bath_masses) {
			output_file << DSdof[it] << "\t";
                     }
			output_file << "\n";
		}
		output_file.close();

	}


}	//namespace DT

// programm a read parameter stuff i nvoid read_thermal_parameters();
