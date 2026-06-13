#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string scelta;

    cout << "Welcome to ThinkNoteCLI. Now you're writing a new note, and for save it, press the Enter key.\n";
    getline(cin, scelta);

    ofstream fileOut("note.txt");
    if (!fileOut) {
        cerr << "Error in the opening the file on writing." << endl;
        return 1;
    }
    fileOut << scelta << '\n';
    fileOut.close();

    ifstream fileIn("nota.txt");
    if (!fileIn) {
        cerr << "Error in the opening the file on reading." << endl;
        return 1;
    }

    return 0;
}