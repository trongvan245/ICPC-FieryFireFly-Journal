#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

struct DSU {
    vector<int> par;
    DSU(int n) { par.assign(n, -1); }
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
};

int main() {

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    vector<int> id;
    DSU g(n);
    vector<bool> mark(m);
    for (int i = 0; i < m; ++i) {
        auto [u, v, w] = edges[i];
        if (g.join(u, v)) {
            mark[i] = true;
            id.push_back(i);
        }
    }

    vector<int> l(id.size(), 0), r(id.size(), m - 1), mid(id.size()),
        res(id.size(), -1);

    auto check = [&]() {
        DSU g(n);
        vector<vector<int>> range(m);

        for (int i = 0; i < id.size(); ++i) {
            if (l[i] <= r[i]) {
                range[mid[i]].push_back(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (!mark[i]) {
                auto [u, v, w] = edges[i];
                g.join(u, v);
            }
            for (int j : range[i]) {
                auto [u1, v1, w1] = edges[id[j]];
                if (g.root(u1) != g.root(v1)) {
                    l[j] = mid[j] + 1;
                } else {
                    res[j] = mid[j];
                    r[j] = mid[j] - 1;
                }
            }
        }
    };

    while (true) {
        bool ok = false;
        for (int i = 0; i < id.size(); ++i) {
            if (l[i] <= r[i]) {
                mid[i] = (l[i] + r[i]) / 2;
                ok = true;
            }
        }
        if (!ok) {
            break;
        }
        check();
    }

    long long ans = 0;
    for (int i = 0; i < id.size(); ++i) {
        if (res[i] == -1) {
            return cout << -1, 0;
        }
        ans += max(0, edges[res[i]].w - edges[id[i]].w + 1);
    }
    cout << ans;
}