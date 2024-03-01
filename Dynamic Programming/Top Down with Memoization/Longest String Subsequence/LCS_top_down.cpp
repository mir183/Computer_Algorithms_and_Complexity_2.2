#include<bits/stdc++.h>
using namespace std;

// Function to find the length of Longest Common Subsequence
int LCS(string s1, string s2, int n, int m, vector<vector<int>>& dp) {
    // Base Case
    if(n == 0 || m == 0)
        return 0;

    // If the subproblem has already been solved, return the stored result
    if(dp[n][m] != -1)
        return dp[n][m];

    // If last characters of s1 and s2 are same
    if(s1[n-1] == s2[m-1])
        return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1, dp);

    // If last characters of s1 and s2 are not same
    else
        return dp[n][m] = max(LCS(s1, s2, n, m-1, dp), LCS(s1, s2, n-1, m, dp));
}

int main() {
    string s1, s2;
    cout << "Enter both strings: ";
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // Create a memoization table, initialized with -1
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    int ans= LCS(s1, s2, n, m, dp);
    cout << "Length of Longest Common Subsequence: " << ans << endl;

    return 0;
}