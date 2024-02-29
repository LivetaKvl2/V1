#include "studentai.h"

int main(){
    int Pasirinkimas, n, b;
    vector<mok> studentai;
      
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
                cout << "Noredami ivesti naujo studento duomenis, iveskite bet kokia raide. Noredami uzbaigti iveskite 'stop'" << endl;
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
    file.open("studentai10000.txt");
    if (!file){
        cout << "Nepavyko atidaryti failo." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    auto nuskaitymoPradzia = chrono::high_resolution_clock::now();
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
    auto nuskaitymoPabaiga = chrono::high_resolution_clock::now();
    auto skaicPradzia = chrono::high_resolution_clock::now();
    calculateResults(studentai);
    auto skaicPabaiga = chrono::high_resolution_clock::now();
    cout << "jei norite, kad duomenys butu isvesti ekrane, iveskite 1, jei i faila, iveskite 2" << endl;
    int c;
    cin >> c;
    while ( !(c == 1 || c == 2)){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> c;
    }
    if (c==1){
        meniuAntras();
        int antrasPasirinkimas;
        cin >> antrasPasirinkimas;
        auto rikiavimoPradzia = chrono::high_resolution_clock::now();
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
            auto rikiavimoPabaiga = chrono::high_resolution_clock::now();
            isvedimas(studentai, cout);
            cout << "Nuskaitymas truko: "<< trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms"<< endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            return 0;
            }else {
        ofstream out ("kursiokai.txt");
        if (!out)
        cout << "Nepavyko atidaryti failo isvedimui." << endl;
        meniuAntras();
        int antrasPasirinkimas;
        cin >> antrasPasirinkimas;
            auto rikiavimoPradzia = chrono::high_resolution_clock::now();
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
            auto rikiavimoPabaiga = chrono::high_resolution_clock::now();
            isvedimas(studentai, out);
            cout << "Nuskaitymas truko: "<< trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms"<< endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            out.close();

                }
                return 0;
            }
}
