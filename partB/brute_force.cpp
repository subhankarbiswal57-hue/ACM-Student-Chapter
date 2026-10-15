#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == x) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
