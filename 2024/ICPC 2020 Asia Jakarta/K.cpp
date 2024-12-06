// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "sol"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

struct Segment_tree {
    vector<ll> st, lazy;
    int n;
    Segment_tree(int x) {
        n = x;
        st.assign(4 * x + 5, 0);
        lazy.assign(4 * x + 5, 0);
    }

    void down(int id, int l, int r) {
        int mid = (l + r) / 2;
        ll t = lazy[id];
        lazy[id] = 0;

        lazy[id * 2] += t, lazy[id * 2 + 1] += t;
        st[id * 2] += t * (mid - l + 1);
        st[id * 2 + 1] += t * (r - mid);
    }
    void upd(int pos, ll val) { upd(1, 1, n, pos, val); }
    void upd(int id, int l, int r, int pos, ll val) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            st[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, pos, val);
        upd(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    void upd(int l, int r, int val) { upd(1, 1, n, l, r, val); }
    void upd(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v) {
            st[id] += 1ll * (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, u, v, val);
        upd(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    ll get(int l, int r) { return get(1, 1, n, l, r); }
    ll get(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        down(id, l, r);
        int mid = (l + r) / 2;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

int n, q, cnt;
int in[N], out[N], p[N];
ll dp[N][25], d[N][25];
vector<int> adj[N];

void dfs(int u) {
    in[u] = ++cnt;
    for (int v : adj[u]) {
        dfs(v);
        for (int i = 1; i <= 20; ++i)
            dp[u][i] += dp[v][i - 1];
    }
    out[u] = cnt;
    ++dp[u][0];
}

void xuly() {
    cin >> n >> q;
    Segment_tree st(n);
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].pb(i);
    }

    dfs(1);
    // return;

    // cout << dp[3][2] << '\n';

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            if (k == 1)
                st.upd(in[x], out[x], y);
            else {
                ll s = 0;
                for (int j = 0; j <= 20; ++j) {
                    s += y * dp[x][j];
                    d[x][j] += y;
                    y /= k;
                }
                st.upd(in[x], s);
            }
        } else {
            int x;
            cin >> x;
            ll ans = st.get(in[x], out[x]);
            // cout << ans << " check\n";

            int pre = x;
            for (int pos = 1; pos <= 20; ++pos) {
                pre = p[pre];
                if (!pre)
                    break;

                for (int i = pos; i <= 20; ++i) {

                    ans += 1ll * d[pre][i] * dp[x][i - pos];
                }
            }

            cout << ans << '\n';
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
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.