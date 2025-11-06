🚦 Smart Traffic Light System Simulation (C++)
A console-based C++ simulation demonstrating a smart traffic management system. Unlike traditional fixed-timing lights, this program uses traffic density analysis to prioritize the road with the most vehicles, aiming to improve traffic flow efficiency.

✨ Features
Dynamic Prioritization: Identifies the road (North, South, East, or West) with the highest vehicle count.

Weighted Signal Timing: Grants a longer green light duration (10 seconds) to the high-density road.

Real-time Simulation: Uses C++ <thread> and <chrono> to simulate signal changes with a second-by-second countdown in the console.

Sequential Cycling: Ensures all roads get a turn, even after the priority road has passed.

⚙️ How It Works
The simulation flow is simple and effective:

Input: The user manually inputs the number of waiting vehicles for all four directions.

Analysis: The program determines the maxVehicles and the corresponding maxRoad.

Sequence: The signalSequence function is called first for the maxRoad, followed by the remaining roads in a predefined order.

🚀 Getting Started
To compile and run this simulation, you will need a C++ compiler that supports the C++11 standard or newer (required for <thread> and <chrono>).

1. Compile the Code
Use a compiler like g++. You may need to include a flag for linking the thread library (-pthread or -lpthread):

Bash

g++ traffic_sim.cpp -o traffic_sim -std=c++11 -pthread
2. Run the Simulation
Execute the compiled file and follow the prompts to enter vehicle counts:

Bash

./traffic_sim
💻 Code Overview
The project relies on two main components:

main() function: Handles all input/output and the core logic for identifying the busiest road.

signalSequence(const string& roadName, int duration): A helper function that prints the signal status and uses this_thread::sleep_for(chrono::seconds(1)) to introduce the real-time delay.

🔮 Future Enhancements (To-Do)
[ ] Implement a dynamic duration calculation where green time is proportional to vehicle count.

[ ] Introduce a dedicated Yellow/Amber signal phase between Green and Red.

[ ] Expand to handle pedestrian crossing signals.
