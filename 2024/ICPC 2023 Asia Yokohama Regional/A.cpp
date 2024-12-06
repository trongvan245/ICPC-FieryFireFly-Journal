#include <bits/stdc++.h>

using namespace std;

string t = "YOKOHAMA";

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (string &i : s) {
        cin >> i;
    }

    int ans = 0;

    function<void(int, int, int)> dfs = [&](int x, int y, int p) {
        if (p == (int)t.size() - 1) {
            ans++;
        }
        for (int i = 0; i < 4; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u >= 0 && u < n && v >= 0 && v < m) {
                if (s[u][v] == t[p + 1]) {
                    dfs(u, v, p + 1);
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == t[0]) {
                dfs(i, j, 0);
            }
        }
    }

    cout << ans;
}