#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
static constexpr bool THERMALCONTRIBS = false;
/*
 ***********************************************
 Until here */

 /*
    Tims Folder settings
------------------------------------------------
 */
int datapoint = 5415;
std::string outpath = "cpvdm/datapoint_" + std::to_string(datapoint) + "/";
//std::string outpath ="cpvdm/";
/*
------------------------------------------------
*/


    /*      NEW CODE STUFF
                    ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_5_5415_thmasses_1.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat
                    ./cpvdm cpvdm/cpvdm_1To2TeV_4712prime_input_1.tsv cpvdm/cpvdm_1To2TeV_4712prime_thmasses_1.tsv cpvdm/datapoint_4712prime/output.tsv
                    ./cpvdm cpvdm_DEBUGThermMasses_L12_m26to8_ms6dif200_A10_1_1.tsv cpvdm_DEBUGThermMasses_L12_m26to8_ms6dif200_A10_1_out.tsv
    */



void CalcAllXsec(Main &M, int firstline, int lastline, double sqsmin, double sqsmax,  const size_t points){
    std::ifstream f;
    // path to textfile with all channels
    f.open("/users/tp/tkrause/Documents/RelExt/dataInput/cpvdm/cpvdm_channels.txt");
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
            std::vector<int> xvals = {1,4970,5000,6000,9999999};
            //CalcXsec
            for (size_t i =0; i<xvals.size();i++){
                std::string strx = std::to_string(xvals[i]);
                std::cout << line << " at " << strx << "\n";

                std::string outfile = outpath + "xsec/calcXsec_" + line + "_" + strx + ".dat";
                double val = xvals[i];
                M.CalcXsec(sqsmin,sqsmax,points,outfile,{line}, val); //"H1,H1,h,h"
            }
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
            std::string outfile = outpath + "tacthm/calcTac_Ry_thm_" + line + ".tsv";
            M.CalcTac(xmin,xmax,points,outfile,{line});
        }
        if (row==lastline){break;}
    }
    f.close();

}

void CalcStepTac(Main &M, int firstline, int lastline, double xmin, double xmax,  const size_t points){
    std::ifstream f;
    // path to textfile with all channels
    f.open("/home/kijetesantakalu/Schreibtisch/channels_cpvdmb_fromempty.txt"); // same order as {}. Is this different!??
    if (!f) {
        std::cerr << "Failed to open file.\n";
    }
    std::string line;

    std::vector<std::string> channels;
    int row=0;
    while (getline(f, line)){
        // firstline starts at 1, lastline also starts at 1

        row++;
        if (row >= firstline){
            //std::cout << line << "\n";
            channels.push_back(line);

            //CalcTac
            std::string outfile = outpath + "steptacthm/calcTac_Ry_thm_upto_" + line + ".tsv";

            std::cout << "the channels contributing to row "<< row << " are:"  <<std::endl;
            for (auto &it : channels){
                std::cout << it << std::endl;
            }
            //if (line == "H3,H3,h,G0")
            M.CalcTac(xmin,xmax,points,outfile,channels);
        }
        if (row==lastline){break;}
    }
    f.close();

    // lets do one where I select all
    std::string outfile = outpath + "steptacthm/calcTac_Ry_thm_upto_empty.tsv";
    M.CalcTac(xmin,xmax,points,outfile,{});

}

void CalcStepTac_backwards(Main &M, int firstline, int lastline, double xmin, double xmax,  const size_t points){
    std::ifstream f;
    // path to textfile with all channels
    f.open("/home/kijetesantakalu/Schreibtisch/channels_cpvdmb_fromempty.txt"); // same order as {}. Is this different!??
    if (!f) {
        std::cerr << "Failed to open file.\n";
    }
    std::string line;

    std::vector<std::string> channels;
    int row=0;
    while (getline(f, line)){
        // firstline starts at 1, lastline also starts at 1

        row++;
        if (row >= firstline){ // && line != ""
            std::cout << line << "\n";
            channels.push_back(line);
        }
        if (row==lastline){break;}
    }
    f.close();

    size_t stor_n = channels.size();
    for (size_t i=0; i< stor_n;i++ ){
        std::string outfile = outpath + "steptacthmbackwards/calcTac_Ry_thm_upto_" + channels[channels.size()-1] + ".tsv";
        M.CalcTac(xmin,xmax,points,outfile,channels);
        channels.pop_back();
    }

}



int main (int argc, char **argv) {
    Main M(argv, MODE, BEPS, XTODAY, FAST, CALCWIDTHS,THERMALCONTRIBS, SAVECONTRIBS);
    M.set_channels(CONSIDERCHANNELS, NEGLECTCHANNELS, NEGLECTPARTICLES);

    clock_t begin_time = clock();

    //load the parameter point
    M.LoadParameters(1);
    //M.PrintChannels();


    //M.CalcTac(5,40,1e2, "calcTac_test_all.tsv",{});
    //double low_s = 3692+4514;
    //M.CalcXsec(low_s,low_s+100,100,"calcXSec_test_all.tsv",{},5);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)

   /*
        //Calculate the cross sections

        //only calculate certain channels:
        //H1H1: 0,13  H1H2: 14,29 H1H3:30,45  H1Hc:46,60
        //H3H3:105,117  NEEDS A BIGGER RANGE: M,105,117,1900,2060,1e3+900

        CalcAllXsec(M,0,200,1900,2060,1e3+900);
        M.CalcXsec(2003,2004,1,outpath+"xsec/calcXsec_H3HcAW_" + std::to_string(4970) +".dat",{"H3,Hc,A,W"},4970);
    */
    //CalcXsec
    // Calculate the TAC
    //int val = std::atoi(argv[4]);
    //M.CalcXsec(1850,3000,100,outpath+"xsec/calcXsec_wgoldstones_test_fullmasses_all_5.dat",{},5);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)

    //M.CalcTac(2,200,200,outpath + "tac/calcTac_wgoldstones_test_thermalmasses_H1H1wW.tsv",{"H1,H1,w,W"}); //"H1,H1,Z,Z"

    /*
    std::ifstream f;
    f.open("/home/kijetesantakalu/Schreibtisch/channels_cpvdmb_bfewsb.txt");
    if (!f) {
        std::cerr << "Failed to open file.\n";
    }
    std::string line;

    while (getline(f, line)){
        // firstline starts at 1, lastline also starts at 1

        std::string outfile = outpath + "xsec/test/calcXsec_" + line + ".dat";
        std::cout << outfile << "\n";
        M.CalcTac(2,50,10,outfile,{line}); //"H1,H1,h,h"
    }
    f.close();
    */

    //args are Main, firstline, lastline, xmin, xmax, points
    //CalcAllTac(M,val,val,0.1,30,1e2);
    //M.CalcTac(20,40,20, "calcTac_test_all.tsv",{});
    //M.CalcTac(3,200,1e2,outpath + "tac/calcTac_thm_" + "all" + ".tsv",{"H2,Hc,h,W"});
    //M.CalcTac(3,200,2e2,"cpvdm/datapoint_4712prime/calcTac_thm_all.tsv",{}); //"H2,H3,T,t"
    //M.CalcXsec(1850,2500,5e2,"cpvdm/datapoint_4712prime/calcXsec_thm_all.tsv",{},9);//"H1,H2,h,G0" : "H3,H3,h,G0" (NEGATIVE)

    // if (THERMALCONTRIBS){
    //     M.CalcTac(18,5000,2e2,"cpvdm/calcTac_inBSMPT39_all.tsv",{}); //"H2,H3,T,t"
    // } else {
    //     M.CalcTac(18,5000,2e2,"cpvdm/calcTac_inBSMPT39_all_back.tsv",{}); //"H2,H3,T,t"
    // }


    //CalcStepTac(M, 0, 212, 5, 200,  1e2);
    //CalcStepTac_backwards(M, 0, 212, 5, 200,  1e2);

    M.CalcRelic();

    M.SaveData(SAVEPARS);
    std::cout << "Computation time: \n"
              << float(clock() - begin_time ) / CLOCKS_PER_SEC << std::endl ;
}



    /*
     * cpvdm_5_5415_thmasses_1.tsv
         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_tvev_5415.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat

         ./cpvdm cpvdm/cpvdm_vals_5415.tsv cpvdm/cpvdm_5_5415_thmasses_1.tsv cpvdm/datapoint_5415/cpvdm_vals_res.dat
         ./cpvdm cpvdm/batch/cpvdm_vals_24690.tsv cpvdm/batch/cpvdm_tvev_24690.tsv cpvdm/batch/cpvdm_vals_res_24690.dat
    */
