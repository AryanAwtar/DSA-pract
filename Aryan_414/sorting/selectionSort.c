#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
int arrEntry(int a[100],int n){
    for (int i=0;i<n;i++){
        printf("Enter the no for %d index of array",i);
        scanf("%d",&a[i]);
    }
    printf("The unsorted array :- ");
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main() {
    int arr[100],n;
    printf("Enter the size of array :- ");
    scanf ("%d",&n);
    arrEntry(arr,n);
    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}