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

struct three {
    int u, v, w;
    bool operator<(const three &other) { return w < other.w; }
};

void xuly() {
    int n, m;
    cin >> n >> m;
    // vector<queue<int>> Q(n + 1);
    // vector<queue<int>> W(n + 1);
    vector<pii> nxt(n + 1);
    vector<ll> res(n + 1, 0), st(n + 1), ed(n + 1);
    vector<int> par(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        // Q[i].push(i);
        nxt[i] = {-1, 0};
        st[i] = i;
        ed[i] = i;
    }

    auto get = [&](int x) -> pii {
        int u = st[x];
        if (u == -1)
            return {-1, 0};

        int w_u = nxt[u].se;
        st[x] = nxt[u].fi;
        if (st[x] == -1)
            ed[u] = -1;
        nxt[u] = {-1, 0};
        return {u, w_u};
    };

    function<int(int)> findd = [&](int v) -> int {
        if (par[v] < 0)
            return v;
        return par[v] = findd(par[v]);
    };

    auto add = [&](int y, int u, int w) {
        nxt[u] = {-1, 0};
        if (ed[y] == -1) {
            st[y] = u;
            ed[y] = u;
        } else {
            nxt[ed[y]] = {u, w};
            ed[y] = u;
            res[y] += w;
        }
    };
    auto Union = [&](int u, int v, int w) {
        int x = findd(u), y = findd(v);
        if (x == y)
            return;

        if (par[x] < par[y])
            swap(x, y);

        while (true) {
            auto [u, w_u] = get(x);
            if (u == -1)
                break;

            auto [v, w_v] = get(y);
            res[y] -= w_v;
            // assert(v != -1);
            // cout << u << " " << v << '\n';
            add(y, u, w);
            add(y, v, w);
        }

        // cout << x << " " << y << " " << w << " " << res[y] << '\n';
        // cout << u << " " << v << " " << w << " " << res[y] << " " << Q[y].size() << '\n';
        par[y] += par[x];
        par[x] = y;
    };
    vector<three> E;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        E.pb({u, v, w});
    }

    sort(E.begin(), E.end());

    for (auto [u, v, w] : E) {
        // cout << u << " " << v << " " << w << '\n';
        Union(u, v, w);
    }

    int x = findd(1);
    cout << res[x] << '\n';
    while (st[x] != -1) {
        cout << st[x] << " ";
        st[x] = nxt[st[x]].fi;
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
