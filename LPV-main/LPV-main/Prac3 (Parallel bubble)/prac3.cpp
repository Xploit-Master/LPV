#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

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
// Parallel Bubble Sort using OpenMP
// =====================================
void bubbleSortParallel(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n; i++) {

        // Even Phase
        #pragma omp parallel for
        for (int j = 0; j < n - 1; j += 2) {

            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
            }
        }

        // Odd Phase
        #pragma omp parallel for
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

    double start, end;

    // =====================================
    // Sequential Bubble Sort
    // =====================================
    temp = arr;

    start = omp_get_wtime();

    bubbleSortSequential(temp);

    end = omp_get_wtime();

    cout << "\nSequential Bubble Sort Completed.\n";

    cout << "Sequential Execution Time: "
         << (end - start)
         << " seconds\n";

    cout << "Sorted Array (First 20 Elements):\n";
    printArray(temp);

    // =====================================
    // Parallel Bubble Sort
    // =====================================
    temp = arr;

    start = omp_get_wtime();

    bubbleSortParallel(temp);

    end = omp_get_wtime();

    cout << "\nParallel Bubble Sort Completed.\n";

    cout << "Parallel Execution Time: "
         << (end - start)
         << " seconds\n";

    cout << "Sorted Array (First 20 Elements):\n";
    printArray(temp);

    // =====================================
    // Speedup Calculation
    // =====================================

    double sequentialTime, parallelTime;

    temp = arr;

    start = omp_get_wtime();
    bubbleSortSequential(temp);
    end = omp_get_wtime();

    sequentialTime = end - start;

    temp = arr;

    start = omp_get_wtime();
    bubbleSortParallel(temp);
    end = omp_get_wtime();

    parallelTime = end - start;

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