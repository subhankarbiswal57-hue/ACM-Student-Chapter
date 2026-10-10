#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it's possible to make at least 't' products in 'time_limit' time
bool canProduce(const vector<long long>& k, long long t, long long time_limit) {
    long long total_products = 0;
    for (long long time_per_product : k) {
        total_products += time_limit / time_per_product;
        if (total_products >= t) {
            return true;
        }
    }
    return total_products >= t;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;

    vector<long long> k(n);
    long long min_time = 1e18;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        min_time = min(min_time, k[i]);
    }

    // Binary search on the answer [low, high]
    long long low = 1;
    long long high = min_time * t;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canProduce(k, t, mid)) {
            ans = mid;
            high = mid - 1; // Try to find a smaller time
        } else {
            low = mid + 1;  // Need more time
        }
    }

    cout << ans << "\n";
    return 0;
}
