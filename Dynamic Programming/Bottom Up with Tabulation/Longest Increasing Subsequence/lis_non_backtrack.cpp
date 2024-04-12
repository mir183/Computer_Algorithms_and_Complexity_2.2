#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

int lis(vector<int> &arr, int n) {  
    vector<int> lis(n, 1); 

    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < i; j++) {   
            if (arr[i] > arr[j]) {  
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    } 

    return *max_element(lis.begin(), lis.end()); 
}  

int main() {       
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Length of LIS is " << lis(arr, n) << "\n";
    return 0;  
}  