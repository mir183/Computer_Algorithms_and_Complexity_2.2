#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define inf INT_MAX

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (auto coin : coins) {
            if (coin <= i) {
                if (dp[i - coin] != inf) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
    }
    if (dp[amount] == inf) {
        return -1;
    } else {
        return dp[amount];
    }
}

void printCombinations(vector<int>& coins, int amount, vector<int>& combination, int start) {
    if (amount == 0) {
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i != combination.size() - 1) {
                cout << " + ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = start; i < coins.size(); i++) {
        if (coins[i] <= amount) {
            combination.push_back(coins[i]);
            printCombinations(coins, amount - coins[i], combination, i);
            combination.pop_back();
        }
    }
}



int main() {
    cout << "How many types of coins do you have? ";
    int n;
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coins: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    int amount;
    cin >> amount;
    int ans = coinChange(coins, amount);
    cout << "Minimum number of coins required: " << ans << endl;
    cout << "The combinations are: " << endl;
    vector<int> combination;
    printCombinations(coins, amount, combination, 0);

    return 0;
}

