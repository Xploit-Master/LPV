#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define SIZE 10000

// =====================================
// Sequential Bubble Sort
// =====================================
void bubbleSortSequential(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// =====================================
// "Parallel" Bubble Sort
// (Works without OpenMP)
// =====================================
void bubbleSortParallel(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        // Even Phase
        for (int j = 0; j < n - 1; j += 2) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }

        // Odd Phase
        for (int j = 1; j < n - 1; j += 2) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }
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
void printArray(vector<int>& arr, int limit = 20) {

    for (int i = 0; i < limit && i < arr.size(); i++) {

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

    // Generate Random Numbers
    generateRandomArray(arr);

    cout << "\nOriginal Array (First 20 Elements):\n";
    printArray(arr);

    // =====================================
    // Sequential Bubble Sort
    // =====================================

    temp = arr;

    auto start1 = high_resolution_clock::now();

    bubbleSortSequential(temp);

    auto end1 = high_resolution_clock::now();

    double sequentialTime =
        duration<double>(end1 - start1).count();

    cout << "\nSequential Bubble Sort Completed.\n";

    cout << "Sequential Execution Time: "
         << sequentialTime
         << " seconds\n";

    cout << "Sorted Array (First 20 Elements):\n";
    printArray(temp);

    // =====================================
    // Parallel Bubble Sort
    // =====================================

    temp = arr;

    auto start2 = high_resolution_clock::now();

    bubbleSortParallel(temp);

    auto end2 = high_resolution_clock::now();

    double parallelTime =
        duration<double>(end2 - start2).count();

    cout << "\nParallel Bubble Sort Completed.\n";

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