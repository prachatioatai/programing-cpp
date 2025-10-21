#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <climits> // For INT_MAX

void makeChangeDP(int n, const std::vector<int>& d) {
    std::vector<int> C(n + 1);
    std::vector<int> S(n + 1);

    C[0] = 0;

    // Fill DP table for all amounts from 1 to n.
    for (int p = 1; p <= n; p++) {
        int min_coins = INT_MAX;
        int coin_used = -1;

        for (int coin : d) {
            if (p >= coin && C[p - coin] + 1 < min_coins) {
                min_coins = C[p - coin] + 1;
                coin_used = coin; // Store the coin denomination d[i]
            }
        }
        C[p] = min_coins;
        S[p] = coin_used;

        std::cout << "DP for " << p << ": " << C[p] << " coins -> ";
        int temp_amount = p;
        while (temp_amount > 0) {
            std::cout << S[temp_amount] << " ";
            temp_amount -= S[temp_amount];
        }
        std::cout << std::endl;
    }

    std::cout << "\nFinal DP Result: " << C[n] << " coins -> ";
    int amount = n;
    while (amount > 0) {
        std::cout << S[amount] << " ";
        amount -= S[amount];
    }
    std::cout << std::endl;
}

void makeChangeGreedy(int n, const std::vector<int>& d) {
    std::vector<int> sorted_d = d;
    std::sort(sorted_d.rbegin(), sorted_d.rend());

    int amount_left = n;
    std::vector<int> coins_used;
    
    for (int coin : sorted_d) {
        while (amount_left >= coin) {
            amount_left -= coin;
            coins_used.push_back(coin);
        }
    }

    std::cout << "Greedy Result: " << coins_used.size() << " coins -> ";
    for (int coin : coins_used) {
        std::cout << coin << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter amount: ";
    std::cin >> n;

    const std::vector<int> denominations = {1, 4, 5, 10};

    std::cout << "\nDynamic Programming (Optimal):\n";
    makeChangeDP(n, denominations);

    std::cout << "\nGreedy Algorithm:\n";
    makeChangeGreedy(n, denominations);

    return 0;
}
