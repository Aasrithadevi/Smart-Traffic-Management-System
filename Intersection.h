#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <iostream>
#include <queue>
#include <vector>
#include "TrafficLight.h"
#include "Vehicle.h"

enum Direction { NORTH, SOUTH, EAST, WEST };

class Intersection {
private:
    std::string intersectionID;
    std::vector<TrafficLight> trafficLights;
    std::vector<std::queue<Vehicle>> vehicleQueues;
    int currentPhase;
    int phaseDuration;
    int yellowDuration;
    int phaseTimer;

public:
    Intersection(std::string id, std::vector<TrafficLight> lights, int phaseDur, int yellowDur) 
        : intersectionID(id), trafficLights(lights), vehicleQueues(4), currentPhase(0), phaseDuration(phaseDur), yellowDuration(yellowDur), phaseTimer(phaseDur) {
        updateTrafficLights();
    }

    void addVehicle(Vehicle vehicle, Direction direction) {
        if (vehicleQueues[direction].size() < 6) { // Max 6 vehicles when the signal is red
            vehicleQueues[direction].push(vehicle);
        }
    }

    void removeVehicle(Direction direction) {
        if (!vehicleQueues[direction].empty()) {
            vehicleQueues[direction].pop();
        }
    }

    void changePhase() {
        currentPhase = (currentPhase + 1) % 4;
        phaseTimer = phaseDuration;
        updateTrafficLights();
    }

    void updateTrafficLights() {
        if (currentPhase == 0) {
            trafficLights[NORTH].changeState(GREEN);
            trafficLights[SOUTH].changeState(GREEN);
            trafficLights[EAST].changeState(RED);
            trafficLights[WEST].changeState(RED);
        } else if (currentPhase == 1) {
            trafficLights[NORTH].changeState(YELLOW);
            trafficLights[SOUTH].changeState(YELLOW);
            trafficLights[EAST].changeState(RED);
            trafficLights[WEST].changeState(RED);
            phaseTimer = yellowDuration; // Ensure yellow duration is set for 2 seconds
        } else if (currentPhase == 2) {
            trafficLights[NORTH].changeState(RED);
            trafficLights[SOUTH].changeState(RED);
            trafficLights[EAST].changeState(GREEN);
            trafficLights[WEST].changeState(GREEN);
        } else if (currentPhase == 3) {
            trafficLights[NORTH].changeState(RED);
            trafficLights[SOUTH].changeState(RED);
            trafficLights[EAST].changeState(YELLOW);
            trafficLights[WEST].changeState(YELLOW);
            phaseTimer = yellowDuration; // Ensure yellow duration is set for 2 seconds
        }
    }

    void manageTraffic() {
        if (phaseTimer > 0) {
            phaseTimer--;
        } else {
            if (currentPhase == 1 || currentPhase == 3) {
                // After yellow phase, set the timer to the full phase duration and change the phase
                phaseTimer = phaseDuration;
                changePhase();
            } else {
                changePhase();
            }
        }

        if (trafficLights[NORTH].getState() == GREEN) {
            if (!vehicleQueues[NORTH].empty()) removeVehicle(NORTH);
            if (!vehicleQueues[SOUTH].empty()) removeVehicle(SOUTH);
        } else if (trafficLights[EAST].getState() == GREEN) {
            if (!vehicleQueues[EAST].empty()) removeVehicle(EAST);
            if (!vehicleQueues[WEST].empty()) removeVehicle(WEST);
        }

        for (auto& light : trafficLights) {
            light.decrementTimer();
        }
    }

    void displayStatus() const {
        std::cout << "Intersection " << intersectionID << " Status:" << std::endl;
        
        // Display traffic lights in a visual layout
        std::cout << "        North\n";
        std::cout << "        |||\n";
        std::cout << "        " << trafficLights[NORTH].getStateStr() << "\n";
        std::cout << "        " << trafficLights[NORTH].getCountdownMessage() << "\n";
        std::cout << "     " << vehiclesInQueue(NORTH) << "\n";
        std::cout << "West " << trafficLights[WEST].getStateStr() << " -- Intersection -- " << trafficLights[EAST].getStateStr() << " East\n";
        std::cout << "     " << trafficLights[WEST].getCountdownMessage() << "           " << trafficLights[EAST].getCountdownMessage() << "\n";
        std::cout << "     " << vehiclesInQueue(WEST) << "                      " << vehiclesInQueue(EAST) << "\n";
        std::cout << "        " << trafficLights[SOUTH].getStateStr() << "\n";
        std::cout << "        " << trafficLights[SOUTH].getCountdownMessage() << "\n";
        std::cout << "        |||\n";
        std::cout << "     " << vehiclesInQueue(SOUTH) << "\n";
        std::cout << "        South\n";

        std::cout << std::endl;
    }

    std::string vehiclesInQueue(Direction direction) const {
        std::string vehicles = "";
        if (vehicleQueues[direction].empty()) {
            vehicles = "None";
        } else {
            std::queue<Vehicle> tempQueue = vehicleQueues[direction];
            while (!tempQueue.empty()) {
                vehicles += "🚗";  // Car emoji
                tempQueue.pop();
            }
        }
        return vehicles;
    }

    std::string getIntersectionID() const {
        return intersectionID;
    }
};

#endif // INTERSECTION_H
