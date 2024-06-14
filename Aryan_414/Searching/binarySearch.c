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
int arrEntry(int a[100],int n){
    for (int i=0;i<n;i++){
        printf("Enter the no for %d index of array :-",i);
        scanf("%d",&a[i]);
    }
}
int main() {
    int arr[100],n,x,result;

    printf("Enter the size of array :- ");
    scanf ("%d",&n);
    arrEntry(arr,n);

    printf("Enter the number you want to search :- ");
    scanf("%d",&x);
    
    result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element found at index %d", result);
    } else {
        printf("Element not found");
    }
    return 0;
}