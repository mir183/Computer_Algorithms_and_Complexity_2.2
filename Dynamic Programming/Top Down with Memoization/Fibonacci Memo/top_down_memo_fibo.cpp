#include <iostream>
#include <vector>
using namespace std;

// Initialize a vector with -1 for memoization
vector<int> memo;

int fib(int n) {
    // Base cases
    if (n <= 1) {
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
    cout<<"Enter the value of n: ";
    int n;
    cin>>n;
    memo = vector<int>(n + 1, -1);  // Initialize memoization vector
    int result = fib(n);
    // Print the result
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}