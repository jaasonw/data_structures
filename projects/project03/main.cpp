/*
 * Author: Jason Wong
 * Project: String Tokenizer
 * Purpose: Create a string tokenizer that returns a single token from an input
 *          string based on the rules set by the internal state machine
 * Notes:
 */
#include "STokenizer.h"
#include "Token.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    // STokenizer s1("...it...was the night of october 17th. pi was still.3.14.");
    STokenizer s2("What the uwu did you just uwu say about me, you little uwu? "
                  "I'll have you know I uwu top of my class in the uwu");

    while (!s2.done()) {
        Token t;
        s2 >> t;
        cout << setw(20) << left << t.type_string() << '|' << t << '|' << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}