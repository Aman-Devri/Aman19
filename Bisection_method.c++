#include <iostream>
#include <cmath>
using namespace std;

// Function to find root of
double func(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

// Bisection Method
void bisection(double a, double b, double tolerance) {
    double c;
    
    // Check if the signs of f(a) and f(b) are the same
    if (func(a) * func(b) >= 0) {
        cout << "Incorrect a and b, function has same signs at both endpoints." << endl;
        return;
    }

    cout << "a\t\tb\t\tc\t\tf(c)" << endl;

    // Continue the process until the interval is smaller than the tolerance
    while ((b - a) >= tolerance) {
        c = (a + b) / 2; // Midpoint
        cout << a << "\t" << b << "\t" << c << "\t" << func(c) << endl;

        // Check if midpoint is the root
        if (func(c) == 0.0)
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

    // Input for intervals a and b, and tolerance
    cout << "Enter the values of a and b: ";
    cin >> a >> b;

    cout << "Enter the tolerance value: ";
    cin >> tolerance;

    // Call the Bisection method
    bisection(a, b, tolerance);

    return 0;
}
