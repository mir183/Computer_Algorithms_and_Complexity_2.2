#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Fibonacci number using bottom-up tabulation
int fib(int n) {
    // Base case: if n is 0 or 1, return n
    if (n <= 1)
        return n;

    // Create a vector F of size n+1 to store the Fibonacci numbers
    vector<int> F(n + 1);
    // Initialize the first two Fibonacci numbers
    F[0] = 0;
    F[1] = 1;

    // Calculate the nth Fibonacci number
    for(int i = 2; i <= n; i++)
        F[i] = F[i - 2] + F[i - 1]; // F[i] is the sum of the previous two Fibonacci numbers

    // Return the nth Fibonacci number
    return F[n];
}

int main() { 
    // Prompt the user to enter the value of n
    cout << "Enter the value of n: ";
    int n;
    // Read the value of n from the user
    cin >> n;
    // Calculate the nth Fibonacci number
    int result = fib(n);
    // Print the result
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    // Return 0 to indicate successful execution
    return 0;
}