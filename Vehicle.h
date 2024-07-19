#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
private:
    std::string vehicleID;
    int arrivalTime;

public:
    Vehicle(std::string id, int arrival) : vehicleID(id), arrivalTime(arrival) {}

    int getArrivalTime() const {
        return arrivalTime;
    }

    std::string getVehicleID() const {
        return vehicleID;
    }

    void displayVehicle() const {
        std::cout << "Vehicle " << vehicleID << " arrived at " << arrivalTime << std::endl;
    }
};

#endif // VEHICLE_H
