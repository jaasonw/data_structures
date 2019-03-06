#include "STokenizer.h"
#include "Token.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    STokenizer s;
    s.set_string("...it...was the night of october 17th. pi was still.3.14.");

    while (!s.done()) {
        Token t;
        s >> t;
        cout << setw(20) << left << t.type_string() << '|' << t << '|' << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}