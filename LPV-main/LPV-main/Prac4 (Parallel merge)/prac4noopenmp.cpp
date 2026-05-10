#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define SIZE 10000

// =====================================
// Merge Function
// =====================================
void merge(vector<int>& arr,
           int left,
           int mid,
           int right) {

    vector<int> leftArray(arr.begin() + left,
                          arr.begin() + mid + 1);

    vector<int> rightArray(arr.begin() + mid + 1,
                           arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    // Merge two sorted arrays
    while (i < leftArray.size() &&
           j < rightArray.size()) {

        if (leftArray[i] <= rightArray[j]) {

            arr[k++] = leftArray[i++];
        }
        else {

            arr[k++] = rightArray[j++];
        }
    }

    // Remaining elements
    while (i < leftArray.size()) {

        arr[k++] = leftArray[i++];
    }

    while (j < rightArray.size()) {

        arr[k++] = rightArray[j++];
    }
}

// =====================================
// Sequential Merge Sort
// =====================================
void mergeSortSequential(vector<int>& arr,
                         int left,
                         int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSortSequential(arr, left, mid);

        mergeSortSequential(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// =====================================
// "Parallel" Merge Sort
// (Works without OpenMP)
// =====================================
void mergeSortParallel(vector<int>& arr,
                       int left,
                       int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSortParallel(arr, left, mid);

        mergeSortParallel(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// =====================================
// Generate Random Array
// =====================================
void generateRandomArray(vector<int>& arr) {

    for (int i = 0; i < arr.size(); i++) {

        arr[i] = rand() % 100000;
    }
}

// =====================================
// Print Array
// =====================================
void printArray(vector<int>& arr,
                int limit = 20) {

    for (int i = 0;
         i < limit && i < arr.size();
         i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}

// =====================================
// Main Function
// =====================================
int main() {

    vector<int> arr(SIZE);
    vector<int> temp;

    srand(time(0));

    // Generate Random Data
    generateRandomArray(arr);

    cout << "\nOriginal Array (First 20 Elements):\n";
    printArray(arr);

    // =====================================
    // Sequential Merge Sort
    // =====================================

    temp = arr;

    auto start1 = high_resolution_clock::now();

    mergeSortSequential(temp,
                        0,
                        SIZE - 1);

    auto end1 = high_resolution_clock::now();

    double sequentialTime =
        duration<double>(end1 - start1).count();

    cout << "\nSequential Merge Sort Completed.\n";

    cout << "Sequential Execution Time: "
         << sequentialTime
         << " seconds\n";

    cout << "Sorted Array (First 20 Elements):\n";
    printArray(temp);

    // =====================================
    // Parallel Merge Sort
    // =====================================

    temp = arr;

    auto start2 = high_resolution_clock::now();

    mergeSortParallel(temp,
                      0,
                      SIZE - 1);

    auto end2 = high_resolution_clock::now();

    double parallelTime =
        duration<double>(end2 - start2).count();

    cout << "\nParallel Merge Sort Completed.\n";

    cout << "Parallel Execution Time: "
         << parallelTime
         << " seconds\n";

    cout << "Sorted Array (First 20 Elements):\n";
    printArray(temp);

    // =====================================
    // Performance Analysis
    // =====================================

    cout << "\nPerformance Analysis\n";

    cout << "Sequential Time: "
         << sequentialTime
         << " seconds\n";

    cout << "Parallel Time: "
         << parallelTime
         << " seconds\n";

    cout << "Speedup: "
         << sequentialTime / parallelTime
         << endl;

    return 0;
}