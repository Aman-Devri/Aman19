#include <iostream>
#include <cmath>
using namespace std;

// Function representing g(x), where x = g(x)
double g(double x) {
    return (x * x + 2) / 3; // Example: g(x) = (x^2 + 2) / 3
}

// Iteration Method (Fixed-Point Iteration)
void iterationMethod(double x0, double tolerance, int maxIterations) {
    double x1;
    cout << "Iteration\t x0\t\t g(x0)\t\t Error" << endl;

    for (int iteration = 0; iteration < maxIterations; iteration++) {
        // Calculate x1 as g(x0)
        x1 = g(x0);
        cout << iteration + 1 << "\t\t " << x0 << "\t " << x1 << "\t " << fabs(x1 - x0) << endl;

        // Check if the absolute error is within the tolerance
        if (fabs(x1 - x0) < tolerance) {
            cout << "\nThe root is approximately: " << x1 << endl;
            return;
        }

        // Update x0 for the next iteration
        x0 = x1;
    }
    
    cout << "\nMax iterations reached. The root is approximately: " << x1 << endl;
}

int main() {
    double x0, tolerance;
    int maxIterations;

    // Input for initial guess, tolerance, and maximum number of iterations
    cout << "Enter the initial guess (x0): ";
    cin >> x0;

    cout << "Enter the tolerance value: ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    // Call the iteration method
    iterationMethod(x0, tolerance, maxIterations);

    return 0;
}
