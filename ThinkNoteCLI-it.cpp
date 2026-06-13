#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string scelta;

    cout << "Benvenuto in ThinkNoteCLI. Ora stai scrivendo una nuova nota, e per salvarla ti basterà premere invio\n";
    getline(cin, scelta);

    ofstream fileOut("nota.txt");
    if (!fileOut) {
        cerr << "Errore nell'apertura del file in scrittura." << endl;
        return 1;
    }
    fileOut << scelta << '\n';
    fileOut.close();

    ifstream fileIn("nota.txt");
    if (!fileIn) {
        cerr << "Errore nell'apertura del file in lettura." << endl;
        return 1;
    }

    return 0;
}