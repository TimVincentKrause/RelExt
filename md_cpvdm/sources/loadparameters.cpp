///////////////////CODE GENERATED VIA MATHEMATICA///////////////////


#include "general_model.hpp"
#include "../model.hpp"
#include <vector>
#include <string>
namespace DT{
	void ModelInfo::load_parameters(const double x){
		using namespace PAR;
		double xinv = 1/x;
		if (therm_contr == false){xinv = 0;}

		if (v_therm.size() == 0){
			std::cerr << "Error empty vev string!\n";
			std::abort();
		} else {

			// Create Mass Matrix to calculate R
			MatDoub mass_matrix(3, 3);


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
				mH1 = mH1_therm[0];
				mH2 = mH2_therm[0];
				mH3 = mH3_therm[0];
				mHc = mHc_therm[0];

				THMZ =   THMZ_therm[0];
				THMW =   THMW_therm[0];
				THmHsm = THmHsm_therm[0];
				THmG0 =  THmG0_therm[0];
				THmGch = THmGch_therm[0];
				THmH1 =  THmH1_therm[0];
				THmH2 =  THmH2_therm[0];
				THmH3 =  THmH3_therm[0];
				THmHc =  THmHc_therm[0];


				// can get negative
				mHsm = pow(std::abs(mHsmsq_therm[0]),0.5);
				mG0 = pow(std::abs(mG0sq_therm[0] + g2*g2 * v*v /4),0.5);
				mGch = pow(std::abs(mGchsq_therm[0] + g2*g2 * v*v /4),0.5);
				if (mHsmsq_therm[0] < 0){
					sign_mHsmsq = 0;//-1.;
				} else {sign_mHsmsq = 1.;}
				if (mG0sq_therm[0] < 0){
					sign_mG0sq = 0;//-1.;
				} else {sign_mG0sq = 1.;}
				if (mGchsq_therm[0] < 0){
					sign_mGchsq = 0;//-1.;
				} else {sign_mGchsq = 1.;}


				// Mass Matrix
				mass_matrix[0][0] = M00_therm[0];
				mass_matrix[0][1] = M01_therm[0];
				mass_matrix[0][2] = M02_therm[0];

				mass_matrix[1][0] = M10_therm[0];
				mass_matrix[1][1] = M11_therm[0];
				mass_matrix[1][2] = M12_therm[0];

				mass_matrix[2][0] = M20_therm[0];
				mass_matrix[2][1] = M21_therm[0];
				mass_matrix[2][2] = M22_therm[0];


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
				mH1 = mH1_therm[v_therm.size()-1];
				mH2 = mH2_therm[v_therm.size()-1];
				mH3 = mH3_therm[v_therm.size()-1];
				mHc = mHc_therm[v_therm.size()-1];

				THMZ =   THMZ_therm[v_therm.size()-1];
				THMW =   THMW_therm[v_therm.size()-1];
				THmHsm = THmHsm_therm[v_therm.size()-1];
				THmG0 =  THmG0_therm[v_therm.size()-1];
				THmGch = THmGch_therm[v_therm.size()-1];
				THmH1 =  THmH1_therm[v_therm.size()-1];
				THmH2 =  THmH2_therm[v_therm.size()-1];
				THmH3 =  THmH3_therm[v_therm.size()-1];
				THmHc =  THmHc_therm[v_therm.size()-1];

				// can get negative
				mHsm = pow(std::abs(mHsmsq_therm[v_therm.size()-1]),0.5);
				mG0 = pow(std::abs(mG0sq_therm[v_therm.size()-1] + g2*g2 * v*v /4),0.5);
				mGch = pow(std::abs(mGchsq_therm[v_therm.size()-1] + g2*g2 * v*v /4),0.5);
				if (mHsmsq_therm[v_therm.size()-1] < 0){
					sign_mHsmsq = 0;//-1.;
				} else {sign_mHsmsq = 1.;}
				if (mG0sq_therm[v_therm.size()-1] < 0){
					sign_mG0sq = 0;//-1.;
				} else {sign_mG0sq = 1.;}
				if (mGchsq_therm[v_therm.size()-1] < 0){
					sign_mGchsq = 0;//-1.;
				} else {sign_mGchsq = 1.;}

				// Mass Matrix
				mass_matrix[0][0] = M00_therm[v_therm.size()-1];
				mass_matrix[0][1] = M01_therm[v_therm.size()-1];
				mass_matrix[0][2] = M02_therm[v_therm.size()-1];

				mass_matrix[1][0] = M10_therm[v_therm.size()-1];
				mass_matrix[1][1] = M11_therm[v_therm.size()-1];
				mass_matrix[1][2] = M12_therm[v_therm.size()-1];

				mass_matrix[2][0] = M20_therm[v_therm.size()-1];
				mass_matrix[2][1] = M21_therm[v_therm.size()-1];
				mass_matrix[2][2] = M22_therm[v_therm.size()-1];


				} else {
					//std::cout << "x_in = "<< x << "\n";
					for (size_t i = 1; i < temp_therm.size(); i++){
						//std::cout << "MDM/T = "<< MDM / temp_therm[i] << "\n";
						if (MDM / temp_therm[i] <= x){
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
							mH1 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH1_therm[i-1],mH1_therm[i]);
							mH2 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH2_therm[i-1],mH2_therm[i]);
							mH3 = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mH3_therm[i-1],mH3_therm[i]);
							mHc = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mHc_therm[i-1],mHc_therm[i]);

							THMZ =   linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THMZ_therm[i-1], THMZ_therm[i]);
							THMW =   linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THMW_therm[i-1], THMW_therm[i]);
							THmHsm = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmHsm_therm[i-1], THmHsm_therm[i]);
							THmG0 =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmG0_therm[i-1], THmG0_therm[i]);
							THmGch = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmGch_therm[i-1], THmGch_therm[i]);
							THmH1 =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmH1_therm[i-1], THmH1_therm[i]);
							THmH2 =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmH2_therm[i-1], THmH2_therm[i]);
							THmH3 =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmH3_therm[i-1], THmH3_therm[i]);
							THmHc =  linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], THmHc_therm[i-1], THmHc_therm[i]);

							// can get negative
							double mHsmsq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mHsmsq_therm[i-1],mHsmsq_therm[i]);
							double mG0sq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mG0sq_therm[i-1],mG0sq_therm[i]) + g2*g2 * v*v /4;
							double mGchsq = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], mGchsq_therm[i-1],mGchsq_therm[i]) + g2*g2 * v*v /4;

							mHsm = pow(std::abs(mHsmsq),0.5);
							mG0 = pow(std::abs(mG0sq),0.5);
							mGch = pow(std::abs(mGchsq),0.5);
							if (mHsmsq < 0){
								sign_mHsmsq = 0;//-1.;
							} else {sign_mHsmsq = 1.;}
							if (mG0sq < 0){
								sign_mG0sq = 0;//-1.;
							} else {sign_mG0sq = 1.;}
							if (mGchsq < 0){
								sign_mGchsq = 0;//-1.;
							} else {sign_mGchsq = 1.;}


							// Mass Matrix
							mass_matrix[0][0] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M00_therm[i-1],M00_therm[i]);
							mass_matrix[1][0] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M01_therm[i-1],M01_therm[i]);
							mass_matrix[2][0] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M02_therm[i-1],M02_therm[i]);

							mass_matrix[0][1] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M10_therm[i-1],M10_therm[i]);
							mass_matrix[1][1] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M11_therm[i-1],M11_therm[i]);
							mass_matrix[2][1] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M12_therm[i-1],M12_therm[i]);

							mass_matrix[0][2] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M20_therm[i-1],M20_therm[i]);
							mass_matrix[1][2] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M21_therm[i-1],M21_therm[i]);
							mass_matrix[2][2] = linint(x, MDM/ temp_therm[i-1], MDM / temp_therm[i], M22_therm[i-1],M22_therm[i]);



							break;
						}
					}
				}


			Jacobi eigensys(mass_matrix);


			// std::cout << "EV0 = " << sqrt(eigensys.d[0])<< "\n";
			// std::cout << "EV1 = " << sqrt(eigensys.d[1])<< "\n";
			// std::cout << "EV2 = " << sqrt(eigensys.d[2])<< "\n";

			RR1x1 = eigensys.v[0][0];
			RR2x1 = eigensys.v[0][1];
			RR3x1 = eigensys.v[0][2];
			RR1x2 = eigensys.v[1][0];
			RR2x2 = eigensys.v[1][1];
			RR3x2 = eigensys.v[1][2];
			RR1x3 = eigensys.v[2][0];
			RR2x3 = eigensys.v[2][1];
			RR3x3 = eigensys.v[2][2];



			// std::cout << std::setw(9) << RR1x1 << ",\t" << RR1x2 << ",\t" << RR1x3 <<",\n";
			// std::cout << std::setw(9) << RR2x1 << ",\t" << RR2x2 << ",\t" << RR2x3 <<",\n";
			// std::cout << std::setw(9) << RR3x1 << ",\t" << RR3x2 << ",\t" << RR3x3 <<",\n";
			//std::cout << std::setw(9) << M00_therm[idx] << ",\t" << M01_therm[idx] << ",\t" << M02_therm[idx] <<",\n";
			//std::cout << std::setw(9) << M10_therm[idx] << ",\t" << M11_therm[idx] << ",\t" << M12_therm[idx] <<",\n";
			//std::cout << std::setw(9) << M20_therm[idx] << ",\t" << M21_therm[idx] << ",\t" << M22_therm[idx] <<",\n";

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

			// Parametrisation of the rotation matrix in terms of angles
			double c2 = std::sqrt(1-RR1x3*RR1x3);

			if (c2 == 0){
				alph2 = Pi/2; // theoretically the parametrization should be worng, but otherwise we rephase our particles unnecessary
				alph1 = 0;
				alph3 = -Pi/2;
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


			load_tokens();
			}


			// Include also the Mass Matrix rotation and the Diagonalisation Matrix R calculation from BSMPT


	//	}
	}


	void ModelInfo::read_thermal_parameters(std::string tvev_input_file){
		using namespace PAR;

		std::unique_ptr<DataReader> rdr_therm = std::make_unique<DataReader>(tvev_input_file, 1);

		rdr_therm->read_column(temp_therm, "Temp");
		rdr_therm->read_column(v_therm, "omega_1");
		rdr_therm->read_column(Mnue_therm, "mL_0sq",0.5);
		rdr_therm->read_column(Mnum_therm, "mL_1sq",0.5);
		rdr_therm->read_column(Mnut_therm, "mL_2sq",0.5);

		rdr_therm->read_column(Me_therm, "mL_3sq",0.5);
		rdr_therm->read_column(MM_therm, "mL_5sq",0.5);
		rdr_therm->read_column(MTA_therm, "mL_7sq",0.5);

		rdr_therm->read_column(MU_therm, "mQ_0sq",0.5);
		rdr_therm->read_column(MD_therm, "mQ_2sq",0.5);
		rdr_therm->read_column(MS_therm, "mQ_4sq",0.5);
		rdr_therm->read_column(MC_therm, "mQ_6sq",0.5);
		rdr_therm->read_column(MB_therm, "mQ_8sq",0.5);
		rdr_therm->read_column(MT_therm, "mQ_10sq",0.5);

		rdr_therm->read_column(MW_therm, "mG_1sq",0.5);
		rdr_therm->read_column(THMW_therm, "mG_1sq_T",0.5);
		rdr_therm->read_column(MZ_therm, "mG_3sq",0.5);
		rdr_therm->read_column(THMZ_therm, "mG_3sq_T",0.5);

		rdr_therm->read_column(mGchsq_therm, "mS_0sq");
		rdr_therm->read_column(THmGch_therm, "mS_0sq_T",0.5);
		rdr_therm->read_column(mG0sq_therm, "mS_2sq");
		rdr_therm->read_column(THmG0_therm, "mS_2sq_T",0.5);
		rdr_therm->read_column(mHsmsq_therm, "mS_3sq");
		rdr_therm->read_column(THmHsm_therm, "mS_3sq_T",0.5);

		rdr_therm->read_column(mH1_therm, "mS_4sq",0.5);
		rdr_therm->read_column(THmH1_therm, "mS_4sq_T",0.5);

		size_t posmHc = rdr_therm->get_mHc_pos();

		// 130 is position in file, this is modeldependent and could change.
		if (posmHc == 1){
			rdr_therm->read_column(mHc_therm, "mS_5sq",0.5);
			rdr_therm->read_column(THmHc_therm, "mS_5sq_T",0.5);
			rdr_therm->read_column(mH2_therm, "mS_7sq",0.5);
			rdr_therm->read_column(THmH2_therm, "mS_7sq_T",0.5);
			rdr_therm->read_column(mH3_therm, "mS_8sq",0.5);
			rdr_therm->read_column(THmH3_therm, "mS_8sq_T",0.5);
		} else if (posmHc == 2){
			rdr_therm->read_column(mH2_therm, "mS_5sq",0.5);
			rdr_therm->read_column(THmH2_therm, "mS_5sq_T",0.5);
			rdr_therm->read_column(mHc_therm, "mS_6sq",0.5);
			rdr_therm->read_column(THmHc_therm, "mS_6sq_T",0.5);
			rdr_therm->read_column(mH3_therm, "mS_8sq",0.5);
			rdr_therm->read_column(THmH3_therm, "mS_8sq_T",0.5);
		} else if (posmHc == 3){
			rdr_therm->read_column(mH2_therm, "mS_5sq",0.5);
			rdr_therm->read_column(THmH2_therm, "mS_5sq_T",0.5);
			rdr_therm->read_column(mH3_therm, "mS_6sq",0.5);
			rdr_therm->read_column(THmH3_therm, "mS_6sq_T",0.5);
			rdr_therm->read_column(mHc_therm, "mS_8sq",0.5);
			rdr_therm->read_column(THmHc_therm, "mS_8sq_T",0.5);
		}

		rdr_therm->read_column(M00_therm, "MS_66");
		rdr_therm->read_column(M01_therm, "MS_67");
		rdr_therm->read_column(M02_therm, "MS_68");

		rdr_therm->read_column(M10_therm, "MS_76");
		rdr_therm->read_column(M11_therm, "MS_77");
		rdr_therm->read_column(M12_therm, "MS_78");

		rdr_therm->read_column(M20_therm, "MS_86");
		rdr_therm->read_column(M21_therm, "MS_87");
		rdr_therm->read_column(M22_therm, "MS_88");

		// // change state of the stream
		// std::cout << std::fixed << std::setprecision(6) << std::setfill(' ');
		// // output data

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

		std::vector<std::string> header = {"FAGS", "MW", "EE", "CW2","SW2", "g1","g2","RR1x1","RR1x2","RR1x3","RR2x1","RR2x2","RR2x3","RR3x1","RR3x2","RR3x3","mH3","m11sq","EL","MW0","MZ0","v0","yu1","yu2","yu3","yd1","yd2","yd3","yl1","yl2","yl3","Me","THMZ", "THMW","THmHsm","THmG0","THmGch","THmH1","THmH2","THmH3","THmHc","sign_mHsmsq","sign_mG0sq","sign_mGchsq"};

		std::vector<std::string> header_T = {"Temp","x_i","v"};

		// T x and v
		for (size_t j=0; j< header_T.size();j++) {output_file << header_T[j] << "\t";}
		// parmap
		for (auto &it : parmap) {output_file << it.first << "\t";}
		// loadpar-values
		for (size_t j=0; j< header.size();j++) {output_file << header[j] << "\t";}
		output_file << "\n";

		for (double T_i; T_i<400; T_i++){
			double x_i = MDM / T_i;
			load_parameters(x_i);

			// define; would be nicer with pointers
			std::vector<double> values_T = {T_i,x_i,v};
			std::vector<double> values = {FAGS, MW, EE, CW2,SW2, g1,g2,RR1x1,RR1x2,RR1x3,RR2x1,RR2x2,RR2x3,RR3x1,RR3x2,RR3x3,mH3,m11sq,EL,MW0,MZ0,v0,yu1,yu2,yu3,yd1,yd2,yd3,yl1,yl2,yl3,Me,THMZ, THMW,THmHsm,THmG0,THmGch,THmH1,THmH2,THmH3,THmHc,sign_mHsmsq,sign_mG0sq,sign_mGchsq};

			// output every row
			for (size_t j=0; j< values_T.size();j++){output_file << values_T[j] << "\t";}
			for (auto &it : parmap) {output_file << *it.second << "\t";}
			for (size_t j=0; j< values.size();j++){output_file << values[j] << "\t";}
			output_file << "\n";
		}
		output_file.close();

	}


}	//namespace DT

// programm a read parameter stuff i nvoid read_thermal_parameters();
