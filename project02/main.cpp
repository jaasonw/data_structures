/*
 * Author: Jason Wong
 * Project: Airplane Simluation
 * Purpose: To create a simulaton of an airport that lands and flies planes 
 *          using queues
 * Notes:
 */
#include "Simulation.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    Simulation s;

    // rerun the simulation several times
    for (int i = 0; i < 10; i++) {
        s.run_simulation();
        cout << s << endl;
    }
    
    cout << endl;
    system("pause");
    return 0;
}