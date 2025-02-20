#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int n) {
    int passes = 0, comparisons = 0, swaps = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        passes++;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] < arr[j + 1]) {
                swaps++;
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swaps occurred in this pass, the array is already sorted
        if (!swapped) break;
    }
    std::cout << "Bubble Sort: Passes=" << passes << ", Comparisons=" << comparisons << ", Swaps=" << swaps << std::endl;
}

void insertionSort(int arr[], int n) {
    int passes = 0, comparisons = 0, swaps = 0;
    for (int i = 1; i < n; i++) {
        passes++;
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
    std::cout << "Insertion Sort: Passes=" << passes << ", Comparisons=" << comparisons << ", Swaps=" << swaps << std::endl;
}

void selectionSort(int arr[], int n) {
    int passes = 0, comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        passes++;
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swaps++;
            std::swap(arr[i], arr[maxIdx]);
        }
    }
    std::cout << "Selection Sort: Passes=" << passes << ", Comparisons=" << comparisons << ", Swaps=" << swaps << std::endl;
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int dataArrayA[20] = {2, 10, 24, 19, 27, 27, 31, 32, 41, 49, 42, 55, 56, 83, 75, 66, 88, 90, 91, 95};
    int dataArrayB[20] = {98, 94, 80, 83, 81, 63, 80, 72, 70, 61, 54, 54, 41, 40, 29, 35, 24, 17, 8, 3};

    int arr[20];

    std::cout << "Original Array A: ";
    printArray(dataArrayA, 20);

    std::copy(std::begin(dataArrayA), std::end(dataArrayA), std::begin(arr));
    bubbleSort(arr, 20);
    std::cout << "Sorted Array A (Bubble Sort): ";
    printArray(arr, 20);

    std::copy(std::begin(dataArrayA), std::end(dataArrayA), std::begin(arr));
    insertionSort(arr, 20);
    std::cout << "Sorted Array A (Insertion Sort): ";
    printArray(arr, 20);

    std::copy(std::begin(dataArrayA), std::end(dataArrayA), std::begin(arr));
    selectionSort(arr, 20);
    std::cout << "Sorted Array A (Selection Sort): ";
    printArray(arr, 20);

    std::cout << std::endl;

    std::cout << "Original Array B: ";
    printArray(dataArrayB, 20);

    std::copy(std::begin(dataArrayB), std::end(dataArrayB), std::begin(arr));
    bubbleSort(arr, 20);
    std::cout << "Sorted Array B (Bubble Sort): ";
    printArray(arr, 20);

    std::copy(std::begin(dataArrayB), std::end(dataArrayB), std::begin(arr));
    insertionSort(arr, 20);
    std::cout << "Sorted Array B (Insertion Sort): ";
    printArray(arr, 20);

    std::copy(std::begin(dataArrayB), std::end(dataArrayB), std::begin(arr));
    selectionSort(arr, 20);
    std::cout << "Sorted Array B (Selection Sort): ";
    printArray(arr, 20);

    return 0;
}
