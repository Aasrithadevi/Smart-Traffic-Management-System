#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <iostream>
#include <chrono>
#include <thread>

enum LightState { RED, GREEN, YELLOW };

class TrafficLight {
private:
    std::string direction;
    LightState state;
    int redDuration;
    int greenDuration;
    int yellowDuration;
    int timer;

public:
    TrafficLight(std::string dir, int red, int green, int yellow) 
        : direction(dir), state(RED), redDuration(red), greenDuration(green), yellowDuration(yellow), timer(red) {}

    void changeState(LightState newState) {
        state = newState;
        if (state == RED) {
            timer = redDuration;
        } else if (state == GREEN) {
            timer = greenDuration;
        } else if (state == YELLOW) {
            timer = yellowDuration;
        }
    }

    void decrementTimer() {
        if (timer > 0) {
            timer--;
        }
    }

    LightState getState() const {
        return state;
    }

    std::string getStateStr() const {
        if (state == RED) {
            return "\033[5;31mRED\033[0m"; // Blinking red
        } else if (state == GREEN) {
            return "\033[5;32mGREEN\033[0m"; // Blinking green
        } else {
            return "\033[5;33mYELLOW\033[0m"; // Blinking yellow
        }
    }

    int getTimer() const {
        return timer;
    }

    std::string getCountdownMessage() const {
        return "\033[5m" + std::to_string(timer) + "s\033[0m";
    }

    std::string getDirection() const {
        return direction;
    }
};

#endif // TRAFFICLIGHT_H
