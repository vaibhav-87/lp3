#include <bits/stdc++.h>
using namespace std;

// Structure for Item which stores weight and corresponding value of Item
struct Item {
    float weight;
    int value;
};

// Node structure to store information of decision tree
struct Node {
    int level, profit, bound;
    float weight;
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Returns bound of profit in subtree rooted with u
int bound(Node u, int n, int W, const vector<Item>& arr) {
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Returns maximum profit we can get with capacity W
int knapsack(int W, vector<Item>& arr, int n) {
    sort(arr.begin(), arr.end(), cmp);

    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;
        else if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = v.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main() {
    int W;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<Item> arr;
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter Profit and Weight of Item " << i + 1 << ": ";
        cin >> profit >> weight;
        arr.push_back({(float)weight, profit});
    }

    cout << "Maximum possible profit = " << knapsack(W, arr, n);

    return 0;
}