#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

struct mok {
string var, pav;
vector<int> nd;
int eg;
double gal_vid, gal_med;
};

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
void isvedimas(vector<mok>& stud){
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite V" << endl;
    cout << "mediana - iveskite M"<< endl;
    char a;
    cin >> a;
    if (a == 'V'){
            cout << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            cout << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_vid << endl;
        }
    } if ( a== 'M'){
            cout << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) <<  "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < stud.size(); i++){
            cout << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << stud[i].gal_med << endl;
        }
        }
        }
int main(){
    int Pasirinkimas, n, sum;
    vector<mok> studentai;
    double med;
    char a;

    string vardai[] = {"Liveta", "Roberta", "Paulina", "Ugne", "Gabriele", "Kamile", "Marija", "Rugile", "Jovita", "Adriana"};
    string pavardes[] = {"Kavaliauskaite", "Jurpalyte", "Podgaiska", "Mockute", "Vaitiekute", "Zobelaite", "Zubareva", "Macaite", "Vencauskaite", "Sirokyte"};

    srand(time(NULL));
do {
        meniu();
        cout << "Jusu pasirinkimas: ";
        while (!(cin >> Pasirinkimas)){
            cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
            cin.clear();
            cin.ignore();
            meniu();
            cout << "Jusu pasirinkimas:";
        }
        switch (Pasirinkimas) {
            case 1:{
                cout << "Noredami ivesti naujo studento duomenis, spauskite bet kokia raide. Noredami uzbaigti iveskite 'stop'" << endl;
                string a;
                while (cin >> a && a !="stop"){
                    ivedimas(studentai);
                }
                calculateResults(studentai);
                isvedimas(studentai);
            break;}
            case 2: {
                cout << "Iveskite studentu kieki: " << endl;
                cin >> n;
                mok naujasStud;
                for (int i = 0; i < n; i++) {
                    cout << "Iveskite studento varda ir pavarde: " << endl;
                    cin >> naujasStud.var >> naujasStud.pav;
                    int pazymys;
                    cout << "Kiek pazymiu norite, kad programa sugeneruotu?: " << endl;
                    cin >> pazymys;
                    int sum = 0;
                    for (int j = 0; j < pazymys; j++) {
                        int rand_paz = rand() % 10 + 1;
                        naujasStud.nd.push_back(rand_paz);
                        sum += rand_paz;
                    }
                naujasStud.eg = rand() % 10 + 1;
                studentai.push_back(naujasStud);
                }

            calculateResults(studentai);
            isvedimas(studentai);
            break;
            }

            case 3: {
                cout << "Iveskite studentu kieki:" << endl;
                cin >> n;
                cout << "Kiek pazymiu norite, kad programa sugeneruotu kiekvienam studentui?:" << endl;
                int pazymys;
                cin >> pazymys;
                mok naujasStud;
                for (int i = 0; i < n; i++) {
                    naujasStud.var = vardai[rand() % (sizeof(vardai) / sizeof(vardai[0]))];
                    naujasStud.pav = pavardes[rand() % (sizeof(pavardes) / sizeof(pavardes[0]))];
                    double sum = 0;
                    for (int j = 0; j < pazymys; j++) {
                        int rand_paz = rand() % 10 + 1;
                        naujasStud.nd.push_back(rand_paz);
                        sum += rand_paz;
                    }
                naujasStud.eg = rand() % 10 + 1;
                studentai.push_back(naujasStud);
                }
            calculateResults(studentai);
            isvedimas(studentai);
            break;
            }

            case 4:{
                cout << "Programa baigta." << endl;
                break;}
            default:{
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }
     }
     int clearDydis = studentai.size();
     for (int i = 0; i < clearDydis; i++) {
     studentai[i].nd.clear();
     }
    studentai.clear();
     }while (Pasirinkimas != 4);

