#pragma once

#include <algorithm>
#include <cassert>
#include <cctype>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "EffDof.hpp"
#include "utils.hpp"
#include "numerical/matrix_operations.hpp"

namespace DT {
#define ADDCHANNEL(name, amp, ampfl) \
    amp2s[name] = amp;               \
    amp2fls[name] = ampfl;

#define CHECKCONDITION(condition) \
    if (!(condition)) return false;

typedef std::function<double(const double &, const double &)> f;
typedef std::vector<f> vamp2;
typedef std::unordered_map<std::string, f> fmap;
typedef std::unordered_map<std::string, double *> sMapDp;

struct ModelInfo {
    sMapDp DSmasses;
    std::map<std::string, double *> prtcls;
    std::map<std::string, double *> aprtcls;
    std::vector<double *> neutraldsmasses;
    std::unordered_map<std::string, double> DSdof;
    std::map<std::string, double *> parmap;
    std::vector<double *> denstructures;
    size_t N_widths;
    VecString bath_masses;
    const bool calc_widths;
    double ZERO = 0;
    double MDM = 0.;

    // store temperature and vev(T)
    std::vector<double*> vev;
    std::vector<double*> temp;

    // use thermal parameters
    const bool therm_contr;
    const bool scal_therm_prop;

    void init();
    void calc_widths_and_scale();
    void load_prtcls();
    void load_parameters(const double x = 1e7);
    void read_thermal_parameters(std::string tvev_input_file);
    void save_parameters();
    void load_parameter_map();
    void load_tokens();
    bool check_conditions();
    void print_prtcls();
    void print_DM();
    bool load_everything();
    double get_prtcl_mass(const std::string &prtcl);
    bool check_par_existence(const std::string &par);
    bool change_parameter(const std::string &par, const double newval,
                          const bool load = true);

    void assign_bath_masses(const VecString &prtcls = {});
    void assigndm();

    ModelInfo(const bool calcwidths,const bool thermcontr, const bool scalthermprop);
};

class AnnihilationAmps : public ModelInfo {
   private:
    double s;
    fmap amp2s;
    fmap amp2fls;
    vamp2 cur_channel;

   public:
    AnnihilationAmps(const bool calcwidths, const bool thermcontr, const bool scalthermprop);

    void init();
    void print_channels();
    VecString get_all_channels();
    void channel_parity(int &p1, int &p2, const std::string &channel);
    bool check_channel_existence(std::string &channel);
    VecString get_channel_prtcls(const std::string &channel);
    void get_channel_masses(double &m1, double &m2, double &m3, double &m4,
                            const std::string &channel);
    VecString find_channels_by_particle(const std::string &particle);
    void assign_masses(double &m1, double &m2, const std::string &channel);
    VecString find_thermal_procs(const VecString &prtcls = {});
    void set_s(const double new_s);
    void set_channel(const VecString &ch_str, const bool flux = true);
    double operator()(const double cos_t);

    ~AnnihilationAmps() {};
};
}  // namespace DT
