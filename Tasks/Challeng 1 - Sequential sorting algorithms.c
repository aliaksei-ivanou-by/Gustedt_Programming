#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double* L = (double*)malloc(n1 * sizeof(double));
    double* R = (double*)malloc(n2 * sizeof(double));

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int stringCompare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int partition(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(&arr[i], &arr[j], sizeof(char*));
        }
    }
    swap(&arr[i + 1], &arr[high], sizeof(char*));
    return i + 1;
}

void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool isSortedDouble(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

bool isSortedStrings(char *arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i - 1], arr[i]) > 0) {
            return false;
        }
    }
    return true;
}

void testSort() {
    printf("Testing merge sort for doubles...\n");
    double doubles[] = {3.5, 1.2, 4.8, 2.2, 5.9};
    int doubleSize = sizeof(doubles) / sizeof(doubles[0]);
    mergeSort(doubles, 0, doubleSize - 1);

    if (isSortedDouble(doubles, doubleSize)) {
        printf("Merge sort for doubles is correct.\n");
    } else {
        printf("Merge sort for doubles failed.\n");
    }

    printf("Testing quick sort for strings...\n");
    char* strings[] = {"pear", "apple", "orange", "banana", "grape"};
    int stringSize = sizeof(strings) / sizeof(strings[0]);
    quickSort(strings, 0, stringSize - 1);

    if (isSortedStrings(strings, stringSize)) {
        printf("Quick sort for strings is correct.\n");
    } else {
        printf("Quick sort for strings failed.\n");
    }
}

int main(void) {
    testSort();
    return EXIT_SUCCESS;
}
