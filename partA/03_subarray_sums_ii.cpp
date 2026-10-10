#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    // Map to store frequency of prefix sums encountered so far
    map<long long, int> prefix_counts;
    // Base case: prefix sum of 0 appears once initially (empty prefix)
    prefix_counts[0] = 1;

    long long current_prefix_sum = 0;
    long long total_subarrays = 0;

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        current_prefix_sum += val;

        // If (current_prefix_sum - x) was seen previously, each occurrence
        // forms a valid subarray with sum equal to x
        long long target = current_prefix_sum - x;
        if (prefix_counts.count(target)) {
            total_subarrays += prefix_counts[target];
        }

        prefix_counts[current_prefix_sum]++;
    }

    cout << total_subarrays << "\n";
    return 0;
}
