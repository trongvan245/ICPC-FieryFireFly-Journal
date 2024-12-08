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

const int N = 2e5 + 5;
const long long mod = 998244353;

using namespace std;

int inv(int a) {
    ll res = 1, t = a;
    int n = mod - 2;
    while (n) {
        if (n & 1)
            res = res * t % mod;
        t = t * t % mod;
        n /= 2;
    }
    return res;
}

struct LCA {
    int n, m;
    vector<vector<int>> sp;
    vector<int> h;
    LCA(int x) {
        n = x;
        m = log2(n) + 1;

        sp.assign(n + 5, vector<int>(m + 5, 0));
        h.assign(n + 5, 0);
    }
    void build() {
        for (int j = 1; j <= m; ++j)
            for (int i = 1; i <= n; ++i) {
                int nxt = sp[i][j - 1];
                if (nxt == 0)
                    continue;
                sp[i][j] = sp[nxt][j - 1];
            }
    }

    int get(int u, int v) {
        if (h[u] < h[v])
            swap(u, v);
        for (int j = m; j >= 0; --j) {
            int U = sp[u][j];
            if (U == 0 || h[U] < h[v])
                continue;
            u = U;
        }

        if (u == v)
            return u;

        for (int j = m; j >= 0; --j) {
            int U = sp[u][j], V = sp[v][j];
            if (U == 0 || V == 0 || U == V)
                continue;
            u = U, v = V;
        }

        return sp[u][0];
    }

    pii get_pre(int u, int v) {

        if (h[u] < h[v])
            swap(u, v);
        for (int j = m; j >= 0; --j) {
            int U = sp[u][j];
            if (U == 0 || h[U] < h[v])
                continue;
            u = U;
        }
        // assert(u == v);
        for (int j = m; j >= 0; --j) {
            int U = sp[u][j], V = sp[v][j];
            if (U == 0 || V == 0 || U == V)
                continue;
            u = U, v = V;
        }
        return {u, v};
    }
};

void xuly() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> up(n + 1), down(n + 1), f(n + 1), dp(n + 1), d(n + 1);
    LCA lca(n);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;

        adj[p].pb(i);
        lca.sp[i][0] = p;
    }

    function<void(int)> dfs_up = [&](int u) {
        up[u] = 1;
        for (int v : adj[u]) {
            lca.h[v] = lca.h[u] + 1;
            dfs_up(v);
            up[u] = 1ll * up[u] * (up[v] + 1) % mod;
            dp[u] = (dp[u] + dp[v]) % mod;
        }
        dp[u] = (dp[u] + up[u]) % mod;
    };
    lca.build();
    dfs_up(1);

    f[1] = up[1];
    function<void(int, int, ll)> dfs_down = [&](int u, int sum, ll top) {
        d[u] = sum;
        ll s = 0;
        (top += 1) % mod;
        for (int v : adj[u]) {
            s = (s + dp[v]) % mod;
            top = top * (up[v] + 1) % mod;
        }

        for (int v : adj[u]) {
            int down = top * inv(up[v] + 1) % mod;
            f[v] = (f[u] + up[v]) % mod;
            dfs_down(v, (mod + sum + s - dp[v] + down) % mod, down);
        }
    };
    dfs_down(1, 0, 0);
    int ans = dp[1];

    while (q--) {
        int u, v;
        cin >> u >> v;
        int p = lca.get(u, v);
        // cout << p << '\n';

        if (p == u)
            swap(u, v);
        int grandparent = lca.sp[p][0];

        int t1 = (mod + f[u] - f[p]) % mod;
        if (p == v) {
            cout << (mod * mod + ans - d[p] - (1ll * dp[p] - t1 - up[p])) % mod << '\n';
        } else {
            int t2 = (mod + f[v] - f[p]) % mod;
            // cout << d[p] << '\n';
            // cout << dp[p] << " " << t1 << " " << t2 << " " << up[p] << "\n\n";
            cout << (mod * mod + ans - d[p] - (1ll * dp[p] - t1 - t2 - up[p])) % mod << '\n';
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
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.