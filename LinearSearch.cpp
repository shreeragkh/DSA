#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;               // size of array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];     // array elements
    }

    int key;
    cin >> key;            // element to search

    // Linear Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index: " << i;
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}
