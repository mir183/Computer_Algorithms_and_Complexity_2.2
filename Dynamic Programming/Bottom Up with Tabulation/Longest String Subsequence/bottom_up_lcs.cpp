#include<iostream>  
#include<algorithm>
using namespace std;

// Function to find the Longest Common Subsequence (LCS)
int LCS(string s1, string s2, int n, int m) {
    int dp[n+1][m+1];

    // Fill the dp matrix
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            // If either string is empty, LCS length is 0
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // If characters match, increment the LCS length for this sub-problem
            else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            // If characters don't match, take the maximum LCS length from the two sub-problems
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Initialize the LCS string
    string ans = "";
    int i = n, j = m;

    // Build the LCS string from the dp matrix
    while(i > 0 && j > 0) {
        // If characters match, add to the LCS string
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--; 
            j--;
        }
        // If characters don't match, move towards the direction of the maximum LCS length
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    // Reverse the LCS string to get the correct order
    reverse(ans.begin(), ans.end());

    // Print the LCS string
    cout << "LCS: " << ans << endl;

    // Return the length of the LCS
    return dp[n][m];
}

int main() {
    // Prompt the user to enter the two strings
    cout << "Enter both strings: ";
    string s1, s2;
    cin >> s1 >> s2;

    // Calculate the lengths of the strings
    int n = s1.length(), m = s2.length();

    // Call the LCS function and store the result
    int ans = LCS(s1, s2, n, m);

    // Print the length of the LCS
    cout << "Length of LCS: " << ans << endl;
}