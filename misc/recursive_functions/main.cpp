#include <iostream>
#include <string>

using namespace std;

void R1_levls(int max, int level = 0) {
    level++;
    cout << string(level, ' ');
    cout << "This was written by call number " << level << endl;
    if (level < max)
        R1_levls(max, level);
    cout << string(level, ' ');
    cout << "This ALSO written by call number " << level << endl;
}

void R2_Box_utility(string str, int number, int level) {

}

void R2_Box(string str, int levels) {
    for (int i = 0; i <= levels; i++) {

    }
}

void R3_catman(string first, string second, int index = 0) {
    for (int i = 0; i < first.length(); i++) {
        char temp;
        temp = first.at(index);
        first.at(index) = first.at(i);
        first.at(i) = temp;
        cout << first << second << endl;
    }
    if (index < first.length() - 1) {
        R3_catman(first, second, index + 1);
    }
}

double R5_sumover(unsigned int num) {
    if (num == 0)
        return 0;
    else
        return (1.0 / num) + R5_sumover(num - 1);
}

void R16_binary(int low, int high) {
    int midpoint = (high + low) / 2;
    if (low == high || midpoint == low || midpoint == high) {
        cout << "your number is " << low << endl;
        return;
    }
    string input;
    cout << "is your number lower, higher, or equal to " << midpoint << ": ";
    cin >> input;
    for(int i = 0; i < input.length(); i++)
        input[i] = tolower(input[i]);

    
    if (input == "lower") {
        R16_binary(low, midpoint - 1);
    }
    else if (input == "higher") {
        R16_binary(midpoint + 1, high);
    }
    else if (input == "equal") {
        cout << "your number is " << midpoint << endl;
    }
    else {
        cout << "invalid input" << endl;
    }
    

}

int main(int argc, char const* argv[]) {

    R1_levls(5);
    // R2_Box("BOX", 5);
    R3_catman("CAT", "MAN");
    cout << endl;
    cout << R5_sumover(5);
    cout << endl;
    R16_binary(1, 100);
    cout << endl;
    system("pause");
    return 0;
}