#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minEditDist(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int dp[n + 1][m + 1];


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
        }
    }

    return dp[n][m];
}

int main() {
    cout<<"Enter two strings: ";
    string s1,s2;
    cin>>s1>>s2;

    cout << "Min Edit Distance: " << minEditDist(s1, s2) << endl;

    return 0;
}