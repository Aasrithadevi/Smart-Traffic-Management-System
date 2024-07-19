#include <iostream>
#include <vector>
#include "TrafficManagementSystem.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Intersection.h"

int main() {
    // Create traffic lights for 4 directions
    TrafficLight light1("North", 10, 5, 2);
    TrafficLight light2("South", 10, 5, 2);
    TrafficLight light3("East", 10, 5, 2);
    TrafficLight light4("West", 10, 5, 2);

    // Create intersections
    Intersection intersection1("Intersection1", {light1, light2, light3, light4}, 10, 2);

    // Create traffic management system
    TrafficManagementSystem tms;
    tms.addIntersection(intersection1);

    // Get user input for the duration of the simulation
    int duration;
    std::cout << "Enter the duration of the simulation in seconds (20-120): ";
    std::cin >> duration;

    // Run simulation for the specified duration
    tms.runSimulation(duration);

    return 0;
}
