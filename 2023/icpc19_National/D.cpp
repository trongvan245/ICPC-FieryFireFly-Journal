#include <bits/stdc++.h>

using namespace std;

struct matrix {
    vector<vector<long long>> a;
    matrix(vector<vector<long long>> _a) : a(_a){};
    matrix operator*(matrix& other) {
        int n = a.size();
        vector<vector<long long>> ans(n, vector<long long>(n, -1e18));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans[i][j] = max(this->a[i][k] + other.a[k][j], ans[i][j]);
                }
            }
        }
        return matrix(ans);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("D.inp", "r")) {
        freopen("D.inp", "r", stdin);
        freopen("D.out", "w", stdout);
    }

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    vector<int> a(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> cost(m + 1, vector<long long>(m + 1, -1e18));
    cost[m][m] = 0;

    auto bfs = [&](int x, int y, vector<long long>& cost) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vector<vector<bool>> vis(n + 1, vector<bool>(m, false));
        vis[x][y] = true;

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n) {
                cost[y] = a[y];
                continue;
            }
            if (s[x][y] == 'L') {
                if (y == 0) {
                    cost[m] = 0;
                } else if (!vis[x][y - 1]) {
                    vis[x][y - 1] = true;
                    q.push({x, y - 1});
                }
            } else if (s[x][y] == 'R') {
                if (y == m - 1) {
                    cost[m] = 0;
                } else if (!vis[x][y + 1]) {
                    vis[x][y + 1] = true;
                    q.push({x, y + 1});
                }
            } else if (s[x][y] == 'X') {
                cost[m] = 0;
            } else if (s[x][y] == '.') {
                if (!vis[x + 1][y]) {
                    vis[x + 1][y] = true;
                    q.push({x + 1, y});
                }
            } else if (s[x][y] == '?') {
                if (y == 0 || y == m - 1) {
                    cost[m] = 0;
                }
                if (y > 0 && !vis[x][y - 1]) {
                    q.push({x, y - 1});
                    vis[x][y - 1] = true;
                }
                if (y + 1 < m && !vis[x][y + 1]) {
                    q.push({x, y + 1});
                    vis[x][y + 1] = true;
                }
            }
        }
    };
    bfs(0, 0, cost[0]);
    for (int i = 0; i < m; ++i) {
        bfs(0, i, cost[i]);
    }

    matrix mul(cost);
    matrix base(cost);

    for (int i = (k - 1); i; i >>= 1) {
        if (i & 1) {
            base = base * mul;
        }
        mul = mul * mul;
    }

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans = max(ans, base.a[i][j]);
        }
    }
    cout << ans;
}