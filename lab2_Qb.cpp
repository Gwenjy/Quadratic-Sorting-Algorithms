#include <iostream>
#include <algorithm>
#include <iomanip>

void conventionalBubbleSort(int arr[], int n, int& passes, int& comparisons, int& swaps) {
    passes = 0; comparisons = 0; swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        passes++;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] < arr[j + 1]) {
                swaps++;
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void improvedBubbleSort(int arr[], int n, int& passes, int& comparisons, int& swaps) {
    passes = 0; comparisons = 0; swaps = 0;
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
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int n, int& passes, int& comparisons, int& swaps) {
    passes = 0; comparisons = 0; swaps = 0;
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
}

void insertionSort(int arr[], int n, int& passes, int& comparisons, int& swaps) {
    passes = 0; comparisons = 0; swaps = 0;
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
        if (j >= 0) comparisons++;
    }
}

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void runAndPrintResults(const char* algorithmName, void (*sortFunc)(int[], int, int&, int&, int&), int dataArrayA[], int dataArrayB[], int n) {
    int arr[20];
    int passes, comparisons, swaps;

    // Worst Case
    std::copy(dataArrayA, dataArrayA + n, arr);
    sortFunc(arr, n, passes, comparisons, swaps);
    std::cout << std::setw(25) << algorithmName << " (Worst Case): Comparisons=" << std::setw(3) << comparisons << ", Swaps=" << std::setw(3) << swaps << ", Passes=" << std::setw(2) << passes << std::endl;

    // Best Case
    std::copy(dataArrayB, dataArrayB + n, arr);
    sortFunc(arr, n, passes, comparisons, swaps);
    std::cout << std::setw(25) << algorithmName << " (Best Case) : Comparisons=" << std::setw(3) << comparisons << ", Swaps=" << std::setw(3) << swaps << ", Passes=" << std::setw(2) << passes << std::endl;
}

int main() {
    int dataArrayA[20] = {2, 10, 24, 19, 27, 27, 31, 32, 41, 49, 42, 55, 56, 83, 75, 66, 88, 90, 91, 95};
    int dataArrayB[20] = {98, 94, 80, 83, 81, 63, 80, 72, 70, 61, 54, 54, 41, 40, 29, 35, 24, 17, 8, 3};
    int n = 20;

    std::cout << std::setw(25) << "Technique" << " | " << std::setw(8) << "Case" << " | " << std::setw(15) << "No of Comparisons, Swaps and Passes" << std::setw(15) << std::endl;
    std::cout << std::string(76, '-') << std::endl;

    runAndPrintResults("Conventional Bubble Sort", conventionalBubbleSort, dataArrayA, dataArrayB, n);
    runAndPrintResults("Improved Bubble Sort", improvedBubbleSort, dataArrayA, dataArrayB, n);
    runAndPrintResults("Selection Sort", selectionSort, dataArrayA, dataArrayB, n);
    runAndPrintResults("Insertion Sort", insertionSort, dataArrayA, dataArrayB, n);

    return 0;
}
