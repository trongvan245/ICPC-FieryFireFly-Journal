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
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

void xuly() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int, int>> c(n + 1, {0, 0});

    function<void(int, int)> pre_dfs = [&](int u, int pre) {
        for (int v : adj[u]) {
            if (v == pre) continue;
            if (!c[u].first) c[u].first = v;
            else c[u].second = v;
            pre_dfs(v, u);
        }
    };
    pre_dfs(1, 0);

    vector<int> h(n + 1, 0);

    function<multiset<int, greater<int>>(int, int)> dfs = [&](int u, int height) -> multiset<int, greater<int>> {
        h[u] = height;
        
        if (c[u] == make_pair(0, 0)) {
            multiset<int, greater<int>> s;
            s.insert(h[u]);
            return s;
        }
        multiset<int, greater<int>> s1, s2;
        if (c[u].first) s1 = dfs(c[u].first, height + 1);
        if (c[u].second) s2 = dfs(c[u].second, height + 1);
        s1.insert(h[u]);
        s2.insert(h[u]);

        while(abs(*s1.begin() - *s2.begin()) > 1) {
            if (*s1.begin() > *s2.begin()) {
                s1.erase(s1.begin());
            }
            else {
                s2.erase(s2.begin());
            }
        }

        s1.erase(s1.find(h[u]));
        s2.erase(s2.find(h[u]));

        if (s1.size() < s2.size()) swap(s1, s2);
        for (auto v : s2) s1.insert(v);
        s1.insert(h[u]);

        // cout << u << '\n';
        // for (auto v : s1) cout << v << " "; cout <<'\n';
        return s1;
    };

    multiset<int, greater<int>> s = dfs(1, 0);

    cout << n - (int)(s.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.