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

vector<int> d[N];
int pre[N], a[N], ans[N];
vector<pii> Q[N];

struct Segment_Tree {
    int n;
    vector<int> st;
    Segment_Tree(int x) {
        n = x + 5;
        st.assign(4 * n + 5, 0);
    }
    void upd(int pos, int v) { upd(1, 1, n, pos, v); }
    void upd(int id, int l, int r, int pos, int v) {
        if (l > pos || r < pos)
            return;
        if (l == r) {
            st[id] = max(st[id], v);
            return;
        }
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, pos, v);
        upd(id * 2 + 1, mid + 1, r, pos, v);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    int get(int l, int r) { return get(1, 1, n, l, r); }
    int get(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return 0;
        if (l >= u && r <= v)
            return st[id];
        int mid = (l + r) / 2;
        return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
};

void xuly() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        Q[r].pb({l, i});
    }

    Segment_Tree st(n);
    for (int i = 1; i <= n; ++i) {
        for (int v : d[a[i]]) {
            if (pre[v])
                st.upd(pre[v], v);
            pre[v] = i;
        }

        for (auto [l, pos] : Q[i]) {
            ans[pos] = st.get(l, i);
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int LIM = 1e5;
    for (int i = 1; i <= LIM; ++i)
        for (int j = i; j <= LIM; j += i)
            d[j].pb(i);

    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.