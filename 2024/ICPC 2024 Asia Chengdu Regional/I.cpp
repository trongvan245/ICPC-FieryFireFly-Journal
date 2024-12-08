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

int d[N];

struct Segment_Tree {
    vector<int> st, lazy;
    int n;
    Segment_Tree(int x) {
        n = x;
        st.assign(4 * x + 5, 1);
        lazy.assign(4 * x + 5, 0);
    }

    void down(int id) {
        if (lazy[id]) {
            st[id * 2] = st[id * 2 + 1] = lazy[id];
            lazy[id * 2] = lazy[id * 2 + 1] = lazy[id];

            lazy[id] = 0;
        }
    }
    void upd(int l, int r) { upd(1, 1, n, l, r, r - l + 1); }
    void upd(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v) {
            st[id] = val;
            lazy[id] = val;
            return;
        }
        down(id);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, u, v, val);
        upd(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
    }

    int get(int l, int r) { return get(1, 1, n, l, r); }
    int get(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return -1;
        if (l >= u && r <= v)
            return st[id];
        int mid = (l + r) / 2;
        down(id);

        int t1 = get(id * 2, l, mid, u, v);
        int t2 = get(id * 2 + 1, mid + 1, r, u, v);

        if (t1 == -1)
            return t2;
        else if (t2 == -1)
            return t1;
        else
            return __gcd(t1, t2);
    }
};

void xuly() {
    int n, q;
    cin >> n >> q;
    Segment_Tree st(n);
    vector<int> a(n + 2, 0);
    set<pii, greater<pii>> s;
    set<pii> ss;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    function<void(pii)> add = [&](pii e) {
        if (e.fi > e.se)
            return;
        st.upd(e.fi, e.se);
        s.insert(e);
        ss.insert(e);
    };
    function<void(pii)> del = [&](pii e) {
        if (s.find(e) == s.end())
            return;
        s.erase(e);
        ss.erase(e);
    };

    auto getLeft = [&](int pos) -> pii {
        auto e = s.upper_bound({pos, pos});

        if (e == s.end())
            return {-1, -1};
        else
            return *e;
    };
    auto getRight = [&](int pos) -> pii {
        auto e = ss.upper_bound({pos, pos});
        if (e == ss.end())
            return {-1, -1};
        else
            return *e;
    };

    int pre = 1;
    for (int i = 2; i <= n + 1; ++i) {
        if (a[i - 1] <= a[i])
            continue;
        else {
            // cout << pre << " " << i - 1 << '\n';
            add({pre, i - 1});
            pre = i;
        }
    }

    if (s.size() == 1)
        cout << n << '\n';
    else {
        pii most_left = *s.lower_bound({n, n});
        int common = st.get(1, most_left.fi - 1);
        cout << d[common] << '\n';
    }
    

    while (q--) {
        int u, v;
        cin >> u >> v;
        a[u] = v;

        // pii curr = getRight(u);//
        pii curr = *s.lower_bound({u, n});

        // cout << u << " " << curr.fi << " " << curr.se << " init\n";
        // cout << '\n';
        del(curr);
        if (curr.fi < u)
            add({curr.fi, u - 1});

        if (curr.se > u)
            add({u + 1, curr.se});

        pii nLine = {u, u};
        pii L = getLeft(u);
        if (L != make_pair(-1, -1) && a[L.se] <= a[u]) {
            del(L);
            nLine.fi = L.fi;
        }

        pii R = getRight(u);
        // cout << R.fi << " " << R.se << "debug \n";
        if (R != make_pair(-1, -1) && a[u] <= a[R.fi]) {
            del(R);
            nLine.se = R.se;
        }
        add(nLine);

        // pii most_left = getLeft(n);//
        pii most_left = *s.lower_bound({n, n});
        if (most_left.fi == 1)
            cout << n << '\n';
        else {
            int common = st.get(1, most_left.fi - 1);
            // cout << " common" << most_left.fi << " " << common << '\n';
            cout << d[common] << '\n';
        }

        // cout << st.st[1] << '\n';

        // for (auto e = s.begin(); e != s.end(); e++)
        //     cout << (*e).fi << " " << (*e).se << '\n';
        // cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int LIM = 2e5;
    for (int i = 1; i <= LIM; ++i)
        for (int j = i; j <= LIM; j += i)
            d[j]++;

    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.