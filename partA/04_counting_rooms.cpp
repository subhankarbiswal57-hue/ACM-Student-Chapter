#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> grid;

// Direction vectors for moving up, down, left, right
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// Depth-First Search to visit all connected floor tiles of a room
void dfs(int r, int c) {
    grid[r][c] = '#'; // Mark as visited by turning it into a wall

    for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        // Check boundary conditions and if the cell is an unvisited floor
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.') {
            dfs(nr, nc);
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int room_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // When an unvisited floor tile is found, start a DFS traversal
            if (grid[i][j] == '.') {
                room_count++;
                dfs(i, j);
            }
        }
    }

    cout << room_count << "\n";
    return 0;
}
