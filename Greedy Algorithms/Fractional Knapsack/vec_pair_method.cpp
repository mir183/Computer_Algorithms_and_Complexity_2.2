#include<iostream>
#include<vector> 
#include<algorithm> // for sort
#include<iomanip> // for setprecision

using namespace std;

// Comparison function to sort items by value-to-weight ratio
bool comp(pair<int,int>& a, pair<int,int>& b){
    return (double)a.first / a.second > (double)b.first / b.second;
}

int main(){
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> w;

    // Vector to store value-weight pairs
    vector<pair<int,int>>pvw(n);

    cout << "Enter the value and weight of the items" << endl;
    for(int i = 0; i < n; i++){
        cin >> pvw[i].first >> pvw[i].second;
    }

    // Sort items by value-to-weight ratio
    sort(pvw.begin(), pvw.end(), comp);

    double ans = 0; // Total value of items in knapsack

    for(int i = 0; i < n; i++){
        if(w == 0){ // If knapsack is full, break out of loop
            break;
        }

        // Take as much of current item as possible
        int take = min(w, pvw[i].second);
        ans += take * (double)pvw[i].first / pvw[i].second; // Update total value
        w -= take; // Update remaining weight
    }

    // Print maximum value that can be obtained
    cout << "Maximum value in the knapsack: " << fixed << setprecision(3) << ans << endl;

    return 0;
}