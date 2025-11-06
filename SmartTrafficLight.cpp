#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Function to calculate green light duration based on traffic density
int calculateGreenTime(int vehicles, int totalVehicles) {
    if (totalVehicles == 0) return 5; // Minimum time if no traffic
    
    // Calculate percentage of total traffic
    double percentage = (double)vehicles / totalVehicles * 100;
    
    // Adaptive timing based on traffic percentage
    if (percentage >= 40) return 20;      // Very high traffic
    else if (percentage >= 25) return 15;  // High traffic
    else if (percentage >= 15) return 10;  // Medium traffic
    else if (percentage > 0) return 7;      // Low traffic
    else return 5;                          // Empty road
}

// Function to get traffic density level
string getDensityLevel(int vehicles) {
    if (vehicles == 0) return "EMPTY";
    else if (vehicles <= 5) return "LOW";
    else if (vehicles <= 15) return "MEDIUM";
    else if (vehicles <= 30) return "HIGH";
    else return "VERY HIGH";
}

// Function to show green light countdown
void showGreenLight(string roadName, int duration, string density) {
    cout << "\n" << string(60, '-') << endl;
    cout << "🚦 GREEN LIGHT: " << roadName << " Road" << endl;
    cout << "📊 Traffic: " << density << endl;
    cout << "⏱️  Duration: " << duration << " seconds" << endl;
    cout << string(60, '-') << endl;
    
    for (int i = duration; i > 0; i--) {
        cout << "\r  ⏳ " << i << " seconds remaining... " << flush;
        Sleep(1000);
    }
    cout << "\r  ✅ Complete!                          " << endl;
    cout << "🔴 RED LIGHT: " << roadName << " Road" << endl;
    Sleep(500);
}

int main() {
    int north, south, east, west;
    int totalVehicles;
    
    // Display header
    cout << "\n" << string(60, '=') << endl;
    cout << "   🚦 SMART TRAFFIC LIGHT CONTROL SYSTEM 🚦" << endl;
    cout << string(60, '=') << endl;
    
    // Get traffic input
    cout << "\nEnter number of vehicles waiting at each road:\n" << endl;
    cout << "  North Road: ";
    cin >> north;
    cout << "  South Road: ";
    cin >> south;
    cout << "  East Road: ";
    cin >> east;
    cout << "  West Road: ";
    cin >> west;
    
    // Calculate total
    totalVehicles = north + south + east + west;
    
    // Display traffic analysis
    cout << "\n" << string(60, '=') << endl;
    cout << "        TRAFFIC DENSITY ANALYSIS" << endl;
    cout << string(60, '=') << endl;
    cout << "\nRoad\t\tVehicles\tDensity\t\tGreen Time" << endl;
    cout << string(60, '-') << endl;
    
    // Store road data
    struct RoadData {
        string name;
        int vehicles;
        int greenTime;
        string density;
    };
    
    RoadData roads[4] = {
        {"North", north, calculateGreenTime(north, totalVehicles), getDensityLevel(north)},
        {"South", south, calculateGreenTime(south, totalVehicles), getDensityLevel(south)},
        {"East", east, calculateGreenTime(east, totalVehicles), getDensityLevel(east)},
        {"West", west, calculateGreenTime(west, totalVehicles), getDensityLevel(west)}
    };
    
    // Display analysis
    for (int i = 0; i < 4; i++) {
        cout << roads[i].name << "\t\t" << roads[i].vehicles << "\t\t" 
             << roads[i].density << "\t\t" << roads[i].greenTime << " sec" << endl;
    }
    
    cout << "\nTotal Vehicles: " << totalVehicles << endl;
    cout << string(60, '=') << endl;
    
    // Find road with highest traffic
    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (roads[i].vehicles > roads[maxIndex].vehicles) {
            maxIndex = i;
        }
    }
    
    cout << "\n📍 Priority Road: " << roads[maxIndex].name 
         << " (" << roads[maxIndex].vehicles << " vehicles)" << endl;
    
    // Start signal sequence
    cout << "\n🚀 Starting traffic light sequence...\n" << endl;
    cout << "Press Enter to begin...";
    cin.ignore();
    cin.get();
    
    // Process roads in priority order (highest traffic first)
    // Sort by vehicle count (simple bubble sort)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (roads[j].vehicles < roads[j + 1].vehicles) {
                RoadData temp = roads[j];
                roads[j] = roads[j + 1];
                roads[j + 1] = temp;
            }
        }
    }
    
    // Execute green lights
    for (int i = 0; i < 4; i++) {
        if (roads[i].vehicles > 0) {
            showGreenLight(roads[i].name, roads[i].greenTime, roads[i].density);
        }
    }
    
    // Final message
    cout << "\n" << string(60, '=') << endl;
    cout << "   ✅ Traffic Light Cycle Completed!" << endl;
    cout << string(60, '=') << endl;
    cout << "\nThank you for using Smart Traffic Light System! 🚗\n" << endl;
    
    return 0;
}

