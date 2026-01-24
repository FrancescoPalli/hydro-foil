#ifndef SURFACE_H
#define SURFACE_H

#include <vector>
#include <iostream>
#include <array>

//meant to read a the beta.dat file from the output of vhlle (polarization branches)

struct element {
    double tau=0, x=0, y=0, eta=0;
    std::array<double,4> u={0};
    std::array<double,4> dsigma={0};
    double T=0, mub=0, muq=0, mus=0; //GeV
    std::array<std::array<double,4>,4> dbeta={0};
    // element() : u(4, 0), dsigma(4, 0), dbeta(4, std::array<double>(4, 0)){};
    void print();
};

void read_hypersrface(std::string filename, std::vector<element> &hypersurface);

// Takes a cell of the freezout hypersup and kill the partialT part of the gradients
element iso_cell (const element& cell);

// Takes the freezout hypersup and makes the gradients iso-thermal
void iso_sup (std::vector<element>& hypersup);

element new_dbeta(element surf_old, int tag);
std::array<std::vector<element>,5> components_freeze_out(std::vector<element> &freeze_out_sup);

#endif