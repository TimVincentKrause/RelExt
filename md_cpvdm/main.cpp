#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "maincl.hpp"
#include "model.hpp"

using namespace DT;
/* Change to desired settings starting from here
 ***********************************************
 */
static constexpr int MODE = 3;
static const VecString SAVEPARS = {"mH1",   "mH2",   "mHc",   "alph1",
                                   "alph2", "alph3", "m22sq", "mssq",
                                   "L2",    "L6",    "L8"};
//static const VecString CONSIDERCHANNELS = {"H1,H1,h,h","H1,H1,E,e","H1,H1,w,W","H1,H1,GCH,W","H1,H1,Gch,w","H1,H1,G0,G0","H1,H1,h,Z","H1,H1,Z,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H1,D,d","H1,H1,T,t","H1,H1,B,b","H1,H1,C,c","H1,H1,S,s","H1,H1,U,u","H1,H1,M,m","H1,H1,GCH,Gch","H1,H1,TA,ta"};
//static const VecString CONSIDERCHANNELS = {"H1,H1,h,h","H1,H1,w,W","H1,H1,GCH,W","H1,H1,Gch,w","H1,H1,G0,G0","H1,H1,h,Z","H1,H1,Z,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H1,T,t","H1,H1,B,b","H1,H1,C,c","H1,H1,S,s","H1,H1,M,m","H1,H1,GCH,Gch","H1,H1,TA,ta"};
//static const VecString CONSIDERCHANNELS = {"H1,H3,U,u","H1,H3,VE,ve","H1,Hc,u,S","H1,H3,GCH,Gch","H1,H2,Z,Z","H1,H3,B,b","H1,H2,S,s","H1,H2,D,d","H1,H2,h,Z","H1,H2,TA,ta","H1,Hc,Z,W","H1,H2,M,m","H1,H2,VT,vt","H1,H3,w,W","H1,H3,E,e","H1,H3,G0,Z","H1,H3,Z,Z","H1,H3,TA,ta","H1,H1,h,h","H1,H2,U,u","H1,H1,E,e","H1,Hc,c,B","H1,H1,w,W","H1,H1,GCH,W","H1,H2,w,W","H1,H1,Gch,w","H1,H2,VM,vm","H1,H1,G0,G0","H1,H2,B,b","H1,H3,G0,G0","H1,H2,h,G0","H1,H2,T,t","H1,H3,M,m","H1,H1,h,Z","H1,H3,Gch,w","H1,H2,GCH,Gch","H1,Hc,t,S","H1,H3,h,h","H1,H3,VM,vm","H1,H1,Z,Z","H1,Hc,Gch,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H3,S,s","H1,H2,C,c","H1,Hc,h,Gch","H1,H1,D,d","H1,H3,VT,vt","H1,H1,T,t","H1,H1,B,b","H1,H2,E,e","H1,H1,C,c","H1,H2,G0,G0","H1,Hc,vt,TA","H1,H2,h,h","H1,H3,GCH,W","H1,H2,G0,Z","H1,H1,S,s","H1,H2,GCH,W","H1,H2,Gch,w","H1,H3,C,c","H1,H1,U,u","H1,H3,T,t","H1,Hc,G0,Gch","H1,Hc,h,W","H1,H3,h,Z","H1,Hc,Gch,A","H1,Hc,A,W","H1,Hc,vm,M","H1,H2,VE,ve","H1,Hc,u,D","H1,Hc,u,B","H1,Hc,c,D","H1,Hc,t,D","H1,Hc,t,B","H1,H1,M,m","H1,Hc,G0,W","H1,Hc,ve,E","H1,H1,GCH,Gch","H1,H3,D,d","H1,Hc,c,S","H1,H3,h,G0","H1,H1,TA,ta"};
static const VecString CONSIDERCHANNELS = {};
//static const VecString CONSIDERCHANNELS = {"H1,H1,w,W"};
VecString NEGLECTCHANNELS = {};
static const VecString NEGLECTPARTICLES ={}; //{"u", "d", "e", "mu"};//{"u", "d", "e", "mu"};
static constexpr double BEPS = 1e-6;
static constexpr double XTODAY = 1e6;
static constexpr bool FAST = false;
static constexpr bool CALCWIDTHS = false;
static constexpr bool SAVECONTRIBS = false;
//static constexpr bool THERMALCONTRIBS = false;
//static constexpr bool SCALARTHERMALPROB = false;
//static constexpr bool TAKEDAISYPHYS = false;
/*
 ***********************************************
 Until here */


void CalcAllXsec(Main &M, int firstline, int lastline, double sqsmin, double sqsmax,  const size_t points, std::string thermcontrib){
    std::ifstream f;
    // path to textfile with all channels
    f.open("/home/kijetesantakalu/thesis/vevyRelExt/md_cpvdm/cpvdm_channels.txt");
    if (!f) {
        std::cerr << "Failed to open file.\n";
    }
    std::string line;

    int row=0;
    while (getline(f, line)){
        // firstline starts at 1, lastline also starts at 1

        row++;
        if (row >= firstline){
            // about v= 0,20,50,150,246
            //std::vector<int> xvals = {1,4970,5000,6000,9999999};
            //CalcXsec
            //for (size_t i =0; i<xvals.size();i++){
            // std::string strx = std::to_string(xvals[i]);
            // std::cout << line << " at " << strx << "\n";

            std::string outfile = "../dataOutput/xsec/calcXsec_" + line + "_" + thermcontrib + ".dat";
            //double val = xvals[i];
            M.CalcXsec(sqsmin,sqsmax,points,outfile,{line}, 23.7); //"H1,H1,h,h"
                //}
        }
        if (row==lastline){break;}
    }
    f.close();

}

void CalcAllTac(Main &M, int firstline, int lastline, double xmin, double xmax,  const size_t points){
    std::ifstream f;
    // path to textfile with all channels
    f.open("/home/kijetesantakalu/Schreibtisch/channels_cpvdmb_bfewsb.txt");
    if (!f) {
        std::cerr << "Failed to open file.\n";
    }
    std::string line;

    int row=0;
    while (getline(f, line)){
        // firstline starts at 1, lastline also starts at 1

        row++;
        if (row >= firstline){
            std::cout << line << "\n";
            //CalcTac
            std::string outfile = "../dataOutput/batchtac/calcTac_Ry_thm_" + line + ".tsv";
            M.CalcTac(xmin,xmax,points,outfile,{line});
        }
        if (row==lastline){break;}
    }
    f.close();

}




int main (int argc, char **argv) {

    std::stringstream s3(argv[3]);
    std::stringstream s4(argv[4]);
    std::stringstream s5(argv[5]);

    bool SCALARTHERMALPROB;
    if (!(s3 >> std::boolalpha >> SCALARTHERMALPROB)){
        std::cout << "Error: parsing mistake in arv[3] (should be true/false)"<<std::endl;
    }
    bool THERMALCONTRIBS;
    if (!(s4 >> std::boolalpha >> THERMALCONTRIBS)){
        std::cout << "Error: parsing mistake in arv[4] (should be true/false)"<<std::endl;
    }
    bool TAKEDAISYPHYS;
    if (!(s5 >> std::boolalpha >> TAKEDAISYPHYS)){
        std::cout << "Error: parsing mistake in arv[5] (should be true/false)"<<std::endl;
    }

    Main M(argv, MODE, BEPS, XTODAY, FAST, CALCWIDTHS,THERMALCONTRIBS,SCALARTHERMALPROB,TAKEDAISYPHYS, SAVECONTRIBS);
    M.set_channels(CONSIDERCHANNELS, NEGLECTCHANNELS, NEGLECTPARTICLES);

    //clock_t begin_time = clock();

    //load the parameter point
    M.LoadParameters(1);
    //M.CalcYield(15,1000,400,"../dataOutput/yield_949_std.tsv");
    //std::string thermcontrib = argv[4];
    // M.CalcXsec(1,1200,1200,"../dataOutput/xsec_all_1756_x1.tsv",{},1);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)

    //M.CalcXsec(11000,100000,1000,"../dataOutput/xsec_21249_x30.tsv",{},30);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)
    //M.CalcXsec(11000,100000,1000,"../dataOutput/xsec_21249_xt.tsv",{},100);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)
    //M.CalcXsec(11000,100000,1000,"../dataOutput/xsec_987_incl.tsv",{"Hc,Hc,W,W"},30);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)
    //CalcAllTac(M, 0, 300, 32, 34,  100);
    M.CalcTac(15,1000,400, "../dataOutput/tac_949_std_full.tsv");
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HchW.tsv",{"H1,Hc,h,W"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HchGch.tsv",{"H1,Hc,h,Gch"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcG0Gch.tsv",{"H1,Hc,G0,Gch"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcGchA.tsv",{"H1,Hc,Gch,A"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcGchZ.tsv",{"H1,Hc,Gch,Z"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcAW.tsv",{"H1,Hc,A,W"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcZW.tsv",{"H1,Hc,Z,W"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HctB.tsv",{"H1,Hc,t,B"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HctD.tsv",{"H1,Hc,t,D"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HctS.tsv",{"H1,Hc,t,S"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcuB.tsv",{"H1,Hc,u,B"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcuD.tsv",{"H1,Hc,u,D"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcuS.tsv",{"H1,Hc,u,S"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HccB.tsv",{"H1,Hc,c,B"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HccD.tsv",{"H1,Hc,c,D"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HccS.tsv",{"H1,Hc,c,S"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcveE.tsv",{"H1,Hc,ve,E"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcvmM.tsv",{"H1,Hc,vm,M"});
    // M.CalcTac(15,1000,50, "../dataOutput/tac_949_imp_H1HcvtTA.tsv",{"H1,Hc,vt,TA"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H1H1.tsv",{"H1,H1,h,h","H1,H1,h,G0", "H1,H1,G0,G0", "H1,H1,GCH,Gch", "H1,H1,h,Z", "H1,H1,G0,Z", "H1,H1,GCH,W", "H1,H1,Gch,w", "H1,H1,Z,Z", "H1,H1,w,W", "H1,H1,E,e", "H1,H1,M,m", "H1,H1,TA,ta", "H1,H1,U,u", "H1,H1,C,c", "H1,H1,T,t", "H1,H1,D,d", "H1,H1,S,s", "H1,H1,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H1H2.tsv",{"H1,H2,h,h", "H1,H2,h,G0", "H1,H2,G0,G0", "H1,H2,GCH,Gch", "H1,H2,h,Z", "H1,H2,G0,Z", "H1,H2,GCH,W", "H1,H2,Gch,w", "H1,H2,Z,Z", "H1,H2,w,W", "H1,H2,VE,ve", "H1,H2,VM,vm", "H1,H2,VT,vt", "H1,H2,E,e", "H1,H2,M,m", "H1,H2,TA,ta", "H1,H2,U,u", "H1,H2,C,c", "H1,H2,T,t", "H1,H2,D,d", "H1,H2,S,s", "H1,H2,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H1H3.tsv",{"H1,H3,h,h", "H1,H3,h,G0", "H1,H3,G0,G0", "H1,H3,GCH,Gch", "H1,H3,h,Z", "H1,H3,G0,Z", "H1,H3,GCH,W", "H1,H3,Gch,w", "H1,H3,Z,Z", "H1,H3,w,W", "H1,H3,VE,ve", "H1,H3,VM,vm", "H1,H3,VT,vt", "H1,H3,E,e", "H1,H3,M,m", "H1,H3,TA,ta", "H1,H3,U,u", "H1,H3,C,c", "H1,H3,T,t", "H1,H3,D,d", "H1,H3,S,s", "H1,H3,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H1Hc.tsv",{"H1,Hc,h,Gch", "H1,Hc,G0,Gch", "H1,Hc,h,W", "H1,Hc,G0,W", "H1,Hc,Gch,A", "H1,Hc,Gch,Z", "H1,Hc,A,W", "H1,Hc,Z,W", "H1,Hc,ve,E", "H1,Hc,vm,M", "H1,Hc,vt,TA", "H1,Hc,u,D", "H1,Hc,u,S", "H1,Hc,u,B", "H1,Hc,c,D", "H1,Hc,c,S", "H1,Hc,c,B", "H1,Hc,t,D", "H1,Hc,t,S", "H1,Hc,t,B"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H2H2.tsv",{"H2,H2,h,h", "H2,H2,h,G0", "H2,H2,G0,G0", "H2,H2,GCH,Gch", "H2,H2,h,Z", "H2,H2,G0,Z", "H2,H2,GCH,W", "H2,H2,Gch,w", "H2,H2,Z,Z", "H2,H2,w,W", "H2,H2,E,e", "H2,H2,M,m", "H2,H2,TA,ta", "H2,H2,U,u", "H2,H2,C,c", "H2,H2,T,t", "H2,H2,D,d", "H2,H2,S,s", "H2,H2,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H2H3.tsv",{"H2,H3,h,h", "H2,H3,h,G0", "H2,H3,G0,G0", "H2,H3,GCH,Gch", "H2,H3,h,Z", "H2,H3,G0,Z", "H2,H3,GCH,W", "H2,H3,Gch,w", "H2,H3,Z,Z", "H2,H3,w,W", "H2,H3,VE,ve", "H2,H3,VM,vm", "H2,H3,VT,vt", "H2,H3,E,e", "H2,H3,M,m", "H2,H3,TA,ta", "H2,H3,U,u", "H2,H3,C,c", "H2,H3,T,t", "H2,H3,D,d", "H2,H3,S,s", "H2,H3,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H2Hc.tsv",{"H2,Hc,h,Gch", "H2,Hc,G0,Gch", "H2,Hc,h,W", "H2,Hc,G0,W", "H2,Hc,Gch,A", "H2,Hc,Gch,Z", "H2,Hc,A,W", "H2,Hc,Z,W", "H2,Hc,ve,E", "H2,Hc,vm,M", "H2,Hc,vt,TA", "H2,Hc,u,D", "H2,Hc,u,S", "H2,Hc,u,B", "H2,Hc,c,D", "H2,Hc,c,S", "H2,Hc,c,B", "H2,Hc,t,D", "H2,Hc,t,S", "H2,Hc,t,B"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H3H3.tsv",{"H3,H3,h,h", "H3,H3,h,G0", "H3,H3,G0,G0", "H3,H3,GCH,Gch", "H3,H3,h,Z", "H3,H3,G0,Z", "H3,H3,GCH,W", "H3,H3,Gch,w", "H3,H3,Z,Z", "H3,H3,w,W", "H3,H3,E,e", "H3,H3,M,m", "H3,H3,TA,ta", "H3,H3,U,u", "H3,H3,C,c", "H3,H3,T,t", "H3,H3,D,d", "H3,H3,S,s", "H3,H3,B,b"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_H3Hc.tsv",{"H3,Hc,h,Gch", "H3,Hc,G0,Gch", "H3,Hc,h,W", "H3,Hc,G0,W", "H3,Hc,Gch,A", "H3,Hc,Gch,Z", "H3,Hc,A,W", "H3,Hc,Z,W", "H3,Hc,ve,E", "H3,Hc,vm,M", "H3,Hc,vt,TA", "H3,Hc,u,D", "H3,Hc,u,S", "H3,Hc,u,B", "H3,Hc,c,D", "H3,Hc,c,S", "H3,Hc,c,B", "H3,Hc,t,D", "H3,Hc,t,S", "H3,Hc,t,B"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_HcHc.tsv",{"Hc,Hc,Gch,Gch", "Hc,Hc,Gch,W", "Hc,Hc,W,W"});
    // M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_HcHC.tsv",{"Hc,HC,h,h", "Hc,HC,h,G0", "Hc,HC,G0,G0", "Hc,HC,GCH,Gch", "Hc,HC,h,A", "Hc,HC,h,Z", "Hc,HC,G0,Z", "Hc,HC,GCH,W", "Hc,HC,Gch,w", "Hc,HC,A,A", "Hc,HC,A,Z", "Hc,HC,Z,Z", "Hc,HC,w,W", "Hc,HC,VE,ve", "Hc,HC,VM,vm", "Hc,HC,VT,vt", "Hc,HC,E,e", "Hc,HC,M,m", "Hc,HC,TA,ta", "Hc,HC,U,u", "Hc,HC,C,c", "Hc,HC,T,t", "Hc,HC,D,d", "Hc,HC,S,s", "Hc,HC,B,b"});
    // //M.CalcTac(15,1000,200, "../dataOutput/tac_949_imp_HcHCZZ.tsv",{"Hc,HC,Z,Z"});

    // //CalcAllXsec(M,0,200,8400,10000,200,thermcontrib);
    //M.PrintChannels();
    M.CalcRelic();




    M.SaveData(SAVEPARS);
    // std::cout << "Computation time: \n"
    //           << float(clock() - begin_time ) / CLOCKS_PER_SEC << std::endl ;
}

    /*
     * ./cpvdm /home/kijetesantakalu/thesis/wierdpoints/cpvdm_ThermMass_L25_nm_m26to10_ms6to10_A5000_978_1.tsv ../dataOutput/out_978.dat
     * ./cpvdm /home/kijetesantakalu/thesis/forquilha/cluster_bash/out/cpvdmS_ThermMass_L25_nm_m26to10_ms6to10_A5000_949_1.tsv ../dataOutput/out_949.dat
     */

    // cpvdm_ThermMass_L25_nm_m26to10_ms6to10_A5000_949_1.tsv
    //
    //


    /*
     * cpvdm_5_5415_thmasses_1.tsv
         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_tvev_5415.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat

         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_5_5415_thmasses_1.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat
         ./cpvdm cpvdm/batch/cpvdm_vals_24690.tsv cpvdm/batch/cpvdm_tvev_24690.tsv cpvdm/batch/cpvdm_vals_res_24690.dat
    */
