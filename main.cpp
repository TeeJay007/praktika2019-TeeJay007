#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

struct Ginklas{
    string pavadinimas;
    float galia;
    float kaina;
    bool uzdetas;
};

struct Zaidejas{
    string Vardas;
    float givybes;
    int lygis;
    int patirtis;
    float pinigai;
    vector<Ginklas> inventorius;
};

struct Priesas{
    string pavadinimas;
    float galia;
    float patirtis;
    float givybes;
};

struct Bosas{
    string pavadinimas;
    float galia;
    float givybes;
    bool nukautas;
};

Zaidejas Zaid;
vector<Ginklas> Ginklai;
vector<Priesas> Priesai;
vector<Bosas> Bosai;
vector<string> Pasiekimai;
bool pas[] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

int main();

void duomenuKrovimas(){
    ifstream f("ginklai.txt");
    int n;
    f >> n;
    Ginklas g;

    for(int i = 0; i < n; i++){
        f >> g.pavadinimas >> g.galia >> g.kaina;
        Ginklai.push_back(g);
    }
    f.close();

    ifstream fa("priesai.txt");
    fa >> n;
    Priesas p;

    for(int i = 0; i < n; i++){
        fa >> p.pavadinimas >> p.galia >> p.patirtis >> p.givybes;
        Priesai.push_back(p);
    }
    fa.close();

    ifstream fb("bosai.txt");
    fb >> n;
    Bosas b;

    for(int i = 0; i < n; i++){
        fb >> b.pavadinimas >> b.galia >> b.givybes;
        b.nukautas = false;
        Bosai.push_back(b);
    }
    fb.close();


    Zaid.givybes = 100;
    Zaid.lygis = 1;
    Zaid.patirtis = 0;
    Zaid.pinigai = 0;

    Zaid.inventorius.push_back(Ginklai.at(0));
    Zaid.inventorius.at(0).uzdetas = true;


    Pasiekimai.push_back("[Pasiekimas] Naujokas.");//
    Pasiekimai.push_back("[Pasiekimas] Pazenges.");//
    Pasiekimai.push_back("[Pasiekimas] Ekspertas.");//
    Pasiekimai.push_back("[Pasiekimas] Naujas zaidimas.");//
    Pasiekimai.push_back("[Pasiekimas] Inventorius.");//
    Pasiekimai.push_back("[Pasiekimas] Pirmoji pergale.");//
    Pasiekimai.push_back("[Pasiekimas] Bosu zudikas.");//
    Pasiekimai.push_back("[Pasiekimas] Kitas ginklas.");//
    Pasiekimai.push_back("[Pasiekimas] Naujas ginklas.");//
    Pasiekimai.push_back("[Pasiekimas] Daugiau givybiu.");//
    Pasiekimai.push_back("[Pasiekimas] Zaidimas laimetas.");//
    Pasiekimai.push_back("[Pasiekimas] Hud perziura.");//
    Pasiekimai.push_back("[Pasiekimas] Pasiekimai.");//
    Pasiekimai.push_back("[Pasiekimas] Sveiki atvyke.");//
    Pasiekimai.push_back("[Pasiekimas] Visi pasiekimai.");
}

void zaidejoHud(){
    pas[11] = true;
    if(Zaid.lygis > 2)
        pas[1] = true;
    if(Zaid.lygis > 3)
        pas[2] = true;

    pas[14] = true;
    for(int i = 0; i < 14; i++){
        if(pas[i] == false){
            pas[14] = false;
            break;
        }
    }

    while(Zaid.patirtis >= 100){
        Zaid.patirtis -= 100;
        Zaid.lygis++;
    }

    cout << "Givybes: " << Zaid.givybes << " ";
    cout << "Lygis: " << Zaid.lygis << " ";
    cout << "Patirtis: " << Zaid.patirtis << " ";
    cout << "Pinigai: " << Zaid.pinigai << " ";
    cout << endl;
}

void meniu(){
    cout << "1. Kovoti su priesais.\n";
    cout << "2. Kovoti su BOSU.\n";
    cout << "3. Inventorius.\n";
    cout << "4. Parduotuve.\n";
    cout << "5. Pasiekimai.\n";
    cout << "6. Html rezultatai.\n";
}

void inventorius(){
    system("clear");
    cout << "*------------------------------------------------------------*\n";
    cout << "|                        INVENTORIUS                         |\n";
    cout << "*------------------------------------------------------------*\n";
    cout << setw(1) << "|" << setw(15) << "Pavadinimas" << setw(15) << "Galia" << setw(15) << "Kaina" << setw(15) << "Uzdetas" << setw(1) << "|" << endl;
    cout << "*------------------------------------------------------------*\n";
    int i = 0;
    for (vector<Ginklas>::iterator it = Zaid.inventorius.begin(); it != Zaid.inventorius.end(); ++it){
        cout << setw(1) << "|" << setw(1) << i << setw(15) << it->pavadinimas << setw(15) << it->galia << setw(15) << it->kaina << setw(15) << ((it->uzdetas) ? "Taip" : "Ne") << setw(1) << "|" << endl;
        i++;
    }
    cout << "*------------------------------------------------------------*\n";
    cout << "1. Uzsideti ginkla.\n";
    cout << "2. Atgal.\n";
    cout << "Pasirinkite: ";
    int p;
    cin >> p;
    switch (p)
    {
        case 1:
            cout << "Iveskite ginklo numeri: ";
            cin >> p;
            for (vector<Ginklas>::iterator it = Zaid.inventorius.begin(); it != Zaid.inventorius.end(); ++it)
                it->uzdetas = false;
            Zaid.inventorius.at(p).uzdetas = true;
            cout << "Ginklas uzdetas. Spauskite enter norint sugristi.";
            pas[7] = true;
            cin.ignore();
            cin.get();
            return;
        break;
    }
}

void parduotuve(){
    system("clear");
    zaidejoHud();
    cout << "*----------------------------------------------*\n";
    cout << "|                   PARDUOTUVE                 |\n";
    cout << "*----------------------------------------------*\n";
    cout << setw(1) << "|" << setw(15) << "Pavadinimas" << setw(15) << "Galia" << setw(15) << "Kaina" << setw(2) << " |" << endl;
    cout << "*----------------------------------------------*\n";
    int i = 0;
    for (vector<Ginklas>::iterator it = Ginklai.begin(); it != Ginklai.end(); ++it){
        cout << setw(1) << "|" << setw(1) << i << setw(15) << it->pavadinimas << setw(15) << it->galia << setw(14) << it->kaina << setw(2) << " |" << endl;
        i++;
    }
    cout << "*----------------------------------------------*\n";
    cout << "1. Pirkti ginkla.\n";
    cout << "2. Atstatyti givybes. (1 Givybe - 1 Pinigas)\n";
    cout << "3. Atgal.\n";
    cout << "Pasirinkite: ";
    int p;
    cin >> p;
    switch (p)
    {
        case 1:
            cout << "Iveskite ginklo numeri: ";
            cin >> p;
            if(Zaid.pinigai >= Ginklai.at(p).kaina){
                Zaid.pinigai -= Ginklai.at(p).kaina;
                Zaid.inventorius.push_back(Ginklai.at(p));
                cout << "Ginklas sekmingai nupirktas. Spauskite enter norint sugristi.";
                pas[8] = true;
            }else{
                cout << "Nepakanka pinigu pasirinktam ginklui. Spauskite enter norint sugristi.";
            }
            cin.ignore();
            cin.get();
            return;
        break;
        case 2:
            if(Zaid.pinigai > 0){
                while(Zaid.givybes < 100 && Zaid.pinigai > 0){
                    Zaid.givybes++;
                    Zaid.pinigai--;
                }
                cout << "Givybes atstatytos. Spauskite enter norint sugristi.";
                pas[9] = true;
            }else{
                cout << "Nepakanka pinigu atstatyti givybems. Spauskite enter norint sugristi.";
            }
            cin.ignore();
            cin.get();
        break;
    }
}

void pasiekimai(){
    pas[12] = true;
    system("clear");
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "|                                         PASIEKIMAI                                        |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";
    int i = 0;
    for (vector<string>::iterator it = Pasiekimai.begin(); it != Pasiekimai.end(); ++it){
        cout << setw(1) << "|" << setw(40) << ((pas[i]) ? "Ivykdytas" : "Neivykdytas") << setw(3) << " | " << setw(47) << *it << setw(2) << " |\n";
        i++;
    }
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "Spauskite enter norint sugristi.";
    cin.ignore();
    cin.get();
}

int kovaPriesPriesus(){
    system("clear");
    cout << "*-------------------------------------------------------------*\n";
    cout << "*                       KOVOS LAUKAS                          *\n";
    cout << "*-------------------------------------------------------------*\n";
    cout << "1. Kovoti\n";
    int p;
    cin >> p;

    switch (p)
    {
    case 1:
        
        srand(time(NULL));
        int r = rand() % Priesai.size();
        Priesas pr = Priesai[r];
        Ginklas gi;

        for (vector<Ginklas>::iterator it = Zaid.inventorius.begin(); it != Zaid.inventorius.end(); ++it)
            if(it->uzdetas)
                gi = *it;

        cout << "Sutikai " << pr.pavadinimas << endl;
        while(pr.givybes > 0 && Zaid.givybes > 0){
            pr.givybes -= (gi.galia*(Zaid.patirtis+1));
            cout << "Jus trenkiate su ginklu " << gi.pavadinimas << " priesininkui " << pr.pavadinimas << " ir padarote " << (gi.galia*(Zaid.patirtis+1)) << " zalos.\n";

            if(pr.givybes > 0){
                Zaid.givybes -= pr.galia*(Zaid.patirtis+1);
                cout << "Jums trenkia " << pr.pavadinimas << " ir padaro " << pr.galia*(Zaid.patirtis+1) << "zalos.\n";
            }
        }

        if(pr.givybes <= 0 && Zaid.givybes > 0){
            Zaid.patirtis += pr.patirtis;
            Zaid.pinigai += pr.patirtis*Priesai[r].givybes;
            cout << "*-------------------------------------------------------------------------------------------*\n";
            zaidejoHud();
            cout << "*-------------------------------------------------------------------------------------------*\n";
            cout << "Jus laimite kova pries " << pr.pavadinimas << " ir igaunate " << pr.patirtis << " patirties, " << pr.patirtis*Priesai[r].givybes << " pinigu.\n";
            cout << "*-------------------------------------------------------------------------------------------*\n";
            pas[5] = true;
        }else{
            cout << "*-------------------------------------------------------------------------------------------*\n";
            cout << "Kova pralaimeta.\n";
            cout << "*-------------------------------------------------------------------------------------------*\n";
            return false;
        }

        cout << "Spauskite enter norint sugristi.";
        cin.ignore();
        cin.get();
        break;
    }
    return true;
}

int kovaPriesBosus(){
    system("clear");
    cout << "*-----------------------------------------------------------------*\n";
    cout << "*                             BOSAI                               *\n";
    cout << "*-----------------------------------------------------------------*\n";
    for (vector<Bosas>::iterator it = Bosai.begin(); it != Bosai.end(); ++it)
        cout << setw(1) << "|" << setw(20) << it->pavadinimas << setw(15) << it->galia << setw(15) << it->givybes << setw(15) << ((it->nukautas) ? "Taip" : "Ne") << setw(2) << " |" << endl;
    cout << "*-----------------------------------------------------------------*\n";
    cout << "1. Kovoti\n";
    cout << "2. Atgal\n";
    int p;
    cin >> p;
    switch (p)
    {
    case 1:
        if(Zaid.lygis > 0){
            Ginklas gi;
            for (vector<Ginklas>::iterator it = Zaid.inventorius.begin(); it != Zaid.inventorius.end(); ++it)
                if(it->uzdetas)
                    gi = *it;
            
            Bosas b;
            int i = 0;
            for (vector<Bosas>::iterator it = Bosai.begin(); it != Bosai.end(); ++it){
                if(!it->nukautas){
                    b = *it;
                    break;
                }
                i++;
            }

            while(b.givybes > 0 && Zaid.givybes > 0){
                b.givybes -= (gi.galia*(Zaid.lygis*100));
                cout << "Jus trenkiate su ginklu " << gi.pavadinimas << " priesininkui " << b.pavadinimas << " ir padarote " << (gi.galia*(Zaid.lygis*100)) << " zalos.\n";

                if(b.givybes > 0){
                    Zaid.givybes -= b.galia;
                    cout << "Jums trenkia " << b.pavadinimas << " ir padaro " << b.galia << "zalos.\n";
                }
            }

            if(b.givybes <= 0 && Zaid.givybes > 0){
                Zaid.patirtis += 100;
                Bosai.at(i).nukautas = true;
                cout << "*-------------------------------------------------------------------------------------------*\n";
                zaidejoHud();
                cout << "*-------------------------------------------------------------------------------------------*\n";
                cout << "Jus laimite kova pries " << b.pavadinimas << " ir igaunate " << 100 << " patirties.\n";
                cout << "*-------------------------------------------------------------------------------------------*\n";
                pas[6] = true;
            }else{
                cout << "*-------------------------------------------------------------------------------------------*\n";
                cout << "Kova pralaimeta.\n";
                cout << "*-------------------------------------------------------------------------------------------*\n";
                return false;
            }

            cout << "Spauskite enter norint sugristi.";
        }else{
            cout << "Dar kovoti negalite jusu patirtis per maza. Spauskite enter jei norite testi.";
        }
        cin.ignore();
        cin.get();
        break;
    }
    return true;
}

void eksportuotiIHtml(){
    string page = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><meta http-equiv='X-UA-Compatible' content='ie=edge'><title>Taskai</title><link href='style.css' rel='stylesheet' type='text/css'></head><body><table style='width:600px' align='center'><tr><th>Vardas</th><th>Taskai</th></tr>";

    ifstream rs("rez.txt");
    ofstream fv("scores.html");

    string d, c;
    fv << page;
    while(rs >> d){
        rs >> c;
        fv << "<tr><td>" << d << "</td><td>" << c << "</td></tr>";
    }
    rs.close();
    
    fv << "</table></body>";
    fv.close();

    cout << "Rezultatai sekmingai irasyti i scores.html. Spauskite enter norint sugristi.";
    cin.ignore();
    cin.get();
}

void zaidimoPabaiga(){
    system("clear");
    pas[10] = true;
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "|                            SVEIKINAME! Jus perejote zaidima.                              |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "|                VARDAS                   |                       TASKAI                    |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << setw(1) << "|" << setw(40) << Zaid.Vardas << setw(3) << " | " << setw(47) << (Zaid.givybes+1)*(Zaid.lygis+1)*(Zaid.patirtis+1)*(Zaid.pinigai+1) << setw(2) << " |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";

    ofstream rez;
    rez.open("rez.txt", std::ios_base::app);
    rez << Zaid.Vardas << " " << (Zaid.givybes+1)*(Zaid.lygis+1)*(Zaid.patirtis+1)*(Zaid.pinigai+1) << endl;
    rez.close();
}

void zaidimoPabaiga2(){
    system("clear");
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "|                            NEPASISEKE! Jus pralosete zaidima.                             |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << "|                VARDAS                   |                       TASKAI                    |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";
    cout << setw(1) << "|" << setw(40) << Zaid.Vardas << setw(3) << " | " << setw(47) << (Zaid.givybes+1)*(Zaid.lygis+1)*(Zaid.pinigai+1) << setw(2) << " |\n";
    cout << "*-------------------------------------------------------------------------------------------*\n";

    ofstream rez;
    rez.open("rez.txt", std::ios_base::app);
    rez << Zaid.Vardas << " " << (Zaid.givybes+1)*(Zaid.lygis+1)*(Zaid.pinigai+1) << endl;
    rez.close();
}

int main(){
    duomenuKrovimas();
    cout << "Iveskite zaidejo varda: ";
    getline(cin, Zaid.Vardas);

    pas[0] = true;
    pas[3] = true;
    pas[13] = true;

    while(true){
        int c;
        system("clear");
        zaidejoHud();
        meniu();
        cin >> c;
        switch(c){
            case 1:
                if(!kovaPriesPriesus()){
                    zaidimoPabaiga2();
                    return 0;
                }
            break;
            case 2:
                if(!kovaPriesBosus()){
                    zaidimoPabaiga2();
                    return 0;
                }
            break;
            case 3:
                pas[4] = true;
                inventorius();
            break;
            case 4:
                parduotuve();
            break;
            case 5:
                pasiekimai();
            break;
            case 6:
                eksportuotiIHtml();
            break;
            default:
            break;
        }

        bool visinukauti = true;
        for (vector<Bosas>::iterator it = Bosai.begin(); it != Bosai.end(); ++it){
            if(!it->nukautas){
                visinukauti = false;
                break;
            }
        }
        if(visinukauti){
            zaidimoPabaiga();
            return 0;
        }
    }
    return 0;
}
