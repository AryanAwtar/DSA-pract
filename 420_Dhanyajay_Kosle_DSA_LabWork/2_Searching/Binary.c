//Binary Search
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid; // Element found at index mid
        }

        if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {12, 21, 24, 30, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element found at index %d", result);
    } else {
        printf("Element not found");
    }
    return 0;
}
