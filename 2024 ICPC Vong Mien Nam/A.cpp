#include <bits/stdc++.h>
#define Nekan "test"
using namespace std;
#define ll long long


// 3D Binary Indexed Tree to store Partial Sums
ll BIT[120][120][120];
ll val[120][120][120];
int N;
int n, m;
// Function to handle updates
void updateQuery(int x, int y, int z, ll val) {
    int i, j, k;
    // Update all the cells that store the partial sum of
    // cell (x, y, z)
    for (i = x; i <= N; i += i & -i) {
        for (j = y; j <= N; j += j & -j) {
            for (k = z; k <= N; k += k & -k) {
                BIT[i][j][k] += val;
            }
        }
    }
}

// Function to get the prefix sum from (0, 0, 0) to
// (x, y, z)
ll sumQuery(int x, int y, int z) {
    ll sum = 0;
    int i, j, k;
    // Calculate prefix sum by summing up all the cells
    // storing the partial sums
    for (i = x; i > 0; i -= i & -i) {
        for (j = y; j > 0; j -= j & -j) {
            for (k = z; k > 0; k -= k & -k) {
                sum += BIT[i][j][k];
            }
        }
    }
    return sum;
}

// Function to get the submatrix sum from (x, y, z) to (X,
// Y, Z)
ll matrixSumQuery(int x, int y, int z, int X, int Y, int Z) {
    return sumQuery(X, Y, Z) - sumQuery(x, Y, Z) - sumQuery(X, y, Z) -
           sumQuery(X, Y, z) + sumQuery(x, y, Z) + sumQuery(x, Y, z) +
           sumQuery(X, y, z) - sumQuery(x, y, z);
}

void sol() {
    memset(BIT, 0, sizeof(BIT));
    cin >> n >> m;
    n += 5;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                BIT[i][j][k] = val[i][j][k] = 0;
    N = n;
    for (int i = 1; i <= m; ++i) {
        string t;
        cin >> t;
        if (t == "UPDATE") {
            int x, y, z;
            ll w;
            cin >> x >> y >> z >> w;
            // --x, --y, --z;
            updateQuery(x + 1, y + 1, z + 1, w - val[x][y][z]);
            val[x][y][z] = w;
        } else {
            int x, y, z, u, v, k;
            cin >> x >> y >> z >> u >> v >> k;
            // --x, --y, --z, --u, --v, --k;
            cout << matrixSumQuery(x, y, z, u + 1, v + 1, k + 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int t;
    cin >> t;
    while (t--)
        sol();
    return 0;

    // int Q, type, x, y, z, val, X, Y, Z;

    // // Predefined input values
    // N = 10;
    // Q = 6;
    // ll queries[Q][7] = {{1, 0, 0, 6, 6},  {1, 9, 9, 9, 10},
    //                     {1, 8, 5, 9, 5},  {2, 3, 4, 5, 9, 10, 9},
    //                     {1, 6, 6, 1, 23}, {2, 0, 0, 0, 8, 9, 10}};

    // for (int i = 0; i < Q; i++) {
    //     type = queries[i][0];
    //     if (type == 1) {
    //         x = queries[i][1];
    //         y = queries[i][2];
    //         z = queries[i][3];
    //         val = queries[i][4];
    //         updateQuery(x + 1, y + 1, z + 1, val);
    //     } else {
    //         x = queries[i][1];
    //         y = queries[i][2];
    //         z = queries[i][3];
    //         X = queries[i][4];
    //         Y = queries[i][5];
    //         Z = queries[i][6];
    //         cout << matrixSumQuery(x, y, z, X + 1, Y + 1, Z + 1) << "\n";
    //     }
    // }
    // return 0;
}