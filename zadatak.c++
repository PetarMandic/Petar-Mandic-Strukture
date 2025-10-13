#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string prezime;
    double bodovi;
};

int main() {
    ifstream dat("studenti.txt");
    if (!dat) {
        cout << "Greska: datoteka se ne moze otvoriti!" << endl;
        return 1;
    }

    int brojStudenata;
    dat >> brojStudenata;

    Student* studenti = new Student[brojStudenata];

    for (int i = 0; i < brojStudenata; i++) {
        dat >> studenti[i].ime >> studenti[i].prezime >> studenti[i].bodovi;
    }

    dat.close();

    double maxBodovi = studenti[0].bodovi;
    for (int i = 1; i < brojStudenata; i++) {
        if (studenti[i].bodovi > maxBodovi)
            maxBodovi = studenti[i].bodovi;
    }

    cout << "\nRezultati studenata:\n";
    cout << "--------------------------------------------\n";
    cout << "Ime\t\tPrezime\t\tAps. bodovi\tRel. bodovi (%)\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < brojStudenata; i++) {
        double relativni = (studenti[i].bodovi / maxBodovi) * 100.0;
        cout << studenti[i].ime << "\t\t" 
             << studenti[i].prezime << "\t\t" 
             << studenti[i].bodovi << "\t\t" 
             << relativni << endl;
    }

    delete[] studenti;
    return 0;
}
