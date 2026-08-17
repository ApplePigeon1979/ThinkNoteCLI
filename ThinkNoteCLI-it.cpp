#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nota, scelta, filename, scelta2;
    cout << "Benvenuto in ThinkNoteCLI. Scegli una delle 2 opzioni.\n";
    cout << "1. Scrivi una nuova nota.\n";
    cout << "2. Apri una nota già esistente.\n";
    cout << "3. Informazioni.\n";
    getline(cin, scelta);

    if (scelta == "1") {
        cout << "Nome file (es. nota.txt): ";
        getline(cin, filename);
        ifstream check(filename);
        if (check) {
            check.close();
            cout << "Il file \"" << filename << "\" esiste già. Vuoi (s)ovrascrivere, (a)ppendere o (c)ancella? [s/a/c]: ";
            string opt; getline(cin, opt);
            if (opt == "c" || opt == "C") {
                cout << "Operazione annullata.\n";
                return 0;
            }
            ios_base::openmode mode = (opt == "a" || opt == "A") ? ios::app : ios::trunc;
            cout << "Scrivi la nota (premi invio per salvare):\n";
            getline(cin, nota);
            ofstream fileOut(filename, mode);
            if (!fileOut) { cerr << "Errore apertura file in scrittura.\n"; return 1; }
            fileOut << nota << '\n';
            cout << "Nota salvata in " << filename << '\n';
            return 0;
        } else {
            cout << "Scrivi la nota (premi invio per salvare):\n";
            getline(cin, nota);
            ofstream fileOut(filename);
            if (!fileOut) { cerr << "Errore apertura file in scrittura.\n"; return 1; }
            fileOut << nota << '\n';
            cout << "Nota salvata in " << filename << '\n';
            return 0;
        }
    } else if (scelta == "2") {
         cout << "Nome file da aprire (es. nota.txt): ";
        getline(cin, filename);

        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cout << "Impossibile aprire il file.\n";
            return 0;
        }

        cout << "---- Contenuto di " << filename << " ----\n";
        string line;
        while (getline(fileIn, line)) {
            cout << line << '\n';
        }
        cout << "------------------------------------------\n";

        fileIn.close();

        cout << "Desideri modificare la nota? (S/N)\n";
        getline(cin, scelta2);
        if (scelta2 == "S") {
            cout << "Ora puoi scrivere la nuova nota (sovrascrivendo quella precedente):\n";
            getline(cin, nota);

            ofstream fileOut(filename, ios::trunc); 
            if (!fileOut) {
                cerr << "Errore apertura file in scrittura. Assicurati di aver i permessi necessari per modificare la nota.\n";
                return 1;
            }
            fileOut << nota << '\n';
            cout << "File modificato: " << filename << '\n';
            return 0;
        }
        if (scelta2 == "N") {
            return 0;
        }
    } else if (scelta == "3") {
        cout << "ThinkNoteCLI è un programma per poter scrivere note. Esso è (ovviamente) gratis, open-source e inventato in Italia.\n";
    }
     else {
        cout << "Opzione non valida.\n";
    }
    return 0;
}
