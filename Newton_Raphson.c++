#include <iostream>
#include <cmath>
using namespace std;

// Function whose root we are trying to find
double func(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

// Derivative of the function
double derivativeFunc(double x) {
    return 3 * x * x - 1; // Derivative: f'(x) = 3x^2 - 1
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tolerance, int maxIterations) {
    double x1;
    
    cout << "Iteration\t x0\t\t f(x0)\t\t f'(x0)\t\t x1" << endl;
    
    for (int iteration = 0; iteration < maxIterations; iteration++) {
        // Calculate x1 using the Newton-Raphson formula
        x1 = x0 - func(x0) / derivativeFunc(x0);

        cout << iteration + 1 << "\t\t " << x0 << "\t " << func(x0) << "\t " 
             << derivativeFunc(x0) << "\t " << x1 << endl;

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

    // Call the Newton-Raphson method
    newtonRaphson(x0, tolerance, maxIterations);

    return 0;
}
