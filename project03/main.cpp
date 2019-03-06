#include "STokenizer.h"
#include "Token.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    STokenizer s;
    s.set_string("The quick brown fox jumped over the lazy dog 55");

    while (!s.done()) {
        Token t;
        s >> t;
        cout << t << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}