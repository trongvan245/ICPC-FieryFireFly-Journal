#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> par;
    int n;

  public:
    DSU(int _n) : n(_n), par(vector<int>(_n + 5, -1)) {}
    int root(int u) { return (par[u] < 0 ? u : par[u] = root(par[u])); }
    bool join(int u, int v) {
        if ((u = root(u)) == (v = root(v))) {
            return false;
        }
        if (par[u] > par[v]) {
            swap(u, v);
        }
        par[u] += par[v];
        par[v] = u;
        return true;
    }
    int sz(int u) { return -par[root(u)]; }
};

struct edge {
    int u, v, c;
    void read() {
        cin >> u >> v >> c;
        u--, v--;
    }
    bool operator<(const edge &other) const { return c < other.c; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    int n, m, alpha;
    cin >> n >> m >> alpha;
    vector<edge> e;
    for (int i = 0; i < m; ++i) {
        e.push_back(edge());
        e.back().read();
    }
    sort(begin(e), end(e));

    DSU g(n);
    vector<vector<int>> adj(n);
    vector<int> dep(n);

    function<void(int, int)> dfs = [&](int u, int pre) {
        for (int v : adj[u]) {
            if (v != pre) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    };

    for (int i = 0; i < m; ++i) {
        auto [u, v, c] = e[i];
        if (!g.join(u, v)) {
            dfs(u, u);
            cout << 1LL * c * c + (dep[v] + 1) * alpha;
            return 0;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    cout << "Poor girl";
}