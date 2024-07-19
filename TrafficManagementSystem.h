#ifndef TRAFFICMANAGEMENTSYSTEM_H
#define TRAFFICMANAGEMENTSYSTEM_H

#include <iostream>
#include <vector>
#include <random>
#include "Intersection.h"

class TrafficManagementSystem {
private:
    std::vector<Intersection> intersections;

public:
    void addIntersection(Intersection intersection) {
        intersections.push_back(intersection);
    }

    void runSimulation(int duration) {
        if (duration < 20 || duration > 120) {
            std::cout << "Please enter a duration between 20 and 120 seconds." << std::endl;
            return;
        }

        // Initialize random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 3);

        // Add random vehicles to the queues initially
        for (auto& intersection : intersections) {
            for (int i = 0; i < 24; ++i) {
                Vehicle newVehicle("V" + std::to_string(i + 1), i + 1);
                Direction randomDirection = static_cast<Direction>(dist(gen));
                intersection.addVehicle(newVehicle, randomDirection);
            }
        }

        for (int i = 0; i < duration; ++i) {
            std::cout << "\n========================================" << std::endl;
            std::cout << "Simulation Step: " << i + 1 << std::endl;
            std::cout << "========================================" << std::endl;
            for (auto& intersection : intersections) {
                std::cout << "Intersection ID: " << intersection.getIntersectionID() << std::endl;
                intersection.manageTraffic();
                intersection.displayStatus();
                std::cout << "----------------------------------------" << std::endl;
            }

            // Add a new vehicle to the queue at each step
            for (auto& intersection : intersections) {
                Vehicle newVehicle("V" + std::to_string(i + 25), i + 25);
                Direction randomDirection = static_cast<Direction>(dist(gen));
                intersection.addVehicle(newVehicle, randomDirection);
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

#endif // TRAFFICMANAGEMENTSYSTEM_H
