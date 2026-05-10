#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

using namespace std;

#define SIZE 10000

// =====================================
// Merge Function
// =====================================
void merge(vector<int>& arr, int left, int mid, int right) {

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

    // Copy remaining elements
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
// Parallel Merge Sort
// =====================================
void mergeSortParallel(vector<int>& arr,
                       int left,
                       int right,
                       int depth) {

    if (left < right) {

        int mid = (left + right) / 2;

        // Stop creating threads after depth limit
        if (depth <= 0) {

            mergeSortSequential(arr, left, mid);

            mergeSortSequential(arr, mid + 1, right);
        }
        else {

            #pragma omp parallel sections
            {

                #pragma omp section
                mergeSortParallel(arr,
                                  left,
                                  mid,
                                  depth - 1);

                #pragma omp section
                mergeSortParallel(arr,
                                  mid + 1,
                                  right,
                                  depth - 1);
            }
        }

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

    // Generate Random Array
    generateRandomArray(arr);

    cout << "\nOriginal Array (First 20 Elements):\n";
    printArray(arr);

    double start, end;

    // =====================================
    // Sequential Merge Sort
    // =====================================

    temp = arr;

    start = omp_get_wtime();

    mergeSortSequential(temp,
                        0,
                        SIZE - 1);

    end = omp_get_wtime();

    double sequentialTime = end - start;

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

    start = omp_get_wtime();

    mergeSortParallel(temp,
                      0,
                      SIZE - 1,
                      4);

    end = omp_get_wtime();

    double parallelTime = end - start;

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