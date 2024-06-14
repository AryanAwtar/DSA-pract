#include <stdio.h>

void bubbleSort(int arr[100],int n);
int arrEntry(int a[100],int n);

int main() {
    int arr[100],n;
    printf("Enter the size of array :- ");
    scanf ("%d",&n);
    arrEntry(arr,n);
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
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
void bubbleSort(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}