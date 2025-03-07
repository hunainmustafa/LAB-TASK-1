#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int maxVal = arr[0]; 

    for (int i = 1; i < n; i++) { 
        if (arr[i] > maxVal) {
            maxVal = arr[i]; 
        }
    }
    return maxVal;
}

void lab2() {
    int arr[] = {3, 1, 7, 5, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The maximum value in the array is: " << findMax(arr, size) << endl;
}

int main() {
    lab2();
    return 0;
}