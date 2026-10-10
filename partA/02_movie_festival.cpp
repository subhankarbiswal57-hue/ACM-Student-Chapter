#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a movie interval
struct Movie {
    int start;
    int end;
};

// Comparator to sort movies by ending time in ascending order
bool compareMovies(const Movie& a, const Movie& b) {
    return a.end < b.end;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Movie> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].start >> movies[i].end;
    }

    // Greedy strategy: sort intervals by end time
    sort(movies.begin(), movies.end(), compareMovies);

    int count = 0;
    int current_end = 0;

    for (int i = 0; i < n; ++i) {
        // If the current movie starts after or when the previous chosen movie ended
        if (movies[i].start >= current_end) {
            count++;
            current_end = movies[i].end;
        }
    }

    cout << count << "\n";
    return 0;
}
