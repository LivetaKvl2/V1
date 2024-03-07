#include "studentai.h"

void ivedimas (vector<mok>& stud) {
    mok naujas_stud;
    cout << "Iveskite studento varda ir pavarde:" << endl;
    cin >> naujas_stud.var >> naujas_stud.pav;
    int pazymys;
    cout << "Iveskite studento tarpinius namu darbu rezultatus(noredami uzbaigti, iveskite neigiama skaiciu):" << endl;
    while (true) {
        cin >> pazymys;
        if (cin.fail() || pazymys > 10 || pazymys == 0) {
            cin.clear();
            cin.ignore();
            cout << "Netinkamas formatas, bandykite dar karta" << endl;
            continue;
        }

        if (pazymys < 0) {
                break;
        }
        naujas_stud.nd.push_back(pazymys);
    }
    try {
        if (naujas_stud.nd.empty()) {
            throw runtime_error("Neivestas nei vienas pazymys.");
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        exit(1);
    }
    cout << "Iveskite studento egzamino rezultata:" << endl;
    while (!(cin >> naujas_stud.eg) || naujas_stud.eg < 1 || naujas_stud.eg > 10){
        cout << "Netinkamas formatas, bandykite dar karta" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
   
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

char rikiavimoklausimas(){
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite V" << endl;
    cout << "mediana - iveskite M"<< endl;
    char a;
    while (!(cin >> a) || (a != 'V' && a != 'v' && a != 'M' && a != 'm' )){
        cout << "Netinkama ivestis, bandykite dar karta" << endl;
        cin.clear();
        cin.ignore();
    }
    return a;
}
void isvedimas(vector<mok>& stud, ostream& os, char a){
    
    if (a == 'V' || a == 'v'){
            os << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
            os << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            os << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_vid << endl;
        }
    } if ( a== 'M' || a == 'm'){
            os << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) <<  "Galutinis (Med.)" << endl;
            os << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            os << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_med << endl;
        }
        }
        }

void meniuAntras(int& antrasPasirinkimas){
    cout << "jei norite, kad duomenys butu isrikiuoti pagal:" << endl;
    cout << "varda - iveskite 1" << endl;
    cout << "pavarde - iveskite 2" << endl;
    cout << "vidurki - iveskite 3" << endl;
    cout << "mediana - iveskite 4" << endl;
    while (!(cin >> antrasPasirinkimas) || antrasPasirinkimas < 1 || antrasPasirinkimas > 4){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    }

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

milliseconds trukmesSkaiciavimas(high_resolution_clock::time_point pradzia,high_resolution_clock::time_point pabaiga) {
    auto trukme = duration_cast<milliseconds>(pabaiga - pradzia);
    return trukme;
}

void failuGeneravimas(int studentuKiekis, const string& failoPavadinimas){
    ofstream generate (failoPavadinimas);
    if (!generate)
        cout << "Nepavyko sugeneruoti failo." << endl;
    generate << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(5) << "ND1" << left << setw(5) << "ND2"<< left << setw(5) << "ND3"<<
    left << setw(5) << "ND4"<< left << setw(5) << "ND5"<< left << setw(5) << "ND6"<< left << setw(5) << "ND7"<< left << setw(5) << "ND8"<< left << setw(5) << "ND9"<< left << setw(5) << "ND10" << endl;
    for (int i = 0; i < studentuKiekis; i++){
        generate << left << setw(6) << "Vardas" << left << setw(14)<< i + 1 << left << setw(7) << "Pavarde" << left << setw(13) << i + 1;
        for (int j = 0; j < 10; j++){
            int rand_paz = rand() % 10 + 1;
            generate << left << setw(5) << rand_paz;
        } 
        generate << endl;
    }
    generate.close();
}

void konteineriai(int studentuKiekis, vector<mok>& studentai, char a, vector<mok>& vargsiukai, vector<mok>& kietiakai){
                        
            if (a == 'M' || a =='m'){
                for (int i = 0; i < studentuKiekis; i++){
                if (studentai[i].gal_med < 5){
                        vargsiukai.push_back(studentai[i]);
                }else{
                    kietiakai.push_back(studentai[i]);
                }
            }   
            }else{
                for (int i = 0; i < studentuKiekis; i++){
                if (studentai[i].gal_vid < 5){
                        vargsiukai.push_back(studentai[i]);
                }else{
                    kietiakai.push_back(studentai[i]);
                }
                }
            }
            
}
