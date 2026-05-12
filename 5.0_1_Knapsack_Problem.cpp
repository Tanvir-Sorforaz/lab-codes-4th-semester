//0/1 Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter profit of items: ";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items: ";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int c;
    cout << "Enter knapsack capacity: ";
    cin >> c;

    // DP table using vector
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    // Fill table
    for(int i = 1; i <= n; i++) {

        for(int w = 0; w <= c; w++) {

            if(wt[i-1] > w) {
                dp[i][w] = dp[i-1][w];
            }

            else {

                int take = val[i-1] + dp[i-1][w - wt[i-1]];
                int notTake = dp[i-1][w];

                if(take > notTake)
                    dp[i][w] = take;
                else
                    dp[i][w] = notTake;
            }
        }
    }

    cout << "Maximum value = " << dp[n][c];
    // print the items included in the knapsack
    int w = c;
    cout << "\nItems included in the knapsack: \n";
    for(int i = n; i > 0 && w >= 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            cout << "Item " << i << " (profit: " << val[i-1] << ", weight: " << wt[i-1] << ")\n";
            w -= wt[i-1];
        }
    }


    return 0;
}


/*
Enter number of items: 4
Enter profit of items: 4 3 6 5
Enter weights of items: 3 2 5 4
Enter knapsack capacity: 5
Maximum value = 7
Items included in the knapsack: 
Item 2 (profit: 3, weight: 2)
Item 1 (profit: 4, weight: 3)
*/