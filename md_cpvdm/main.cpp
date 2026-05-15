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
static const VecString CONSIDERCHANNELS = {"H1,H1,h,h","H1,H1,E,e","H1,H1,w,W","H1,H1,GCH,W","H1,H1,Gch,w","H1,H1,G0,G0","H1,H1,h,Z","H1,H1,Z,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H1,D,d","H1,H1,T,t","H1,H1,B,b","H1,H1,C,c","H1,H1,S,s","H1,H1,U,u","H1,H1,M,m","H1,H1,GCH,Gch","H1,H1,TA,ta"};
//static const VecString CONSIDERCHANNELS = {"H1,H1,h,h","H1,H1,w,W","H1,H1,GCH,W","H1,H1,Gch,w","H1,H1,G0,G0","H1,H1,h,Z","H1,H1,Z,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H1,T,t","H1,H1,B,b","H1,H1,C,c","H1,H1,S,s","H1,H1,M,m","H1,H1,GCH,Gch","H1,H1,TA,ta"};
//static const VecString CONSIDERCHANNELS = {"H1,H3,U,u","H1,H3,VE,ve","H1,Hc,u,S","H1,H3,GCH,Gch","H1,H2,Z,Z","H1,H3,B,b","H1,H2,S,s","H1,H2,D,d","H1,H2,h,Z","H1,H2,TA,ta","H1,Hc,Z,W","H1,H2,M,m","H1,H2,VT,vt","H1,H3,w,W","H1,H3,E,e","H1,H3,G0,Z","H1,H3,Z,Z","H1,H3,TA,ta","H1,H1,h,h","H1,H2,U,u","H1,H1,E,e","H1,Hc,c,B","H1,H1,w,W","H1,H1,GCH,W","H1,H2,w,W","H1,H1,Gch,w","H1,H2,VM,vm","H1,H1,G0,G0","H1,H2,B,b","H1,H3,G0,G0","H1,H2,h,G0","H1,H2,T,t","H1,H3,M,m","H1,H1,h,Z","H1,H3,Gch,w","H1,H2,GCH,Gch","H1,Hc,t,S","H1,H3,h,h","H1,H3,VM,vm","H1,H1,Z,Z","H1,Hc,Gch,Z","H1,H1,G0,Z","H1,H1,h,G0","H1,H3,S,s","H1,H2,C,c","H1,Hc,h,Gch","H1,H1,D,d","H1,H3,VT,vt","H1,H1,T,t","H1,H1,B,b","H1,H2,E,e","H1,H1,C,c","H1,H2,G0,G0","H1,Hc,vt,TA","H1,H2,h,h","H1,H3,GCH,W","H1,H2,G0,Z","H1,H1,S,s","H1,H2,GCH,W","H1,H2,Gch,w","H1,H3,C,c","H1,H1,U,u","H1,H3,T,t","H1,Hc,G0,Gch","H1,Hc,h,W","H1,H3,h,Z","H1,Hc,Gch,A","H1,Hc,A,W","H1,Hc,vm,M","H1,H2,VE,ve","H1,Hc,u,D","H1,Hc,u,B","H1,Hc,c,D","H1,Hc,t,D","H1,Hc,t,B","H1,H1,M,m","H1,Hc,G0,W","H1,Hc,ve,E","H1,H1,GCH,Gch","H1,H3,D,d","H1,Hc,c,S","H1,H3,h,G0","H1,H1,TA,ta"};
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
    //M.CalcYield(1e-1,500,200,"/run/media/kijetesantakalu/leftVolume/tkrause/look_atThmFiles/out/yield_out.tsv");
    //std::string thermcontrib = argv[4];
    //M.CalcXsec(8400,10000,200,"../dataOutput/xsec_all_23_" + thermcontrib + ".tsv",{},23.78);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)
    //M.CalcTac(22,24,200, "../dataOutput/tac_all_23_"+ thermcontrib +".tsv");
    //CalcAllXsec(M,0,200,8400,10000,200,thermcontrib);
    //M.CalcTac(2,200,200,outpath + "tac/calcTac_wgoldstones_test_thermalmasses_H1H1wW.tsv",{"H1,H1,w,W"}); //"H1,H1,Z,Z"

    //M.PrintChannels();
    M.CalcRelic();

    M.SaveData(SAVEPARS);
    // std::cout << "Computation time: \n"
    //           << float(clock() - begin_time ) / CLOCKS_PER_SEC << std::endl ;
}



    /*
     * cpvdm_5_5415_thmasses_1.tsv
         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_tvev_5415.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat

         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_5_5415_thmasses_1.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat
         ./cpvdm cpvdm/batch/cpvdm_vals_24690.tsv cpvdm/batch/cpvdm_tvev_24690.tsv cpvdm/batch/cpvdm_vals_res_24690.dat
    */
