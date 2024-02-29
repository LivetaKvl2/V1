#include <vector>
#include <string>
#include <iostream>
#include <ostream>

struct mok {
    std::string var, pav;
    std::vector<int> nd;
    int eg;
    double gal_vid, gal_med;
};

void ivedimas(std::vector<mok>& stud);
void calculateResults(std::vector<mok>& stud);
void isvedimas(std::vector<mok>& stud, std::ostream& os);
void meniu();
void meniuAntras();
bool pagalVarda(const mok& a, const mok& b);
bool pagalPavarde(const mok& a, const mok& b);
bool pagalMediana(const mok& a, const mok& b);
bool pagalVidurki(const mok& a, const mok& b);