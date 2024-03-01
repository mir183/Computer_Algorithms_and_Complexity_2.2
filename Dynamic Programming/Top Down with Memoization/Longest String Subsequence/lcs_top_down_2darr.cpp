#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001]; // 2D array for memoization

int LCS(string s1, string s2, int n, int m){
    // Base Case
    if(n == 0 || m == 0)
        return 0;
    
    // If the subproblem has already been computed
    if(dp[n][m] != -1)
        return dp[n][m];
    
    // If last characters match
    if(s1[n-1] == s2[m-1])
        {
            return dp[n][m] = 1 + LCS(s1, s2, n-1, m-1);
            }
    else{
        // If last characters don't match
        return dp[n][m] = max(LCS(s1, s2, n, m-1), LCS(s1, s2, n-1, m));
        }
}

int main(){
    string s1, s2;
    cout << "Enter both strings: ";
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();


    // Initialize the dp array to -1
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = -1;

    int length = LCS(s1, s2, n, m);
    cout << "Length of Longest Common Subsequence: " << length << endl;
}