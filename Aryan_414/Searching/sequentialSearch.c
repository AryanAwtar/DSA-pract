#include <stdio.h>

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
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
    int arr[100],n,x,result;

    printf("Enter the size of array :- ");
    scanf ("%d",&n);
    arrEntry(arr,n);

    printf("Enter the number you want to search :- ");
    scanf("%d",&x);

    result = sequentialSearch(arr, n, x);
    
    if (result != -1) {
        printf("Element found at index %d", result);
    } else {
        printf("Element not found");
    }
    return 0;
}
