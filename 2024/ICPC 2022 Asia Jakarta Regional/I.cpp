#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edge;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.emplace_back(u, v);
    }

    int root = 0;
    while (root < n && adj[root].size() == 1) {
        root++;
    }
    if (root == n || adj[root].size() == n - 1) {
        return cout << -1, 0;
    }

    int Count = 0;
    pair<int, int> node = {root, 0};
    pair<int, int> leaf1 = {-1, -1}, leaf2 = {-1, -1};
    pair<int, int> demo = {-1, -1};
    vector<int> par(n + 1, -1), tin(n + 1, 0), tout(n + 1, 0);

    function<void(int, int, int)> dfs = [&](int u, int pre,
                                            int dep = 0) -> void {
        tin[u] = ++Count;
        for (int v : adj[u]) {
            if (v != pre) {
                dfs(v, u, dep + 1);
                par[v] = u;
            }
        }
        tout[u] = Count;
        pair<int, int> nod = {dep, u};
        demo = max(demo, nod);
    };
    pair<int, int> euler;
    for (int v : adj[root]) {
        demo = {-1, -1};
        dfs(v, root, 1);
        if (leaf1 < demo)
            leaf2 = leaf1, leaf1 = demo, euler = {tin[v], tout[v]};
        else
            leaf2 = max(leaf2, demo);
    }
    // cout << leaf1.se + 1 << " " << leaf2.se + 1 << '\n';
    // cout << tin[2] << " " << tout[2] << '\n';
    // cout << tin[1] << " " << tout[1] << '\n';
    // cout << '\n';
    for (auto [u, v] : edge) {
        if (tin[v] < tin[u])
            swap(u, v);
        if (v == leaf1.se)
            cout << v + 1 << " " << root + 1 << '\n';
        else if (euler.fi <= tin[v] && tout[v] <= euler.se)
            cout << v + 1 << " " << leaf2.se + 1 << '\n';
        else
            cout << v + 1 << " " << leaf1.se + 1 << '\n';
    }
}