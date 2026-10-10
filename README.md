# ACM Student Chapter - Competitive Programming Recruitment 2026

This repository contains full, clean, and tested solutions for the **ACM Student Chapter Competitive Programming Domain Recruitment 2026 Tasks**.

## 📌 Profile Handles
- **CSES Handle:** `subhankarbiswal` (or link to your profile)
- **Codeforces Handle:** `subhankarbiswal`
- **LeetCode Handle:** `subhankarbiswal`
- **GitHub:** [subhankarbiswal57-hue](https://github.com/subhankarbiswal57-hue)

---

## 📁 Repository Structure
```text
├── partA/
│   ├── 01_factory_machines.cpp           # CSES 1620 (Binary Search on Answer)
│   ├── 02_movie_festival.cpp             # CSES 1629 (Greedy Interval Scheduling)
│   ├── 03_subarray_sums_ii.cpp           # CSES 1661 (Prefix Sums + Hash Map)
│   ├── 04_counting_rooms.cpp             # CSES 1192 (Connected Components DFS/BFS)
│   ├── 05_shortest_routes_i.cpp          # CSES 1671 (Dijkstra's Algorithm)
│   ├── 06_road_reparation.cpp            # CSES 1675 (Minimum Spanning Tree / Kruskal + DSU)
│   ├── 07_edit_distance.cpp              # CSES 1639 (2D String DP)
│   └── 08_dynamic_range_sum_queries.cpp  # CSES 1648 (Fenwick Tree / Binary Indexed Tree)
├── partB/
│   ├── brute_force.cpp                   # O(N^2) All-Subarrays Brute Force
│   ├── optimized.cpp                     # O(N log N) / O(N) Prefix Sum + Frequency Map
│   └── README.md                         # Detailed write-up, complexity analysis & empirical timings
└── README.md                             # Top-level documentation & detailed problem notes
```

---

## 🧠 Part A: Problem Set Solutions & Detailed Notes

### 1. Factory Machines (CSES 1620)
- **Technique:** Binary Search on Answer (Monotonicity)
- **Complexity:** $\mathcal{O}(n \log(\min(k) \times t))$ Time, $\mathcal{O}(n)$ Space
- **Approach:**
  Given $n$ machines with processing times $k_i$, we need the minimum time required to produce $t$ items. Notice that the total items produced monotonically increases with time $T$:
  $$\text{Total}(T) = \sum_{i=1}^n \left\lfloor \frac{T}{k_i} \right\rfloor$$
  Because $\text{Total}(T)$ is monotonic, we binary search over $T \in [1, \min(k_i) \cdot t]$. For each midpoint candidate, we verify feasibility in $\mathcal{O}(n)$. To prevent 64-bit integer overflow, we exit the sum early as soon as `total >= t`.

---

### 2. Movie Festival (CSES 1629)
- **Technique:** Greedy Interval Scheduling
- **Complexity:** $\mathcal{O}(n \log n)$ Time, $\mathcal{O}(n)$ Space
- **Approach:**
  We are given intervals $[a_i, b_i]$ and want to pick the maximum number of non-overlapping movies. The optimal greedy choice is to always pick the movie that **ends earliest** among all eligible remaining movies. This leaves the maximum possible remaining time for future movies.
  We sort the movies by their ending time $b_i$. We iterate through the sorted list, selecting movie $i$ if its start time $a_i \ge$ the finish time of the last selected movie.

---

### 3. Subarray Sums II (CSES 1661)
- **Technique:** Prefix Sums + Frequency Hash Map
- **Complexity:** $\mathcal{O}(n \log n)$ Time (using `std::map`), $\mathcal{O}(n)$ Space
- **Approach:**
  A subarray from index $i$ to $j$ has sum equal to $x$ if and only if $\text{pref}[j] - \text{pref}[i-1] = x \iff \text{pref}[i-1] = \text{pref}[j] - x$.
  While scanning through the array, we accumulate the running prefix sum $\text{pref}[j]$ and query how many previous prefixes equaled $\text{pref}[j] - x$. We store counts in a map (with base case $\text{count}[0] = 1$). Since negative values are allowed, two-pointers would fail, making this hash map prefix technique the standard and optimal approach.

---

### 4. Counting Rooms (CSES 1192)
- **Technique:** Connected Components on a 2D Grid (DFS / BFS)
- **Complexity:** $\mathcal{O}(n \cdot m)$ Time, $\mathcal{O}(n \cdot m)$ Space (recursion stack)
- **Approach:**
  The building map is represented by an $n \times m$ grid of `#` (walls) and `.` (floor). A room is a connected component of floor squares.
  We scan every cell $(r, c)$. Whenever an unvisited `.` is encountered, we increment the room counter and launch a Depth-First Search (DFS) or Breadth-First Search (BFS) to mark all transitively reachable floor cells in the four cardinal directions as visited (by setting them to `#` in-place).

---

### 5. Shortest Routes I (CSES 1671)
- **Technique:** Dijkstra’s Algorithm with Min-Heap
- **Complexity:** $\mathcal{O}((n + m) \log n)$ Time, $\mathcal{O}(n + m)$ Space
- **Approach:**
  Find the shortest directed paths from city 1 to all other cities with non-negative edge weights.
  We initialize distances $\text{dist}[1] = 0$ and $\text{dist}[v] = \infty$ for all $v \ne 1$. We use a priority queue storing pairs `(distance, vertex)` ordered by minimum distance. At each step, we extract the closest unfinalized vertex $u$, relax all incident directed edges $(u \to v, w)$, and push shorter distances into the priority queue. Standard duplicate state skipping (`if (d > dist[u]) continue;`) ensures optimal runtime.

---

### 6. Road Reparation (CSES 1675)
- **Technique:** Minimum Spanning Tree (MST) / Kruskal’s Algorithm + Disjoint Set Union (DSU)
- **Complexity:** $\mathcal{O}(m \log m)$ Time, $\mathcal{O}(n + m)$ Space
- **Approach:**
  Given a weighted undirected graph of roads, we must find the minimum cost to make all cities reachable from each other.
  We sort all $m$ edges in ascending order of their repair cost. We maintain a DSU structure with both path compression and union-by-rank. We greedily add edges that connect two previously disconnected components. If exactly $n - 1$ edges are accepted, the sum of their weights is printed; otherwise, the graph is disconnected, and we output `IMPOSSIBLE`.

---

### 7. Edit Distance (CSES 1639)
- **Technique:** 2D Dynamic Programming on Strings
- **Complexity:** $\mathcal{O}(n \cdot m)$ Time, $\mathcal{O}(m)$ Space (rolling array)
- **Approach:**
  Calculate the minimum operations (insert, delete, replace) to convert string $s$ of length $n$ to string $t$ of length $m$.
  Let $\text{dp}[i][j]$ be the minimum operations to convert $s[0 \dots i-1]$ to $t[0 \dots j-1]$:
  - If $s[i-1] == t[j-1]$: $\text{dp}[i][j] = \text{dp}[i-1][j-1]$
  - Else: $\text{dp}[i][j] = 1 + \min(\text{dp}[i-1][j] \text{ [delete]}, \text{dp}[i][j-1] \text{ [insert]}, \text{dp}[i-1][j-1] \text{ [replace]})$
  Since computing row $i$ only requires row $i-1$, we optimize memory to $\mathcal{O}(m)$ using two rolling vectors.

---

### 8. Dynamic Range Sum Queries (CSES 1648)
- **Technique:** Fenwick Tree (Binary Indexed Tree)
- **Complexity:** $\mathcal{O}(n \log n)$ initialization, $\mathcal{O}(\log n)$ per point update and range query, $\mathcal{O}(n)$ Space
- **Approach:**
  Supports updating single values at index $k$ and querying the sum in range $[a, b]$ over $q$ operations on an array of size $n$.
  A Fenwick Tree isolates lowest set bits (`idx & -idx`) to maintain prefix sums in a compact 1-indexed array:
  - `add(k, delta)` propagates in $\mathcal{O}(\log n)$.
  - `query(idx)` returns the prefix sum in $\mathcal{O}(\log n)$.
  - Range sum $[a, b]$ is evaluated as $\text{query}(b) - \text{query}(a - 1)$.

---

## ⚡ Part B: Subarray Sums II - Brute Force vs. Optimized

See [`partB/README.md`](file:///partB/README.md) for the complete theoretical breakdown and benchmark results.

### Summary
- **Brute Force:** Computes all $\mathcal{O}(n^2)$ subarray sums. For $n = 200,000$, $\approx 2 \times 10^{10}$ operations, requiring $> 20$ seconds and resulting in **Time Limit Exceeded (TLE)**.
- **Optimized:** Converts subarray sum condition into prefix difference $\text{pref}[j] - \text{pref}[i-1] = x \implies \text{pref}[i-1] = \text{pref}[j] - x$. By tracking prefix frequencies in a map, lookup is $\mathcal{O}(\log n)$ per element, finishing in $< 0.1$ seconds (**Accepted**).

### Timing Benchmark Snapshot
| Input Size ($N$) | Brute Force $\mathcal{O}(N^2)$ | Optimized $\mathcal{O}(N)$ | Speedup Factor |
| :--- | :--- | :--- | :--- |
| $1,000$ | 35.95 ms | 0.56 ms | ~64x |
| $10,000$ | 4,148.38 ms (~4.15s) | 4.26 ms | ~973x |
| $100,000$ | > 65.0 s (Projected) | 34.61 ms | > 5,000x |
