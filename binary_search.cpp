#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Enter element to search: ";
    cin >> key;
    
    int idx = binarySearch(arr, key);
    if(idx != -1) cout << "Element found at index " << idx << endl;
    else cout << "Element not found\n";
    
    return 0;
}
