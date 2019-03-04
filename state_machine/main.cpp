#include "agency_table.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    int table[state_machine::NUM_ROWS][state_machine::MAX_COLUMNS];
    const char* DIGITS = "1234567890";
    state_machine::init_table(table);
    state_machine::mark_fail(table, 0);    // Mark states 0 and 2 as fail states
    state_machine::mark_success(table, 1); // Mark states 1 and 3 as success states
    state_machine::mark_fail(table, 2);
    state_machine::mark_success(table, 3);

    state_machine::mark_cells(0, table, DIGITS, 1);   // state [0] --- DIGITS ---> [1]
    state_machine::mark_cell(0, table, '.', 2);       // state [0] --- '.' ------> [2]
    state_machine::mark_cells(1, table, DIGITS, 1);   // state [1] --- DIGITS ---> [1]
    state_machine::mark_cell(1, table, '.', 2);       // state [1] --- '.' ------> [2]
    state_machine::mark_cells(2, table, DIGITS, 3);   // state [2] --- DIGITS ---> [3]
    state_machine::mark_cells(3, table, DIGITS, 3);   // state [3] --- DIGITS ---> [3]

    const char* test = "1234.";
    int state = 0;
    int pos = 0;
    state_machine::get_token(test, pos, table, state);
    state_machine::show_string(test, pos);

    cout << endl;
    system("pause");
    return 0;
}