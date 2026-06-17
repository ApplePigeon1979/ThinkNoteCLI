#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nota, scelta, filename;
    cout << "Welcome to ThinkNoteCLI. Choose one of the 2 options.\n";
    cout << "1. Write a new note\n";
    cout << "2. Open an already existing note.\n";
    getline(cin, scelta);

    if (scelta == "1") {
        cout << "Name of the file (es. note.txt): ";
        getline(cin, filename);
        ifstream check(filename);
        if (check) {
            check.close();
            cout << "The file \"" << filename << "\" is already existing. Do you want (o)verwrite, (h)ang or (d)elete? [o/h/d]: ";
            string opt; getline(cin, opt);
            if (opt == "d" || opt == "D") {
                cout << "Operation canceled.\n";
                return 0;
            }
            ios_base::openmode mode = (opt == "h" || opt == "H") ? ios::app : ios::trunc;
            cout << "Write the note (press enter for save):\n";
            getline(cin, nota);
            ofstream fileOut(filename, mode);
            if (!fileOut) { cerr << "Error in the opening the file in writing.\n"; return 1; }
            fileOut << nota << '\n';
            cout << "Note saved in " << filename << '\n';
            return 0;
        } else {
            cout << "Write the note (press enter for save):\n";
            getline(cin, nota);
            ofstream fileOut(filename);
            if (!fileOut) { cerr << "Errore in the opening the file in writing.\n"; return 1; }
            fileOut << nota << '\n';
            cout << "Note saved in " << filename << '\n';
            return 0;
        }
    } else if (scelta == "2") {
        cout << "Name of the file to open: ";
        getline(cin, filename);
        ifstream fileIn(filename);
        if (!fileIn) {
            cerr << "Error: file not founded or impossible to open.\n";
            return 1;
        }
        cout << "Content of " << filename << ":\n";
        while (getline(fileIn, nota)) cout << nota << '\n';
        fileIn.close();
    } else {
        cout << "Option invalid.\n";
    }
    return 0;
}
