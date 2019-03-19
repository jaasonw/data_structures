/*
 * Author: Jason Wong
 * Project: File Tokenizer
 * Purpose: Opens a file to repeatedly extract tokens from it using the internal
 *          String Tokenizer (STokenizer) class.
 * Notes:
 */
#include "FTokenizer.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    string filename;
    cout << "enter the filename to tokenize: ";
    cin >> filename;
    FTokenizer file(filename);
    cout << endl;
    while (!file.done()) {
        Token t;
        file >> t;
        if (t.token_str() != "")
            cout << setw(15) << left << t.type_string() << '|' << t << '|' << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}