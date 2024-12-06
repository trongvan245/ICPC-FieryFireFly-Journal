#include <bits/stdc++.h>

using namespace std;

int f[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                f[i][j] = 1e8;
            } else {
                f[i][j] = 0;
            }
        }
    }

    vector<tuple<int, int, int>> e;

    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        f[u][v] = min(f[u][v], c);
        f[v][u] = min(f[v][u], c);
        e.emplace_back(u, v, c);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    int ans = 0;
    for (auto [u, v, c] : e) {
        if (f[a][u] + f[v][b] + c == f[a][b] ||
            f[a][v] + f[u][b] + c == f[a][b]) {

        } else {
            ans += c;
        }
    }
    cout << ans;
}