#ifndef INTEGRALS_H
#define INTEGRALS_H

#include <vector>
#include <fstream>

#include "surface.h"
#include "utils.h"
#include "particle_data_group.h"

using namespace std;

template <typename T>
int sign(T x){
  return (T(0)<x)-(x<T(0));
}
//computes the mean spin vector for particles emitted at midrapidity for the particle "particle" using
//the freezeout file "freezeout_sup". For the thermal vorticity, eq. 64 of 2304.02276 is used
//The output is written in "fileout" as a table:
//pt phi denominator numerator_varpi numerator_xi
//refer to 2103.10917
void polarization_midrapidity(double pT, double phi, pdg_particle particle, vector<element> &freeze_out_sup, ofstream &fileout);

//same as the previous function but uses the linear approximation for the vorticity induced polarization. This function is faster.
void polarization_midrapidity_linear(double pT, double phi, pdg_particle particle, vector<element> &freeze_out_sup, ofstream &fileout);
//same as the previous but uses the new formula (2509.14301)
void polarization_midrapidity_linear_new(double pT, double phi, pdg_particle particle, vector<element> &freeze_out_sup, ofstream &fileout);

//Returns wheter a cell is or is not intersected by the world line
bool intersection(const element& ref_cell, const element& cell, const std::array<double,4> momentum);

//Given a reference cell and a four-momentum returns a list of pointers to cells that are intersected by the worldline
std::vector<const element*> intersections_list(const element& ref_cell, const std::vector<element>& hypersup, const std::array<double,4>& momentum);

//Same as "polarization_midrapidity", but the table now includes the rapidity "y":
//pt phi y denominator numerator_varpi numerator_xi
void polarization_exact_rapidity(double pT, double phi, double y_rap, pdg_particle particle, vector<element> &freeze_out_sup, ofstream &fileout);

//auxiliary function to compute polarization for any spin
double aux_exact_polarization(double spin, double pu, double T, double mutot, double theta_sq);

//auxiliary function used for distribution functions
int statistics(double spin);

//integrates the thermal spectrum of "particle"
void spectrum_rapidity(double pT, double phi, double y_rap, pdg_particle particle, vector<element> &freeze_out_sup, ofstream &fileout);

//Gets feed down polarization interpolating from tables
void Lambda_polarization_FeedDown(double pT, double phi, double y_rap, pdg_particle mother, 
    interpolator &spectrum_interpolator, array<interpolator,4> &S_vorticity_interpolator, array<interpolator,4> &S_shear_interpolator, ofstream &fileout);

//prints components of polarization coming from different hydro gradients
void polarization_components(pdg_particle particle, 
        std::array<vector<element>,5> components, std::array<string,5> fileout_list);

// DEPRECATED void Lambda_FeedDown_nointerpolation(double pT, double phi, double y_rap, pdg_particle mother, 
//     vector<element> &freeze_out_sup, ofstream &fileout);

#endif
