#pragma once
#include "Average.h"
#include "Probability.h"
#include "Queue/Queue.h"
#include <iostream>

class Simulation {
private:
    // CONFIG
    // how long it takes for a take off once plane is on the runway
    unsigned int time_to_take_off = 15;
    // how long it takes for a plane to land on the runway in each second
    unsigned int time_to_land = 5;

    // probability of arrival of a plane into the take off line
    Probability takeoff_probability = Probability(0.08);
    // probability of arrival of planes for landing in each second
    Probability landing_probability = Probability(0.10);

    // maximum amount of time a plan can stay in landing queue without crashing
    unsigned int fuel_limit = 20;
    // total time you will run the simulation
    unsigned int simulation_time = 1440;
    // debug mode
    const bool DEBUG = false;
    
    // queues
    Queue<unsigned int> landing_queue;
    Queue<unsigned int> takeoff_queue;

    // SIMULATION STATS
    unsigned int planes_landed;
    unsigned int planes_took_off;
    unsigned int planes_crashed;
    Average avg_wait_takeoff;
    Average avg_wait_landing;

public:
    Simulation();
    void run_simulation();
    friend std::ostream& operator<<(std::ostream& outs, const Simulation& s);
};