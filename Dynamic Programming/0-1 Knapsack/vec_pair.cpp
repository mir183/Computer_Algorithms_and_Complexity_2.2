#include <iostream> // for std::cout
#include <vector>   // for std::vector
#include <utility>  // for std::pair
using namespace std;

int knapSack(int W, vector<pair<int,int>>& items){
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (items[i - 1].first <= j)
                dp[i][j] = max(items[i - 1].second + dp[i - 1][j - items[i - 1].first], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}

int main(){
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the total weight of the knapsack: ";
    cin >> W;
    vector<pair<int,int>> items(n);
    cout << "Enter the weight and value of each item:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    int ans = knapSack(W, items);
    cout << "Maximum Profit achieved with this knapsack: " << ans << endl;
    return 0;
}