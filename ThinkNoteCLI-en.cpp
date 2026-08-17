#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nota, scelta, filename, scelta2;
    cout << "Welcome to ThinkNoteCLI. Choose one of the 2 options.\n";
    cout << "1. Write a new note\n";
    cout << "2. Open an already existing note.\n";
    cout << "3. About ThinkNoteCLI\n";
    getline(cin, scelta);

    if (scelta == "1") {
        cout << "Name of the file (ex. note.txt): \n";
        getline(cin, filename);
        ifstream check(filename);
        if (check) {
            check.close();
            cout << "The file \"" << filename << "\" is already existing. Do you want (o)verwrite, (h)ang or (d)elete? [o/h/d]: ";
            string opt; getline(cin, opt);
            if (opt == "d" || opt == "D") {
                cout << "Operation deleted.\n";
                return 0;
            }
            ios_base::openmode mode = (opt == "a" || opt == "A") ? ios::app : ios::trunc;
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
            if (!fileOut) { cerr << "Error in the opening the file in writing..\n"; return 1; }
            fileOut << nota << '\n';
            cout << "Note saved in " << filename << '\n';
            return 0;
        }
    } else if (scelta == "2") {
         cout << "Name of the file to open (ex. note.txt): ";
        getline(cin, filename);

        ifstream fileIn(filename);
        if (!fileIn.is_open()) {
            cout << "Error in opening file.n";
            return 0;
        }

        cout << "---- Content of " << filename << " ----\n";
        string line;
        while (getline(fileIn, line)) {
            cout << line << '\n';
        }
        cout << "------------------------------------------\n";

        fileIn.close();

        cout << "Do you want to edit the note? (Y/N)\n";
        getline(cin, scelta2);
        if (scelta2 == "Y") {
            cout << "Now you can write the new note (deleting the previous one)n";
            getline(cin, nota);

            ofstream fileOut(filename, ios::trunc); 
            if (!fileOut) {
                cerr << "Errore opening file in writing. Make sure you have the necessary permits for edit the note\n";
                return 1;
            }
            fileOut << nota << '\n';
            cout << "Edited file: " << filename << '\n';
            return 0;
        }
        if (scelta2 == "N") {
            return 0;
        }
    } else if (scelta == "3") {
        cout << "ThinkNoteCLI is a program for writing notes. It is (obvisuly) free, open-source and invented in Italy.\n";
    }
     else {
        cout << "Option invalid.\n";
    }
    return 0;
}
