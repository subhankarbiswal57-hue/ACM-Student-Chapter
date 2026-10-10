#include <iostream>
#include <vector>

using namespace std;

// Brute-force approach: checks every possible subarray [i, j]
// Time Complexity: O(n^2)
// Space Complexity: O(n)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;

    // Check all subarrays starting at index i and ending at index j
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += a[j];
            if (current_sum == x) {
                count++;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
