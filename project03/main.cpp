#include "STokenizer.h"
#include "Token.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    STokenizer s;
    // s.set_string("The quick brown fox jumped over the lazy dog");
    // s.set_string("don\'t...{55.6565}");
    // s.set_string("...it...was the night of october 17th. pi was still 3...14...");
    // s.set_string("traps r gay.3.46");
    s.set_string("traps...r...gay");

    while (!s.done()) {
        Token t;
        s >> t;
        cout << t << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}