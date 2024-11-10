#include <iostream>
#include <cmath>
using namespace std;

// Function to find the root of
double func(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

// Regula Falsi Method
void regulaFalsi(double a, double b, double tolerance, int maxIterations) {
    double c;
    
    // Check if the signs of f(a) and f(b) are the same
    if (func(a) * func(b) >= 0) {
        cout << "Incorrect a and b, function has same signs at both endpoints." << endl;
        return;
    }

    cout << "a\t\tb\t\tc\t\tf(c)" << endl;

    // Perform iterations
    for (int i = 0; i < maxIterations; i++) {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a)); // Regula Falsi formula

        cout << a << "\t" << b << "\t" << c << "\t" << func(c) << endl;

        // Check if c is the root within the given tolerance
        if (fabs(func(c)) <= tolerance)
            break;

        // Update the interval
        if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nThe root is approximately: " << c << endl;
}

int main() {
    double a, b, tolerance;
    int maxIterations;

    // Input for intervals a and b, tolerance, and max iterations
    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    cout << "Enter the tolerance value: ";
    cin >> tolerance;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    // Call the Regula Falsi method
    regulaFalsi(a, b, tolerance, maxIterations);

    return 0;
}
