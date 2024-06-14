#include <stdio.h>

void merge(int A[], int p, int q, int r) {
    int nl = q - p + 1;
    int nr = r - q;

    int L[nl], R[nr];

    for (int i = 0; i < nl; ++i) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < nr; ++j) {
        R[j] = A[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < nl) {
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < nr) {
        A[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void arrEntry(int a[100], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the number for index %d of array: ", i);
        scanf("%d", &a[i]);
    }
    printf("The unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arrEntry(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
