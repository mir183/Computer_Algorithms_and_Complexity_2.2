#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;

    // Constructor with a more readable form  
    Item(int w, int v) {
        weight = w;
        value = v;
        ratio = static_cast<double>(v) / w;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.ratio > item2.ratio;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    for (const auto& item : items) {
        if (capacity <= 0) {
            break;
        }

        int selectedWeight = min(item.weight, capacity);
        totalValue += selectedWeight * item.ratio;

        capacity -= selectedWeight;
    }

    return totalValue;
}

int main() {
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;

    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        int weight, value;
        cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    double result = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack: " << result << endl;

    return 0;
}