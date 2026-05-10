#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// =====================================
// Function for Minimum
// =====================================
int minval(vector<int>& arr) {

    int minimum = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] < minimum) {

            minimum = arr[i];
        }
    }

    return minimum;
}

// =====================================
// Function for Maximum
// =====================================
int maxval(vector<int>& arr) {

    int maximum = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] > maximum) {

            maximum = arr[i];
        }
    }

    return maximum;
}

// =====================================
// Function for Sum
// =====================================
int sum(vector<int>& arr) {

    int total = 0;

    for (int i = 0; i < arr.size(); i++) {

        total += arr[i];
    }

    return total;
}

// =====================================
// Function for Average
// =====================================
double average(vector<int>& arr) {

    int total = sum(arr);

    return (double)total / arr.size();
}

// =====================================
// Main Function
// =====================================
int main() {

    vector<int> arr =
    {
        10, 20, 5, 40, 25,
        15, 30, 35, 50, 45
    };

    // =====================================
    // Minimum Operation
    // =====================================

    auto start1 = high_resolution_clock::now();

    int minimum = minval(arr);

    auto end1 = high_resolution_clock::now();

    double minTime =
        duration<double>(end1 - start1).count();

    cout << "Minimum Value = "
         << minimum
         << endl;

    cout << "Time for Min Operation = "
         << minTime
         << " seconds\n" << endl;

    // =====================================
    // Maximum Operation
    // =====================================

    auto start2 = high_resolution_clock::now();

    int maximum = maxval(arr);

    auto end2 = high_resolution_clock::now();

    double maxTime =
        duration<double>(end2 - start2).count();

    cout << "Maximum Value = "
         << maximum
         << endl;

    cout << "Time for Max Operation = "
         << maxTime
         << " seconds\n" << endl;

    // =====================================
    // Sum Operation
    // =====================================

    auto start3 = high_resolution_clock::now();

    int totalsum = sum(arr);

    auto end3 = high_resolution_clock::now();

    double sumTime =
        duration<double>(end3 - start3).count();

    cout << "Sum = "
         << totalsum
         << endl;

    cout << "Time for Sum Operation = "
         << sumTime
         << " seconds\n" << endl;

    // =====================================
    // Average Operation
    // =====================================

    auto start4 = high_resolution_clock::now();

    double avg = average(arr);

    auto end4 = high_resolution_clock::now();

    double avgTime =
        duration<double>(end4 - start4).count();

    cout << "Average = "
         << avg
         << endl;

    cout << "Time for Average Operation = "
         << avgTime
         << " seconds\n" << endl;

    return 0;
}