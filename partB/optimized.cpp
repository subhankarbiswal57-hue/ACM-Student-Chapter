#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Optimized approach: Prefix sums with frequency hash map
// Time Complexity: O(n log n) with std::map (or O(n) average with custom/gp_hash_table)
// Space Complexity: O(n)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    map<long long, int> prefix_counts;
    // Prefix sum 0 exists by default (empty subarray before index 0)
    prefix_counts[0] = 1;

    long long current_prefix = 0;
    long long count = 0;

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        current_prefix += val;

        long long target = current_prefix - x;
        if (prefix_counts.count(target)) {
            count += prefix_counts[target];
        }

        prefix_counts[current_prefix]++;
    }

    cout << count << "\n";
    return 0;
}
