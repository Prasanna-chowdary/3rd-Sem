#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter request sequence:\n";
    for(int i = 0; i < n; i++)
        cin >> requests[i];

    cout << "Enter initial head position: ";
    cin >> head;

    vector<bool> visited(n, false);
    int distance = 0, current = head;

    cout << "\nHead movements:\n";

    for(int i = 0; i < n; i++) {
        int min_dist = INT32_MAX;
        int idx = -1;

        // Find the closest request
        for(int j = 0; j < n; j++) {
            if(!visited[j] && abs(requests[j] - current) < min_dist) {
                min_dist = abs(requests[j] - current);
                idx = j;
            }
        }

        cout << requests[idx] << " -> ";
        distance += abs(requests[idx] - current);
        current = requests[idx];
        visited[idx] = true;
    }

    cout << "End\n";
    cout << "Total Head Movement = " << distance << endl;
    return 0;
}
