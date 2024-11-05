#include <bits/stdc++.h>
using namespace std;

// Structure for an item that stores weight and corresponding profit of the item
struct Item {
	int profit, weight;

	// Constructor
	Item(int profit, int weight) {
		this->profit = profit;
		this->weight = weight;
	}
};

// Comparison function to sort items by profit/weight ratio in descending order
bool cmp(struct Item a, struct Item b) {
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item>& arr, int N) {
	// Sorting items based on profit/weight ratio
	sort(arr.begin(), arr.end(), cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		// If adding the item doesn't exceed capacity, add it fully
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		// If the item can't be added fully, add a fraction of it
		else {
			finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning the maximum profit
	return finalvalue;
}

int main() {
	int W, N;
	cout << "Enter Maximum Weight Capacity of Knapsack: ";
	cin >> W;
	cout << "Enter Number of Items: ";
	cin >> N;

	vector<Item> arr;
	for (int i = 0; i < N; i++) {
		int profit, weight;
		cout << "Enter Profit and Weight of Item " << i + 1 << ": ";
		cin >> profit >> weight;
		arr.push_back(Item(profit, weight));
	}

	cout << "Maximum profit in Knapsack = " << fractionalKnapsack(W, arr, N) << endl;
	return 0;
}
