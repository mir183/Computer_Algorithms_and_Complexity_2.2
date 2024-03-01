#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());  // sort the coins in descending order
    int result = 0;
    for (auto coin : coins) {
        if (amount == 0) {
            break;
        }
        int count = amount / coin;  // find the maximum number of this coin that fits into the remaining amount
        result += count;
        amount -= coin * count;  // subtract the value of the coins from the remaining amount
    }
    if (amount != 0) {  // if there is any remaining amount, the problem cannot be solved with the given coin denominations
        return -1;
    }
    return result;
}

int main() {
    cout << "How many types of coins are there?- ";
    int n;
    cin >> n;
    vector<int> coins(n);
    cout << "Enter the coins: ";
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    int ans = coinChange(coins, amount); // Output the minimum number of coins required
    cout << "Minimum number of coins required: " << ans << endl;
    return 0;
}