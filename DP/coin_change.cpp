#include <iostream>
#include <vector>
using namespace std;

vector<int> d = {1, 4, 5, 10}; // Coin denominations
int k = d.size();

void CHANGE(int n) {
    vector<int> C(n + 1);          // Minimum coins needed for amount i
    vector<int> coinUsed(n + 1);   // Tracks which coin was last used to get to amount i

    C[0] = 0; // Base case

    for (int p = 1; p <= n; p++) {
        int minCoins = n;
        int usedCoin = -1;

        for (int i = 0; i < k; i++) {
            if (p >= d[i]) {
                if (C[p - d[i]] + 1 < minCoins) {
                    minCoins = C[p - d[i]] + 1;
                    usedCoin = d[i]; // Store the coin value
                }
            }
        }

        C[p] = minCoins;
        coinUsed[p] = usedCoin;
    }

    // Print each amount and coins used to make it
    for (int i = 1; i <= n; i++) {
        cout << "Amount " << i << " (Min coins = " << C[i] << "): ";
        int current = i;
        vector<int> coins;

        // Backtrack to find the full list of coins used
        while (current > 0) {
            coins.push_back(coinUsed[current]);
            current -= coinUsed[current];
        }

        // Print the coins used
        for (int coin : coins) {
            cout << coin << " ";
        }
        cout << endl;
    }
}

int main() {
    int amount = 10; // You can change this value
    CHANGE(amount);
    return 0;
}
