
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
