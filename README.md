#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// Function to simulate the green signal ON and OFF with countdown
void signalSequence(const string& roadName, int duration) {
    cout << "\n🚦 GREEN Signal ON for " << roadName << " road for " << duration << " seconds." << endl;
    for (int i = duration; i > 0; --i) {
        cout << "  " << i << " seconds remaining...." << endl;
        this_thread::sleep_for(chrono::seconds(1)); // wait for 1 second
    }
    cout << "🔴 Signal OFF for " << roadName << " road." << endl;
}

int main() {
    int north, south, east, west;
    cout << "==============================\n";
    cout << "🚦 SMART TRAFFIC LIGHT SYSTEM 🚦\n";
    cout << "==============================\n\n";
    
    cout << "Enter number of vehicles waiting at each road:\n";
    cout << "North Road: ";
    cin >> north;
    cout << "South Road: ";
    cin >> south;
    cout << "East Road: ";
    cin >> east;
    cout << "West Road: ";
    cin >> west;
    
    cout << "\nAnalyzing traffic density...\n\n";
    
    // Find road with max vehicles
    int maxVehicles = north;
    string maxRoad = "North";
    
    if (south > maxVehicles) {
        maxVehicles = south;
        maxRoad = "South";
    }
    if (east > maxVehicles) {
        maxVehicles = east;
        maxRoad = "East";
    }
    if (west > maxVehicles) {
        maxVehicles = west;
        maxRoad = "West";
    }
    
    cout << "Road with highest traffic: " << maxRoad << " (" << maxVehicles << " vehicles)\n\n";
    
    cout << "Starting signal sequence...\n";
    
    // Signal sequence - green light on highest traffic road for 10 seconds
    if (maxRoad == "North")
        signalSequence("North", 10);
    else if (maxRoad == "South")
        signalSequence("South", 10);
    else if (maxRoad == "East")
        signalSequence("East", 10);
    else if (maxRoad == "West")
        signalSequence("West", 10);
    
    // Other roads green light ON for 5 or 10 seconds as per the example
    if (maxRoad != "North")
        signalSequence("North", 10);
    if (maxRoad != "South")
        signalSequence("South", 10);
    if (maxRoad != "East")
        signalSequence("East", 5);
    if (maxRoad != "West")
        signalSequence("West", 5);
    
    cout << "\n✅ Simulation Complete. All signals processed.\n";
    cout << "=============================================\n";
    
    return 0;
}
