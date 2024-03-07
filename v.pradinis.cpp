#include "studentai.h"

int main(){
    int Pasirinkimas, antrasPasirinkimas, n, b;
    vector<mok> studentai;
      
    string vardai[] = {"Liveta", "Roberta", "Paulina", "Ugne", "Gabriele", "Kamile", "Marija", "Rugile", "Jovita", "Adriana"};
    string pavardes[] = {"Kavaliauskaite", "Jurpalyte", "Podgaiska", "Mockute", "Vaitiekute", "Zobelaite", "Zubareva", "Macaite", "Vencauskaite", "Sirokyte"};

    srand(time(NULL));
//PASIRINKIMAS, AR DUOMENYS IVEDAMI RANKA, AR NUSKAITOMI IS FAILO
    cout << "Jei norite duomenis ivesti ranka, iveskite 1, jei norite, kad duomenys butu nuskaityti is failo, iveskite 2" << endl;
    cin >> b;
    while ( !(b == 1 || b == 2)){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> b;
    }
//JEI NORIMA DUOMENIS IVESTI RANKA
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
            case 1:{ //NEZINOMAS KIEKIS STUDENTU IR PAZYMIU
                cout << "Noredami ivesti naujo studento duomenis, iveskite bet kokia raide. Noredami uzbaigti iveskite 'stop'" << endl;
                string a;
                while (cin >> a && a !="stop"){
                    ivedimas(studentai);
                }
                calculateResults(studentai);
                isvedimas(studentai, cout, rikiavimoklausimas());
            break;}
            case 2: { //GENERUOJAMI PAZYMIAI
                cout << "Iveskite studentu kieki: " << endl;
                while (!(cin >> n) || n < 1){
                    cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                    cin.clear();
                    cin.ignore();
                };
                mok naujasStud;
                for (int i = 0; i < n; i++) {
                    cout << "Iveskite studento varda ir pavarde: " << endl;
                    cin >> naujasStud.var >> naujasStud.pav;
                    int pazymys;
                    cout << "Kiek pazymiu norite, kad programa sugeneruotu?: " << endl;
                    while (!(cin >> pazymys) || pazymys < 1){
                        cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                        cin.clear();
                        cin.ignore();
                    };
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
            isvedimas(studentai, cout, rikiavimoklausimas());
            break;
            }
            case 3: { //GENERUOJAMI IR VARDAI IR PAZYMIAI
                cout << "Iveskite studentu kieki:" << endl;
                while (!(cin >> n) || n < 1){
                    cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                    cin.clear();
                    cin.ignore();
                };
                cout << "Kiek pazymiu norite, kad programa sugeneruotu kiekvienam studentui?" << endl;
                int pazymys;
                while (!(cin >> pazymys) || pazymys < 1){
                        cout << "Neteisinga ivestis, bandykite dar karta" << endl;
                        cin.clear();
                        cin.ignore();
                    };
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
            isvedimas(studentai, cout, rikiavimoklausimas());
            break;
            }
            case 4:{
                cout << "Programa baigta." << endl;
                break;}
            default:{
                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            }
        }
    }while (Pasirinkimas !=4);
     //TRINAMI VEKTORIAI
    isvalymas(studentai);
}else { //NORIMA DUOMENIS SKAITYTI IS FAILO
// FAILU GENERAVIMAS
/*
    cout << "Kiek studentu norite, kad programa sugeneruotu?" << endl;
    int studentuKiekis;
    cin >> studentuKiekis;
    stringstream failoPavadinimas;
    failoPavadinimas << "studentai" << studentuKiekis << ".txt";
    auto failoGeneravimoPradzia = high_resolution_clock::now();
    failuGeneravimas(studentuKiekis, failoPavadinimas.str());
    auto failoGeneravimoPabaiga = high_resolution_clock::now();
    */
// FAILAS JAU EGZISTUOJA (TYRIMUI)

    int studentuKiekis = 1000;
    stringstream failoPavadinimas;
    failoPavadinimas << "studentai" << studentuKiekis << ".txt";
    
//NUSKAITYMAS IS FAILO  
    ifstream file;
    file.open (failoPavadinimas.str());
    if (!file){
        cout << "Nepavyko atidaryti failo." << endl;
        exit(EXIT_FAILURE);
    }
    string line;
    auto nuskaitymoPradzia = high_resolution_clock::now();
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
    //NUSKAITYMAS IS FAILO BAIGTAS
    auto nuskaitymoPabaiga = high_resolution_clock::now();
    auto skaicPradzia = high_resolution_clock::now();
    calculateResults(studentai);
    auto skaicPabaiga = high_resolution_clock::now();
    //PASIRINKIMAS, AR NORIMA, KAD DUOMENYS BUTU ISVESTI I EKRANA AR I FAILA
    cout << "jei norite, kad duomenys butu isvesti ekrane, iveskite 1, jei i faila, iveskite 2" << endl;
    int c;
    cin >> c;
    while ( !(c == 1 || c == 2)){
        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        cin.clear();
        cin.ignore();
        cin >> c;
    }
    if (c==1){ //NORIMA, KAD DUOMENYS BUTU ISVESTI EKRANE
        meniuAntras(antrasPasirinkimas);
        auto rikiavimoPradzia = high_resolution_clock::now();
            switch (antrasPasirinkimas){//RIKIAVIMAS
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
            auto rikiavimoPabaiga = high_resolution_clock::now();
            //RIKIAVIMO PABAIGA
            //KONTEINERIU KURIMAS
            vector<mok> vargsiukai;
            vector<mok> kietiakai;
            char kl = rikiavimoklausimas();  
            auto rusiavimoPradzia = high_resolution_clock::now();
            konteineriai(studentuKiekis, studentai, kl, vargsiukai, kietiakai);
            auto rusiavimoPabaiga = high_resolution_clock::now();
            //ISVEDIMAS I EKRANA
            auto isvedimoPradzia = high_resolution_clock::now();
            cout << "VARGSIUKAI:" << endl;   
            isvedimas(vargsiukai, cout, kl);
            cout << "KIETIAKAI: " << endl;
            isvedimas(kietiakai, cout, kl);
            auto isvedimoPabaiga = high_resolution_clock::now();
            cout << "Nuskaitymas truko: "<< trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms"<< endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            cout << "Rusiavimas i konteinerius truko: " << trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() << " ms" << endl;
            cout << "Isvedimas truko: " << trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << " ms" << endl;
            }else {//NORIMA, KAD DUOMENYS BUTU ISVESTI I FAILUS
        //SUKURIAMI FAILAI ISVEDIMUI
        ofstream out1 ("Vargsiukai.txt");
        if (!out1)
        cout << "Nepavyko atidaryti failo isvedimui." << endl;
        ofstream out2 ("Kietiakai.txt");
        if (!out2)
        cout << "Nepavyko atidaryti failo isvedimui." << endl;
            auto rikiavimoPradzia = high_resolution_clock::now();
            meniuAntras(antrasPasirinkimas);
            switch (antrasPasirinkimas){//RIKIAVIMAS
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
            //RIKIAVIMAS BAIGTAS
            auto rikiavimoPabaiga = high_resolution_clock::now();
            //KONTEINERIU KURIMAS
            vector<mok> vargsiukai;
            vector<mok> kietiakai;
            char kl= rikiavimoklausimas();  
            auto rusiavimoPradzia = high_resolution_clock::now();
            konteineriai(studentuKiekis, studentai, kl, vargsiukai, kietiakai);
            auto rusiavimoPabaiga = high_resolution_clock::now();
            //ISVEDIMAS
            auto isvedimoPradzia = high_resolution_clock::now();
            isvedimas(vargsiukai, out1, kl);
            isvedimas(kietiakai, out2, kl);
            auto isvedimoPabaiga = high_resolution_clock::now();
            //cout << "Failo su " << studentuKiekis << "studentu generavimas truko: " << trukmesSkaiciavimas(failoGeneravimoPradzia, failoGeneravimoPabaiga).count() << " ms" << endl;
            cout << "Nuskaitymas truko: "<< trukmesSkaiciavimas(nuskaitymoPradzia, nuskaitymoPabaiga).count() << " ms"<< endl;
            cout << "Skaiciavimas truko: " << trukmesSkaiciavimas(skaicPradzia, skaicPabaiga).count() << " ms" << endl;
            cout << "Rikiavimas truko: " << trukmesSkaiciavimas(rikiavimoPradzia, rikiavimoPabaiga).count() << " ms" << endl;
            cout << "Rusiavimas i konteinerius truko: " << trukmesSkaiciavimas(rusiavimoPradzia, rusiavimoPabaiga).count() << " ms" << endl;
            cout << "Isvedimas truko: " << trukmesSkaiciavimas(isvedimoPradzia, isvedimoPabaiga).count() << " ms" << endl;
            out1.close();
            out2.close();
            isvalymas(vargsiukai);
            isvalymas(kietiakai);
            isvalymas(studentai);
                }               
     }
     
}
