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
static constexpr bool FAST = false;
static constexpr bool CALCWIDTHS = false;
static constexpr bool SAVECONTRIBS = false;
//static constexpr bool THERMALCONTRIBS = false;
//static constexpr bool SCALARTHERMALPROB = false;
/*
 ***********************************************
 Until here */

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
