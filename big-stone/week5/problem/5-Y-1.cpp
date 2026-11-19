//
// Created by 5600G on 2026-11-19.
//
#include <bits/stdc++.h>
using namespace std;

// n: number of discs, m: numbers per disc, T: number of rotations
// x: disc multiple, d: direction (0 = clockwise, 1 = counter-clockwise), k: steps to rotate
int n, m, T, x, d, k;

// a[i][j] stores the number on the i-th disc at position j (0-indexed)
// 0 means the number has been erased
int a[54][54];

// visited[i][j] marks whether cell (i, j) has an adjacent duplicate to be erased
int visited[54][54];

// ret stores the final sum of remaining numbers
int ret;

// Direction arrays for checking 4 neighbors: Up, Right, Down, Left
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// flag = 1 (true) means NO adjacent duplicates were found in the current turn
// flag = 0 (false) means at least one pair of adjacent duplicates was found
bool flag = 1;

// Function to rotate the 'y'-th disc in direction 'dir' by 'k' steps
void _rotate(int y, int dir, int k) {
    vector<int> v;
    // 1. Copy the numbers on disc 'y' into a temporary 1D vector
    for (int i = 0; i < m; i++) {
        v.push_back(a[y][i]);
    }

    // 2. Use C++ STL rotate(begin, new_first, end):
    //    rotate() shifts elements left so that 'new_first' becomes the first element.
    if (dir == 1) {
        // Counter-clockwise (shift left by k): element at index k moves to index 0
        rotate(v.begin(), v.begin() + k, v.end());
    } else {
        // Clockwise (shift right by k): equivalent to shifting left by (m - k)
        rotate(v.begin(), v.begin() + m - k, v.end());
    }

    // 3. Copy the rotated numbers back onto disc 'y'
    for (int i = 0; i < m; i++) {
        a[y][i] = v[i];
    }
}

// Depth-First Search (DFS) to find all connected cells with the same number
void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        // Neighbor on an inner or outer disc
        int ny = y + dy[i];
        // Neighbor on the same disc; "+ m) % m" wraps around the circle (0 <-> m-1)
        int nx = (x + dx[i] + m) % m;

        // Discs do not wrap vertically: skip if out of bounds (innermost/outermost)
        if (ny < 0 || ny >= n) continue;
        // Skip if already visited
        if (visited[ny][nx]) continue;

        // If the neighbor has the exact same number:
        if (a[y][x] == a[ny][nx]) {
            // Mark both the current cell and the neighbor as part of a duplicate group
            visited[y][x] = visited[ny][nx] = 1;
            // Record that we found at least one duplicate pair
            flag = 0;
            // Continue searching from the neighbor to catch chains of 3 or more
            dfs(ny, nx);
        }
    }
}

// Finds all adjacent identical numbers across all discs and erases them.
// Returns true (1) if NO duplicates were found, or false (0) if any were erased.
bool findAdj() {
    flag = 1; // Assume no duplicates at the start of this round
    memset(visited, 0, sizeof(visited)); // Reset visited array to 0

    // Check every cell on every disc
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;   // Skip already erased numbers
            if (visited[i][j]) continue;  // Skip already checked cells
            dfs(i, j);                    // Search for matching neighbors
        }
    }

    // Erase all marked numbers AFTER searching is completely done
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) {
                a[i][j] = 0; // Set to 0 to represent "erased"
            }
        }
    }

    return flag;
}

// Adjusts remaining numbers based on their average when no duplicates are found
void setAverage() {
    int sum = 0;
    int cnt = 0;

    // 1. Calculate sum and count of all remaining (non-zero) numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            sum += a[i][j];
            cnt++;
        }
    }

    // Guard against division by zero if all numbers have been erased
    if (cnt == 0) return;

    // 2. Cast to double to avoid integer division truncation (e.g., 7 / 2 = 3.5, not 3)
    double av = (double)sum / (double)cnt;

    // 3. Decrease numbers greater than average by 1, increase smaller ones by 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) continue;
            if ((double)a[i][j] > av) a[i][j]--;
            else if ((double)a[i][j] < av) a[i][j]++;
        }
    }
}

int main() {
    // Fast I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Read grid dimensions and number of operations
    cin >> n >> m >> T;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Process each of the T rotation commands
    for (int i = 0; i < T; i++) {
        cin >> x >> d >> k;

        // Rotate all discs whose 1-based number is a multiple of x
        // (In 0-based indexing: x-1, 2x-1, 3x-1, ...)
        for (int j = x - 1; j < n; j += x) {
            _rotate(j, d, k);
        }

        // Look for adjacent duplicates. If none exist (findAdj() returns true),
        // adjust values using the average.
        if (findAdj()) {
            setAverage();
        }
    }

    // Sum all remaining numbers across all discs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ret += a[i][j];
        }
    }

    cout << ret << "\n";
    return 0;
}