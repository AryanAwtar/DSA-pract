//Linear Search
#include <stdio.h>

int LinearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 110;
    int result = LinearSearch(arr, n, x);
    if (result != -1) {
        printf("Element found at index %d", result);
    } else {
        printf("Element not found");
    }
    return 0;
}
