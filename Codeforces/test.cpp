#include <bits/stdc++.h>

using namespace std;

// Function to check if we can form decks of size s
bool canFormDecks(const vector<int>& a, int n, int k, int s) {
    int totalRequired = 0;

    for (int i = 0; i < n; ++i) {
        // Calculate how many decks we can make with a[i] cards
        int currentCards = a[i];
        int maxDecks = currentCards / s;
        totalRequired += maxDecks;
        
        // Calculate how many more cards we would need to make (maxDecks + 1) decks
        if (maxDecks * s < currentCards) {
            // We can already make maxDecks decks, no more cards needed
            continue;
        }
        
        // How many cards are needed to make one more deck
        int neededForNextDeck = s - (currentCards % s);
        if (neededForNextDeck < s) {
            totalRequired += 1; // Need one more deck
            totalRequired += (neededForNextDeck > k) ? 0 : (neededForNextDeck - 1) / s + 1; // Count extra cards needed
        }
    }

    return totalRequired <= k;
}

// Main function to find the maximum deck size
int maxDeckSize(const vector<int>& a, int n, int k) {
    int low = 1, high = accumulate(a.begin(), a.end(), 0) + k;
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (canFormDecks(a, n, k, mid)) {
            result = mid; // mid is a feasible size
            low = mid + 1; // Try for a bigger size
        } else {
            high = mid - 1; // Try a smaller size
        }
    }

    return result;
}

int main() {
    int n, k;
    // cout << "Enter number of types of cards (n) and number of coins (k): ";
    cin >> n >> k;
    
    vector<int> a(n);
    // cout << "Enter the number of cards of each type: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = maxDeckSize(a, n, k);
    cout << "Maximum possible size of a deck: " << result << endl;

    return 0;
}
