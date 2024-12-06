#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("A.inp", "r")) {
        freopen("A.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    s[n] = string(m, '.');

    queue<pair<int, int>> q;
    vector<vector<int>> f(n + 1, vector<int>(m, -1));
    q.push({0, 0});
    f[0][0] = 0;

    int ans = 1e9;
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n) {
            ans = min(ans, f[x][y]);
            continue;
        }

        // stay at same cell
        int u = x, v = (y + m - 1) % m;
        if (f[u][v] == -1 && s[u][v] != 'M' && s[u][y] != 'M') {
            f[u][v] = f[x][y] + 1;
            q.push({u, v});
        }

        u = x + 1, v = (y + m - 1) % m; // move down
        if (f[u][v] == -1 && s[u][v] != 'M' && s[u][y] != 'M') {
            f[u][v] = f[x][y] + 1;
            q.push({u, v});
        }

        u = x - 1, v = (y + m - 1) % m; // move up
        if (u >= 0 && f[u][v] == -1 && s[u][v] != 'M' && s[u][y] != 'M') {
            f[u][v] = f[x][y] + 1;
            q.push({u, v});
        }

        // move left
        u = x, v = (y + m * 3 - 2) % m;
        if (s[u][(y + m * 3 - 1) % m] != 'M' &&
            s[u][(y + m * 3 - 2) % m] != 'M' && f[u][v] == -1) {
            f[u][v] = f[x][y] + 1;
            q.push({u, v});
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
}