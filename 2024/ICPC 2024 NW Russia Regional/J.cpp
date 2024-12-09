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
    int n, m;
    cin >> n >> m;
    vector<set<int>> in(n + 1), out(n + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        in[v].insert(u);
        out[u].insert(v);
    }

    vector<int> A, B;
    for (int i = 1; i <= n; ++i) {
        if (in[i].size() >= out[i].size()) {
            B.pb(i);
            for (int v : in[i])
                adj[v].pb(i), deg[i]++;
        } else {
            A.pb(i);
            for (int v : out[i])
                adj[i].pb(v), deg[v]++;
        }

        for (int v : in[i]) {
            out[v].erase(i);
        }
        for (int v : out[i])
            in[v].erase(i);
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i)
        if (deg[i] == 0)
            q.push(i);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            --deg[v];
            if (deg[v] == 0)
                q.push(v);
        }
        cout << u << " ";
    }
    cout << '\n';
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