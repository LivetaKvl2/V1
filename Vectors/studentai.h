
#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include "fstream"
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <deque>

using namespace std;
using namespace std::chrono;

struct mok {
    string var, pav;
    deque<int> nd;
    int eg;
    double gal_vid, gal_med;
};

void ivedimas(deque<mok>& stud);
void calculateResults(deque<mok>& stud);
char rikiavimoklausimas();
void isvedimas(deque<mok>& stud, ostream& os, char a);
void meniu(int& antrasPasirinkimas);
void meniuAntras(int& ketvirtasPasirinkimas);
bool pagalVarda(const mok& a, const mok& b);
bool pagalPavarde(const mok& a, const mok& b);
bool pagalMediana(const mok& a, const mok& b);
bool pagalVidurki(const mok& a, const mok& b);
milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia, high_resolution_clock::time_point pabaiga);
void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas);
void konteineriai(int studentuKiekis, deque<mok>& studentai, char a, deque<mok>& vargsiukai, deque<mok>& kietiakai);
void isvalymas(deque<mok>& vektorius);
void failuNuskaitymas(deque<mok>& studentai, string& failoPavadinimas);
int pirmasP(int& pirmasPasirinkimas);
int treciasP(int& treciasPasirinkimas);
void rikiavimas(const int ketvirtaspasirinkimas, deque<mok>& studentai);
