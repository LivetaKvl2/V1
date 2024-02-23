#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>

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
int main(){
    int Pasirinkimas, n, b, sum;
    vector<mok> studentai;
    double med;
    char a;

    string vardai[] = {"Liveta", "Roberta", "Paulina", "Ugne", "Gabriele", "Kamile", "Marija", "Rugile", "Jovita", "Adriana"};
    string pavardes[] = {"Kavaliauskaite", "Jurpalyte", "Podgaiska", "Mockute", "Vaitiekute", "Zobelaite", "Zubareva", "Macaite", "Vencauskaite", "Sirokyte"};

    srand(time(NULL));

    cout << "Jei norite duomenis ivesti ranka, iveskite 1, jei norite, kad duomenys butu nuskaityti is failo, iveskite 2" << endl;
    cin >> b;
    while ( !(b == 1 || b == 2)){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> b;
    }
if (b==1){

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
                isvedimas(studentai, cout);
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
            isvedimas(studentai, cout);
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
            isvedimas(studentai, cout);
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

}else {
    ifstream file;
    file.open("kursiokai.txt");
    if (!file){
        cout << "Nepavyko atidaryti failo." << endl;
    }
    string line;
    getline(file, line);

    int pazymys;
    while (getline(file, line)) {
       // cout << line << endl;
       mok naujasStud;
       istringstream iss(line);
       iss >> naujasStud.var >> naujasStud.pav;
       while (iss >> pazymys){
        naujasStud.nd.push_back(pazymys);
       }
        naujasStud.eg = naujasStud.nd.back();
        naujasStud.nd.pop_back();

       studentai.push_back(naujasStud);
    }
    calculateResults(studentai);
cout << "jei norite, kad duomenys butu isvesti ekrane, iveskite 1, jei i faila, iveskite 2" << endl;
    int c;
    cin >> c;
    while ( !(c == 1 || c == 2)){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> c;
    }if (c==1){
        meniuAntras();
        int antrasPasirinkimas;
        cin >> antrasPasirinkimas;
            switch (antrasPasirinkimas){
            case 1:
                {
                    sort(studentai.begin(), studentai.end(), pagalVarda);
                    break;
                }
            case 2:
                {
                    sort(studentai.begin(), studentai.end(), pagalPavarde);
                    break;
                }
            case 3:
                {
                    sort(studentai.begin(), studentai.end(), pagalVidurki);
                    break;
                }
            case 4:
                {
                    sort(studentai.begin(), studentai.end(), pagalMediana);
                    break;
                }
            }
            isvedimas(studentai, cout);
            return 0;
            }else {
        ofstream out ("isvedimas.txt");
        if (!out)
        cout << "Nepavyko atidaryti failo išvedimui." << endl;
        meniuAntras();
        int antrasPasirinkimas;
        cin >> antrasPasirinkimas;
            switch (antrasPasirinkimas){
                case 1:
                {
                    sort(studentai.begin(), studentai.end(), pagalVarda);
                    isvedimas(studentai, out);
                    break;
                }
            case 2:
                {
                    sort(studentai.begin(), studentai.end(), pagalPavarde);
                    isvedimas(studentai, out);
                    break;
                }
            case 3:
                {
                    sort(studentai.begin(), studentai.end(), pagalVidurki);
                    isvedimas(studentai, out);
                    break;
                }
            case 4:
                {
                    sort(studentai.begin(), studentai.end(), pagalMediana);
                    isvedimas(studentai, out);
                    break;
                }
            }
            out.close();

                }
            }
}
