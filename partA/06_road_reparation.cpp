#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) / Union-Find with path compression and union by rank
struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Union by rank
            if (rank[root_i] < rank[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j])
                rank[root_i]++;
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v;
    long long weight;

    // Sort edges by weight ascending
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Kruskal's algorithm
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_cost += edge.weight;
            edges_count++;
            if (edges_count == n - 1) {
                break;
            }
        }
    }

    // If we managed to connect all n cities with n - 1 edges
    if (edges_count == n - 1) {
        cout << total_cost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
