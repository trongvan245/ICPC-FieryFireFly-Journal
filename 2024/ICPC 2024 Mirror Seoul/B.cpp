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

const int N = 1e6 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int n;
bool vis[N];
pii a[N];
vector<int> adj[N];

void dfs(int u, int pre, bool &isTree) {
    vis[u] = true;

    int cnt = 0;
    for (int v : adj[u]) {
        if (v == pre) {
            ++cnt;
            if (cnt > 1)
                isTree = false;
            continue;
        }
        if (vis[v])
            isTree = false;
        else
            dfs(v, u, isTree);
    }
}

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].se;
        adj[a[i].fi].pb(a[i].se);
        adj[a[i].se].pb(a[i].fi);
    }

    int LIM = 1e6;
    int ans = LIM + 1;
    for (int i = 0; i <= LIM; ++i) {
        if (adj[i].size() == 0) {
            --ans;
            continue;
        }
        if (vis[i])
            continue;

        bool isTree = true;
        dfs(i, i, isTree);
        ans -= isTree;
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
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.