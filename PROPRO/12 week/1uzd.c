#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void fillArray(int array[], int capacity){
    srand(time(NULL));
    for(int i = 0; i < capacity; ++i){
        array[i] = 1 + rand()% 100;
    }
}

void check(int array[], int capacity){
    int count = 0;
    for(int i = 0; i < capacity-1; ++i){
        if(array[i] <= array[i+1]){
            continue;
        }
        else{
            count++;
        }
    }
    if(count == 0){
        printf("All good\n");
    }
    else{
        printf("Something is wrong\n");
        printArray(array, capacity);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
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

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int cap = 20;
    int arr[cap];
    fillArray(arr, cap);

    // Bubble Sort
    bubbleSort(arr, cap);
    printf("Bubble Sort: ");
    // printArray(arr, cap);
    check(arr, cap);

    // Insertion Sort
    fillArray(arr, cap);
    insertionSort(arr, cap);
    printf("Insertion Sort: ");
    // printArray(arr, cap);
    check(arr, cap);

    // Quick Sort
    fillArray(arr, cap);
    quickSort(arr, 0, cap - 1);
    printf("Quick Sort: ");
    // printArray(arr, cap);
    check(arr, cap);

    // Selection Sort
    fillArray(arr, cap);
    selectionSort(arr, cap);
    printf("Selection Sort: ");
    // printArray(arr, cap);
    check(arr, cap);

    // Merge Sort

    mergeSort(arr, 0, cap - 1);
    printf("Merge Sort: ");
    // printArray(arr, cap);
    check(arr, cap);

    return 0;
}
