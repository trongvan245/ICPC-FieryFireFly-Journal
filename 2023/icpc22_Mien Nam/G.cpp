// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 10005;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, m, ans;
int a[N], d[N], dp[N][N];
bool p[N][N];
vector<int> adj[N];
vector<int> M;

void dfs(int u, int p) {
    d[u] = p;
    M.pb(u);
    for (int v : adj[u]) {
        if (!d[v])
            dfs(v, p);
    }
}

void xuly() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int c = 0;
    for (int i = 1; i <= n; ++i)
        if (!d[i]) {
            M.clear();
            dfs(i, i);
            if (M.size() == n)
                c = 1;
            for (int v : M)
                for (int u : M)
                    p[v][a[u]] = true;
        }

    if (c) {
        cout << n << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[i][j]) {
                // cout << i << " " << j << '\n';
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i - 1][j]});
            ans = max(ans, dp[i][j]);
            // cout << i << " " << j << " " << dp[i][j] << '\n';
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.