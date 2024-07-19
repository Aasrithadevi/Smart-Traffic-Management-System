# Smart-Traffic-Management-System_2018
OOPS

This project simulates a smart traffic management system using C++. The simulation includes traffic lights for four directions (North, South, East, and West) and manages vehicle flow at an intersection.

## Features

- **Random Vehicle Generation:** Vehicles are randomly generated at all signals at the start of the simulation.
- **Traffic Light Phases:** Traffic lights follow standard phases with a 2-second yellow light before turning red.
- **Dynamic Simulation:** Vehicles are added randomly at each signal at every step of the simulation.
- **Clear Visualization:** The status of the intersection, including traffic lights and vehicle queues, is displayed at each step.

## Files

- `TrafficLight.h`: Defines the TrafficLight class.
- `Vehicle.h`: Defines the Vehicle class.
- `Intersection.h`: Defines the Intersection class and manages traffic flow.
- `TrafficManagementSystem.h`: Manages the entire traffic management system.
- `main.cpp`: Main file to run the simulation.

## How to Compile and Run

1. **Compile the Project:**

    ```sh
    g++ -std=c++11 main.cpp -o SmartTrafficManagement
    ```

2. **Run the Executable:**

    ```sh
    ./SmartTrafficManagement
    ```

3. **Enter the duration of the simulation when prompted:**

    The program will run for the specified duration, displaying the state of the four traffic lights at the intersection, a countdown timer, and the vehicles in the queue.

## Example Output

```plaintext
Enter the duration of the simulation in seconds (1-120): 10

========================================
Simulation Step: 1
========================================
Intersection ID: Intersection1
Intersection Intersection1 Status:
        North
        |||
        GREEN
         5s
     🚗🚗
West RED -- Intersection -- RED East
         10s           10s
None                      🚗🚗🚗
        GREEN
         5s
        |||
     🚗🚗
        South

----------------------------------------
...
