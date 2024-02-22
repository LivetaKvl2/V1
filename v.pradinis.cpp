#include <iostream>
#include <iomanip>

using namespace std;

struct mok {
    string var, pav;
    int nd[10], eg;
};

int main() {
    int n;
    cout << "Kiek is viso yra studentu?" << endl;
    cin >> n;
    mok* stud = new mok[n];
    for (int i = 0; i < n; i++) {
        cout << "iveskite studento varda ir pavarde" << endl;
        cin >> stud[i].var >> stud[i].pav;
        cout << "iveskite 10 namu darbu tarpiniu rezultatu" << endl;
        for (int j = 0; j < 10; j++) {
            cin >> stud[i].nd[j];
        }
        cout << "iveskite egzamino rezultata" << endl;
        cin >> stud[i].eg;
    };
    double* vid = new double[n];
    double* gal_vid = new double[n];
    double* gal_med = new double[n];
    int sum;
    int med;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += stud[i].nd[j];
        }
        vid[i] = sum / 10;
        gal_vid[i] = 0.4 * vid[i] + 0.6 * stud[i].eg;
    };
    for (int i = 0; i < n; i++) {
        med = 0;
        for (int j = 0; j < 10; j++) {
            if (stud[i].nd[j] > stud[i].nd[j + 1]) {
                double k = stud[i].nd[j];
                stud[i].nd[j] = stud[i].nd[j + 1];
                stud[i].nd[j + 1] = k;


            }
            med = (stud[i].nd[4] + stud[i].nd[5]) / 2;
            gal_med[i] = 0.4 * med + 0.6 * stud[i].eg;

        }
    };
    int a;
    cout << "Jei norite matyti galutini rezultata apskaiciuota pagal:" << endl;
    cout << "vidurki - iveskite vieneta" << endl;
    cout << "mediana - iveskite dvejeta" << endl;
    cin >> a;
    if (a == 1) {
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << stud[i].var << setw(20) << stud[i].pav << setw(20) << fixed << setprecision(2) << gal_vid[i] << endl;
        }
    } if (a == 2) {
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << stud[i].var << setw(20) << stud[i].pav << setw(20) << fixed << setprecision(2) << gal_med[i] << endl;
        }
    };

    delete[] stud;
    delete[] vid;
    delete[] gal_vid;
};
