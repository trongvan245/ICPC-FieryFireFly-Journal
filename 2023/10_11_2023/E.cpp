/* try <3 */
#include <bits/stdc++.h>

using namespace std;

#define task "sol"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007;  /// 998244353
const ll base = 331;

struct DSU {
    vector<int> par;
    int n;
    DSU(int _n) {
        n = _n;
        par.assign(n + 5, -1);
    }
    int root(int u) {
        return (par[u] < 0 ? u : par[u] = root(par[u]));
    }
    bool isSame(int u, int v) {
        return root(u) == root(v);
    }
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
struct edges {
    int u, v, w, id;
    bool operator < (const edges &other) const {
        return w < other.w;
    }
};
void gogo() {
    int n, m;
    cin >> n >> m;

    vector<edges> e;

    DSU g(n);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w, i});
        g.join(u, v);
    }
    sort(ALL(e));
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += g.par[i] < 0;
    }

    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }

    g = DSU(n);
    vector<bool> vis(m + 1, 0);

    vector<int> res;
    for (int i = 0; i < m; ++i) {
        int j = i;
        while (j + 1 < m && e[j + 1].w == e[i].w) {
            j++;
        }
        for (int k = i; k <= j; ++k) {
            if (g.isSame(e[k].u, e[k].v)) {
                vis[k] = 1;
            }
        }
        for (int k = i; k <= j; ++k) {
            if (vis[k]) {
                continue;
            }
            if (!g.join(e[k].u, e[k].v)) {
                res.push_back(e[k].id);
            }
        }
        i = j;
    }
    cout << res.size() << ' ';
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);

    }
    int t;
    cin >> t;
    while (t--) {
        gogo();
    }
}
