#include "studentai.h"

void ivedimas (vector<mok>& stud) {
    mok naujas_stud;
    cout << "Iveskite studento varda ir pavarde:" << endl;
    cin >> naujas_stud.var >> naujas_stud.pav;
    int pazymys;
    cout << "Iveskite studento tarpinius namu darbu rezultatus(noredami uzbaigti, iveskite neigiama skaiciu):" << endl;
    while (cin >> pazymys) {
            if (pazymys < 0) {
                break;
            }
        naujas_stud.nd.push_back(pazymys);
    }
    cout << "Iveskite studento egzamino rezultata:" << endl;
    cin >> naujas_stud.eg;
    stud.push_back(naujas_stud);
}

void meniu (){
    cout << "Pasirinkite" << endl;
    cout << "1. Ivesti studentu duomenis ranka."<< endl;
    cout << "2. Pazymius sugeneruoti automatiskai." << endl;
    cout << "3. Automatiskai sugeneruoti ir pazymius, ir studentu vardus, pavardes." << endl;
    cout << "4. Baigti darba." << endl;
}

void calculateResults(vector<mok>& stud) {

    for (int i = 0; i < stud.size(); i++) {
        double sum = accumulate(stud[i].nd.begin(), stud[i].nd.end(), 0.0);
        double vid = sum / stud[i].nd.size();
        stud[i].gal_vid = (0.4 * vid + 0.6 * stud[i].eg);
        sort(stud[i].nd.begin(), stud[i].nd.end());
        if (stud[i].nd.size() % 2 == 0) {
            stud[i].gal_med = ((stud[i].nd[stud[i].nd.size() / 2 - 1] + stud[i].nd[stud[i].nd.size() / 2]) / 2.0 * 0.4) + 0.6 * stud[i].eg;
        } else {
            stud[i].gal_med = (stud[i].nd[stud[i].nd.size() / 2] * 0.4) + (0.6 * stud[i].eg);
        }
    }
}

void isvedimas(vector<mok>& stud, ostream& os){
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite V" << endl;
    cout << "mediana - iveskite M"<< endl;
    char a;
    cin >> a;
    if (a == 'V'){
            os << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
            os << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            os << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_vid << endl;
        }
    } if ( a== 'M'){
            os << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) <<  "Galutinis (Med.)" << endl;
            os << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            os << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_med << endl;
        }
        }
        }

void meniuAntras(){
    cout << "jei norite, kad duomenys butu isrikiuoti pagal:" << endl;
    cout << "varda - iveskite 1" << endl;
    cout << "pavarde - iveskite 2" << endl;
    cout << "vidurki - iveskite 3" << endl;
    cout << "mediana - iveskite 4" << endl;}

bool pagalVarda(const mok& a, const mok& b){
    return stoi(a.var.substr(6,1))< stoi(b.var.substr(6,1));
}
bool pagalPavarde(const mok& a, const mok& b){
    return stoi(a.pav.substr(7,1)) < stoi (b.pav.substr(7,1));
}
bool pagalMediana(const mok& a, const mok& b){
    return a.gal_med < b.gal_med;
}
bool pagalVidurki(const mok& a, const mok& b){
    return a.gal_vid < b.gal_vid;
}

chrono::milliseconds trukmesSkaiciavimas(chrono::high_resolution_clock::time_point pradzia,chrono::high_resolution_clock::time_point pabaiga) {
    auto trukme = chrono::duration_cast<chrono::milliseconds>(pabaiga - pradzia);
    return trukme;
}