#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> maxHeap; // Max-heap to store fuel available at stations
    int fuel = startFuel, stops = 0, i = 0;

    while (fuel < target) {
        // Add all reachable stations to the max-heap
        while (i < stations.size() && stations[i][0] <= fuel) {
            maxHeap.push(stations[i][1]);
            i++;
        }

        // If we can't reach the next station or the target, return -1
        if (maxHeap.empty()) return -1;

        // Refuel at the station with the largest fuel available
        fuel += maxHeap.top();
        maxHeap.pop();
        stops++; // Increase stop count
    }

    return stops;
}

int main() {
    int target, startFuel, n;
    cout << "Enter the target distance: ";
    cin >> target;

    cout << "Enter the starting fuel amount: ";
    cin >> startFuel;

    cout << "Enter the number of fuel stations: ";
    cin >> n;

    vector<vector<int>> stations(n, vector<int>(2));
    cout << "Enter each station's position and fuel amount:\n";
    for (int i = 0; i < n; i++) {
        cin >> stations[i][0] >> stations[i][1];
    }

    int result = minRefuelStops(target, startFuel, stations);
    if (result == -1) {
        cout << "It's impossible to reach the target." << endl;
    } else {
        cout << "The minimum number of refueling stops is: " << result << endl;
    }

    return 0;
}
