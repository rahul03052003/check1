#include <stdio.h>
#include<conio.h>
int a[2500];

void merge(int low, int mid, int high) {
    int i = low, l = low, j = mid + 1, b[2500], k;

    while ((l <= mid) && (j <= high)) {
        if (a[l] <= a[j]) {
            b[i] = a[l];
            l++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    if (l > mid) {
        for (k = j; k <= high; k++) {
            b[i] = a[k];
            i++;
        }
    } else {
        for (k = l; k <= mid; k++) {
            b[i] = a[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void mergeSort(int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    int i, n;

    printf("Enter the array size:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nThe elements considered are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    mergeSort(0, n - 1);

    printf("\nThe sorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    return 0;
}

