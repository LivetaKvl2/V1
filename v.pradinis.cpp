#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct mok {
string var, pav;
int* nd;
int eg;
int ndCount;
};
int n;

void ivedimas (mok* stud, int n) {
    cout << "Iveskite studento varda ir pavarde:" << endl;
    cin >> stud[n].var >> stud[n].pav;
    int pazymys;
    stud[n].ndCount = 0;
    stud[n].nd = nullptr;
    cout << "Iveskite studento tarpinius namu darbu rezultatus(noredami uzbaigti, iveskite neigiama skaiciu):" << endl;
    while (cin >> pazymys) {
            if (pazymys < 0) {
                break;
            }
        int* naujasMasyvas = new int[stud[n].ndCount + 1];
        for (int i = 0; i < stud[n].ndCount; i++) {
            naujasMasyvas[i] = stud[n].nd[i];
        }
        delete[] stud[n].nd;
        stud[n].nd = naujasMasyvas;
        stud[n].nd[stud[n].ndCount++] = pazymys;
    }
    cout << "Iveskite studento egzamino rezultata:" << endl;
    cin >> stud[n].eg;
}

void meniu (){
    cout << "Pasirinkite" << endl;
    cout << "1. Ivesti studentu duomenis ranka."<< endl;
    cout << "2. Pazymius sugeneruoti automatiskai." << endl;
    cout << "3. Automatiskai sugeneruoti ir pazymius, ir studentu vardus, pavardes." << endl;
    cout << "4. Baigti darba." << endl;
}

void isvedimas(mok* stud, double* gal_vid, double* gal_med){
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite V" << endl;
    cout << "mediana - iveskite M"<< endl;
    char a;
    cin >> a;
    if (a == 'V'){
            cout << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < n; i++){
            cout << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << gal_vid[i] << endl;
        }
    } if ( a== 'M'){
            cout << left << setw(20) <<"Pavarde" << setw(20) << "Vardas" << setw(20) <<  "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (int i = 0; i < n; i++){
            cout << left << setw(20) << stud[i].var << setw(20)<< stud[i].pav << setw(20) << fixed << setprecision(2) << gal_med[i] << endl;
        }
        }
        }

int main(){
    int Pasirinkimas;
    double *vid = new double[n];
    double *gal_vid = new double[n];
    double *gal_med = new double[n];
    int sum;
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
                    cout << "Noredami ivesti naujo studento duomenis, iveskite bet koki simboli, noredami uzbaigti, parasykite 'stop'" << endl;
                    string stop;
                    n=0;
                    mok* stud = nullptr;
                    while (cin >> stop && stop != "stop"){
                        n+=1;
                        mok* naujasMasyvas = new mok[n];
                        for (int i = 0; i < n - 1; i++) {
                            naujasMasyvas[i] = stud[i];
                            }

                        stud = naujasMasyvas;
                        ivedimas(stud, n-1);
                    }

                    for (int i = 0; i < n; i++) {
                        sum = 0;
                        for (int j = 0; j < stud[i].ndCount; j++) {
                            sum += stud[i].nd[j];
                            }
                    vid[i] = sum / stud[i].ndCount;
                    gal_vid[i] = 0.4 * vid[i] + 0.6 * stud[i].eg;
                    sort(stud[i].nd, stud[i].nd + stud[i].ndCount);
                    if (stud[i].ndCount % 2 == 1) {
                        med = stud[i].nd[stud[i].ndCount / 2];
                        } else {
                        med = (stud[i].nd[stud[i].ndCount / 2 - 1] + stud[i].nd[stud[i].ndCount / 2]) / 2;
                        }
                    gal_med[i] = 0.4 * med + 0.6 * stud[i].eg;
                    }
                    isvedimas(stud, gal_vid, gal_med);
                    delete[] stud;
            break;}
            case 2: {
                cout << "Iveskite studentu kieki:" << endl;
                cin >> n;
                delete[] vid;
                delete[] gal_vid;
                delete[] gal_med;
                vid = new double[n];
                gal_vid = new double[n];
                gal_med = new double[n];

                mok *stud = new mok[n];
                for (int i = 0; i < n; i++){
                    cout << "Iveskite studento varda ir pavarde:" << endl;
                    cin >> stud[i].var >> stud[i].pav;
                    int pazymys;
                    cout << "Kiek pazymiu norite, kad programa sugeneruotu?:" << endl;
                    cin >> pazymys;
                    stud[i].ndCount = pazymys;
                    stud[i].nd = new int[pazymys];
                    sum = 0;
                    int *paz = new int[pazymys];
                    for (int j = 0; j < pazymys; j++) {
                            stud[i].nd[j] = rand() % 10 + 1;
                            sum += stud[i].nd[j];
                            }
                    stud[i].eg = rand() % 10 + 1;
                    sort(stud[i].nd, stud[i].nd + pazymys);
                    vid[i] = sum / pazymys;
                    gal_vid[i] = 0.4 * vid[i] + 0.6 * stud[i].eg;
                    if (pazymys % 2 == 1) {
                        med = stud[i].nd[pazymys / 2];
                        } else {
                            med = (stud[i].nd[pazymys / 2 - 1] + stud[i].nd[pazymys / 2]) / 2;
                            }
                    gal_med[i] = 0.4 * med + 0.6 * stud[i].eg;
                }

                for (int i = 0; i < n; i++) {
                    delete[] stud[i].nd;
                }
                isvedimas(stud, gal_vid, gal_med);
                delete[] stud;
                break;

            }
            case 3:{ cout << "Iveskite studentu kieki:" << endl;
                cin >> n;
                delete[] vid;
                delete[] gal_vid;
                delete[] gal_med;
                vid = new double[n];
                gal_vid = new double[n];
                gal_med = new double[n];

                cout << "Kiek pazymiu norite, kad programa sugeneruotu kiekvienam studentui?:" << endl;
                int pazymys;
                cin >> pazymys;
                mok *stud = new mok[n];
                for (int i = 0; i < n; i++){
                    stud[i].ndCount = pazymys;
                    stud[i].nd = new int[pazymys];
                    sum=0;
                    int *paz = new int[pazymys];
                    int random_vardas = rand() % 10;
                    int random_pavarde = rand() % 10;
                    stud[i].var = vardai[random_vardas];
                    stud[i].pav = pavardes[random_pavarde];
                    for (int j = 0; j < pazymys; j++) {
                            stud[i].nd[j] = rand() % 10 + 1;
                            sum += stud[i].nd[j];
                            }
                    sort(stud[i].nd, stud[i].nd + pazymys);
                    vid[i] = sum / pazymys;
                    stud[i].eg = rand() % 10 + 1;
                    gal_vid[i] = 0.4 * vid[i] + 0.6 * stud[i].eg;
                    if (pazymys % 2 == 1) {
                        med = stud[i].nd[pazymys / 2];
                        } else {
                            med = (stud[i].nd[pazymys / 2 - 1] + stud[i].nd[pazymys / 2]) / 2;
                            }
                    gal_med[i] = 0.4 * med + 0.6 * stud[i].eg;
                }

                for (int i = 0; i < n; i++) {
                    delete[] stud[i].nd;
                }
                isvedimas(stud, gal_vid, gal_med);
                delete[] stud;
                break;
            }
            case 4:{
                cout << "Programa baigta." << endl;
                break;}
            default:{
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }
    }} while (Pasirinkimas != 4);

    delete[] vid;
    delete[] gal_vid;
    delete[] gal_med;
}
