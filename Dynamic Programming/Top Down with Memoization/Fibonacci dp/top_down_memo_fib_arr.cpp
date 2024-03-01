#include <iostream>
using namespace std;

// Initialize an array with -1 for memoization
int* memo;

int fib(int n) {
    if (n ==0 || n == 1) {
        return n;
    }

    // Check if we have already computed fib(n)
    if (memo[n] != -1) {
        return memo[n];
    }

    // Otherwise, compute it by calling fib recursively, then store and return the result
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}


int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    memo = new int[n + 1];  // Dynamically allocate memoization array
    fill_n(memo, n + 1, -1);  // Initialize all elements to -1
    int result = fib(n);
    // Print the result
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    delete[] memo;  // Don't forget to delete the dynamically allocated array
    return 0;
}