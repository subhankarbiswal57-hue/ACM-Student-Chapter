#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    long long x;
    cin >> n >> x;
    unordered_map<long long, long long> freq;
    freq[0] = 1;
    long long sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        sum += num;
        count += freq[sum - x];
        freq[sum]++;
    }
    cout << count << endl;
    return 0;
}
