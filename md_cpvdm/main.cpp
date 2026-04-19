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
static const VecString CONSIDERCHANNELS = {};
VecString NEGLECTCHANNELS = {};
static const VecString NEGLECTPARTICLES = {"u", "d", "e", "mu"};
static constexpr double BEPS = 1e-6;
static constexpr double XTODAY = 1e6;
static constexpr bool FAST = true;
static constexpr bool CALCWIDTHS = false;
static constexpr bool SAVECONTRIBS = false;
//static constexpr bool THERMALCONTRIBS = false;
//static constexpr bool SCALARTHERMALPROB = false;
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

    bool SCALARTHERMALPROB;
    if (!(s3 >> std::boolalpha >> SCALARTHERMALPROB)){
        std::cout << "Error: parsing mistake in arv[3] (should be true/false)"<<std::endl;
    }
    bool THERMALCONTRIBS;
    if (!(s4 >> std::boolalpha >> THERMALCONTRIBS)){
        std::cout << "Error: parsing mistake in arv[4] (should be true/false)"<<std::endl;
    }

    Main M(argv, MODE, BEPS, XTODAY, FAST, CALCWIDTHS,THERMALCONTRIBS,SCALARTHERMALPROB, SAVECONTRIBS);
    M.set_channels(CONSIDERCHANNELS, NEGLECTCHANNELS, NEGLECTPARTICLES);

    //clock_t begin_time = clock();

    //load the parameter point
    M.LoadParameters(1);
    //std::string thermcontrib = argv[4];
    //M.CalcXsec(8400,10000,200,"../dataOutput/xsec_all_23_" + thermcontrib + ".tsv",{},23.78);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)
    //M.CalcTac(22,24,200, "../dataOutput/tac_all_23_"+ thermcontrib +".tsv");
    //CalcAllXsec(M,0,200,8400,10000,200,thermcontrib);
    //M.CalcTac(2,200,200,outpath + "tac/calcTac_wgoldstones_test_thermalmasses_H1H1wW.tsv",{"H1,H1,w,W"}); //"H1,H1,Z,Z"

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
