#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate absolute error
double absoluteError(double actual, double measured) {
    return fabs(actual - measured);
}

// Function to calculate relative error
double relativeError(double actual, double measured) {
    return fabs((actual - measured) / actual);
}

// Function to calculate percentage error
double percentageError(double actual, double measured) {
    return relativeError(actual, measured) * 100;
}

int main() {
    double actualValue, measuredValue;

    // Input for actual and measured values
    cout << "Enter the actual value: ";
    cin >> actualValue;

    cout << "Enter the measured value: ";
    cin >> measuredValue;

    // Calculate errors
    double absError = absoluteError(actualValue, measuredValue);
    double relError = relativeError(actualValue, measuredValue);
    double percError = percentageError(actualValue, measuredValue);

    // Display the results
    cout << "\nAbsolute Error: " << absError;
    cout << "\nRelative Error: " << relError;
    cout << "\nPercentage Error: " << percError << "%" << endl;

    return 0;
}
