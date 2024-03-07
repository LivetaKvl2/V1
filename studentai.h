#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std :: chrono;

struct mok {
    string var, pav;
    vector<int> nd;
    int eg;
    double gal_vid, gal_med;
};

void ivedimas(vector<mok>& stud);
void calculateResults(vector<mok>& stud);
char rikiavimoklausimas();
void isvedimas(vector<mok>& stud, ostream& os, char a);
void meniu();
void meniuAntras(int& antrasPasirinkimas);
bool pagalVarda(const mok& a, const mok& b);
bool pagalPavarde(const mok& a, const mok& b);
bool pagalMediana(const mok& a, const mok& b);
bool pagalVidurki(const mok& a, const mok& b);
std::chrono::milliseconds trukmesSkaiciavimas(std::chrono::high_resolution_clock::time_point pradzia, std::chrono::high_resolution_clock::time_point pabaiga);
