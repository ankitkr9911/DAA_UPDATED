#include <stdio.h>

// A function to find the minimum element's index in an array
int findMin(int arr[], int start, int end) {
    int min = arr[start];
    int minIndex = start;
    for (int i = start; i <= end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// A function to find the maximum element's index in an array
int findMax(int arr[], int start, int end) {
    int max = arr[start];
    int maxIndex = start;
    for (int i = start; i <= end; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// A function to find the maximum profit in a given range using divide and conquer
int maxProfitDivideAndConquer(int prices[], int start, int end) {
    // Base case: if the array has less than two elements, no profit can be made
    if (start >= end) {
        return 0;
    }

    // Divide the array into two halves
    int mid = (start + end) / 2;

    // Find the maximum profit in the left half
    int leftProfit = maxProfitDivideAndConquer(prices, start, mid);

    // Find the maximum profit in the right half
    int rightProfit = maxProfitDivideAndConquer(prices, mid + 1, end);

    // Find the minimum price in the left half and the maximum price in the right half
    int minPriceIndex = findMin(prices, start, mid);
    int maxPriceIndex = findMax(prices, mid + 1, end);

    // Calculate the profit by buying at the minimum price in the left half and selling at the maximum price in the right half
    int crossProfit = prices[maxPriceIndex] - prices[minPriceIndex];

    // Return the maximum of the three profits
    return (leftProfit > rightProfit) ? (leftProfit > crossProfit ? leftProfit : crossProfit) : (rightProfit > crossProfit ? rightProfit : crossProfit);
}

int main() {
    int prices[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(prices) / sizeof(prices[0]);

    int maxProfit = maxProfitDivideAndConquer(prices, 0, n - 1);

    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
