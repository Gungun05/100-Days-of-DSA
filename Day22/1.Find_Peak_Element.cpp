/*
Question:
Given an integer array, find any one peak element and return its index.
A peak element is one that is strictly greater than its immediate neighbors.
Assume the elements outside the array are -∞.
The solution should run in O(log n) time.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the index of a peak element
int findPeakElement(vector<int>& arr) {
    int n = arr.size();

    // If the array has only one element, it is the peak
    if (n == 1) return 0;

    // Check if the peak lies at the boundaries
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int start = 1;
    int end = n - 2;

    // Binary search based on slope comparison
    while (start <= end) {
        int mid = start + (end - start) / 2;

        // If mid is greater than both neighbors, it is a peak
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // If the slope is increasing, move to the right side
        else if (arr[mid] > arr[mid - 1]) {
            start = mid + 1;
        }
        // Otherwise, move to the left side
        else {
            end = mid - 1;
        }
    }

    return -1;  // This line is added for safety
}

int main() {
    int n;
    vector<int> arr;

    cout << "Enter no. of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = findPeakElement(arr);
    cout << "Peak element index: " << peakIndex << endl;

    return 0;
}
