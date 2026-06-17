#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nota, scelta, filename;
    cout << "Benvenuto in ThinkNoteCLI. Scegli una delle 2 opzioni.\n";
    cout << "1. Scrivi una nuova nota.\n";
    cout << "2. Apri una nota già esistente.\n";
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
        cout << "Nome file da aprire: ";
        getline(cin, filename);
        ifstream fileIn(filename);
        if (!fileIn) {
            cerr << "Errore: file non trovato o impossibile aprire.\n";
            return 1;
        }
        cout << "Contenuto di " << filename << ":\n";
        while (getline(fileIn, nota)) cout << nota << '\n';
        fileIn.close();
    } else {
        cout << "Opzione non valida.\n";
    }
    return 0;
}
