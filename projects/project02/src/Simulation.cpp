#include "Simulation.h"
#include <ctime>

Simulation::Simulation() {
    srand(time(0));
}

void Simulation::run_simulation() {
    // init variables
    // reset stats
    planes_landed = 0;
    planes_took_off = 0;
    planes_crashed = 0;
    avg_wait_takeoff = Average();
    avg_wait_landing = Average();

    // queues
    landing_queue.clear();
    takeoff_queue.clear();

    // cooldown timer
    int cooldown = 0;

    for (int timer = 0; timer <= simulation_time; timer++) {
        if (landing_probability.roll()) {
            if (DEBUG) {
                std::cout << "Plane added to landing queue with timestamp: "
                          << timer << std::endl;
            }
            landing_queue.push(timer);
        }
        if (takeoff_probability.roll()) {
            if (DEBUG) {
                std::cout << "Plane added to take off queue with timestamp: "
                          << timer << std::endl;
            }
            takeoff_queue.push(timer);
        }

        if (!landing_queue.empty() && cooldown == 0) {
            int plane_time = 0;
            while (!landing_queue.empty() && timer - plane_time > fuel_limit) {
                plane_time = landing_queue.pop();
                if (timer - plane_time > fuel_limit) {
                    planes_crashed++;
                    if (DEBUG) {
                        std::cout << "Plane crashed, skipping" << std::endl; 
                    }
                }
            }

            if (DEBUG) {
                std::cout << "Plane landing with timestamp: "
                          << plane_time << std::endl;
            }
            planes_landed++;
            avg_wait_landing.add(timer - plane_time);
            cooldown = time_to_land;
        }
        if (!takeoff_queue.empty() && cooldown == 0) {
            int plane_time = takeoff_queue.pop();

            if (DEBUG) {
                std::cout << "Plane taking off with timestamp: "
                          << plane_time << std::endl;
            }
            planes_took_off++;
            avg_wait_takeoff.add(timer - plane_time);
            cooldown = time_to_take_off;
        }

        // decrement dooldown
        cooldown -= cooldown > 0;
    }
}

std::ostream& operator<<(std::ostream& outs, const Simulation& s) {
    outs << "============================================" << std::endl;
    outs << "time to take off\t: " << s.time_to_take_off << std::endl;
    outs << "time to land\t\t: " << s.time_to_land << std::endl;
    outs << "probability of landing\t: " << s.landing_probability << std::endl;
    outs << "probability of takeoff\t: " << s.takeoff_probability << std::endl;
    outs << "fuel: time to crash\t: " << s.fuel_limit << std::endl;
    outs << "total simulation time\t: " << s.simulation_time << std::endl;

    outs << std::endl;
    outs << std::endl;
    outs << ". . . . . . . . . . . . . . . . . . . . . . ." << std::endl;

    outs << s.planes_landed << " landed" << std::endl;
    outs << s.planes_took_off << " took off" << std::endl;
    outs << s.planes_crashed << " crashed. :(" << std::endl;
    outs << "Average waiting time to land: " << s.avg_wait_landing << std::endl;
    outs << "Average waiting time to take off: " << s.avg_wait_takeoff
         << std::endl;
    outs << "Planes in landing queue: " << s.landing_queue.size() << std::endl;
    outs << "Planes in take off queue: " << s.takeoff_queue.size() << std::endl;
    outs << "============================================" << std::endl;
    return outs;
}