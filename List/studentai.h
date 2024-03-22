#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <ctime>
#include "fstream"
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <list>

using namespace std;
using namespace std::chrono;

struct mok {
    string var, pav;
    list<int> nd;
    int eg;
    double gal_vid, gal_med;
};

void ivedimas(list<mok>& stud);
void calculateResults(list<mok>& stud);
char rikiavimoklausimas();
void isvedimas(list<mok>& stud, ostream& os, char a);
void meniu(int& antrasPasirinkimas);
void meniuAntras(int& ketvirtasPasirinkimas);
bool pagalVarda(const mok& a, const mok& b);
bool pagalPavarde(const mok& a, const mok& b);
bool pagalMediana(const mok& a, const mok& b);
bool pagalVidurki(const mok& a, const mok& b);
milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga);
void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas);
void konteineriai(int studentuKiekis, list<mok>& studentai, char a, list<mok>& vargsiukai, list<mok>& kietiakai);
void isvalymas(list<mok>& vektorius);
void failuNuskaitymas(list<mok>& studentai, string& failoPavadinimas);
int pirmasP(int& pirmasPasirinkimas);
int treciasP(int& treciasPasirinkimas);
void rikiavimas(const int ketvirtaspasirinkimas, list<mok>& studentai)
