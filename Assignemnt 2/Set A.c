Assignment 2 - Set A
a) Sort a random array of n integers (accept the value of n from user) in ascending order by
using bubble sort algorithm.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter integers by pressing enter : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array (Bubble Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

b) Sort a random array of n integers (create a random array of n integers) in ascending order by using insertion sort algorithm.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter integers by pressing enter :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array (Insertion Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}


c) Sort a random array of n integers (accept the value of n from user) in ascending order by
using selection sort algorithm.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter integers by pressing Enter : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array (Selection Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}


