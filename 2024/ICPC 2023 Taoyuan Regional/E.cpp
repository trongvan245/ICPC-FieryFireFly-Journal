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

struct Square {
    ll u, v, x, y;

    bool operator<(const Square &other) const { return u < other.u; }
} a[105], b[105];

int n, d;
ll R[105];

bool inv(ll l1, ll r1, ll l2, ll r2) {
    if (!(l1 >= r2) && !(r1 <= l2))
        return true;
    return false;
    // if (l1 <= l2 && l2 < r1)
    //     return true;
    // if (l1 < r2 && r2 <= r1)
    //     return true;
    // return false;
}

void xuly() {
    cin >> n >> d;

    ll maxx_y = 0, minn_y = 1e10, maxx_x = 0, minn_x = 1e10;
    ;
    for (int i = 1; i <= n; ++i) {
        auto &[u, v, x, y] = a[i];
        cin >> u >> v >> x >> y;
        maxx_y = max(maxx_y, y);
        minn_y = min(minn_y, v);

        maxx_x = max(maxx_x, x);
        minn_x = min(minn_x, u);
    }

    sort(a + 1, a + 1 + n);
    ll ans1 = 0;
    for (int i = 1; i <= n; ++i) {
        ll maxx = 0;
        for (int j = 1; j < i; ++j) {
            if (!inv(a[j].v, a[j].y, a[i].v, a[i].y))
                continue;
            maxx = max(R[j] + d, maxx);
        }

        R[i] = maxx + (a[i].x - a[i].u);
        ans1 = max(ans1, R[i]);
    }

    ll ans2 = 0;
    ll LIM = 1e10;
    for (int i = 1; i <= n; ++i) {
        ll tu = LIM - a[i].x, tx = LIM - a[i].u;
        a[i].u = tu, a[i].x = tx;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        ll maxx = 0;
        for (int j = 1; j < i; ++j) {
            if (!inv(a[j].v, a[j].y, a[i].v, a[i].y))
                continue;
            maxx = max(R[j] + d, maxx);
        }

        R[i] = maxx + (a[i].x - a[i].u);
        ans2 = max(ans2, R[i]);
    }

    cout << max(((maxx_x - minn_x) - min(ans1, ans2)), 0ll) * (maxx_y - minn_y) << '\n';
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