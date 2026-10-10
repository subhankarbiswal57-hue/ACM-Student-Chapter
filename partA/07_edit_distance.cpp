#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    if (!(cin >> s >> t)) return 0;

    int n = s.length();
    int m = t.length();

    // dp[i][j] stores the minimum edit distance between s[0..i-1] and t[0..j-1]
    // Memory optimization: We can just use two rows of size m + 1
    vector<int> prev(m + 1), curr(m + 1);

    // Base case: transforming empty string s to t[0..j-1] requires j insertions
    for (int j = 0; j <= m; ++j) {
        prev[j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        curr[0] = i; // transforming s[0..i-1] to empty string requires i deletions
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                curr[j] = prev[j - 1]; // Characters match, no operation needed
            } else {
                curr[j] = 1 + min({
                    prev[j],     // Delete from s
                    curr[j - 1], // Insert into s
                    prev[j - 1]  // Replace in s
                });
            }
        }
        prev = curr;
    }

    cout << prev[m] << "\n";
    return 0;
}
