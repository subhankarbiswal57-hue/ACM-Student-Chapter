#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree (Binary Indexed Tree) for point update and prefix sum queries
// 1-indexed implementation
struct FenwickTree {
    int n;
    vector<long long> tree;

    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    // Add delta to element at index idx
    void add(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += delta;
        }
    }

    // Query sum in range [1, idx]
    long long query(int idx) const {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    // Query sum in range [l, r]
    long long query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> arr(n + 1);
    FenwickTree ft(n);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        ft.add(i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Update value at position k to u
            int k;
            long long u;
            cin >> k >> u;
            long long diff = u - arr[k];
            arr[k] = u;
            ft.add(k, diff);
        } else if (type == 2) {
            // Query sum in range [a, b]
            int a, b;
            cin >> a >> b;
            cout << ft.query(a, b) << "\n";
        }
    }

    return 0;
}
