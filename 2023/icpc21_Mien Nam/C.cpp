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

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n;
pii a[105];
map<vector<ll>, int> mm;

ll dis(pii A, pii B) {
    int t1 = A.fi - B.fi;
    int t2 = A.se - B.se;
    return t1 * t1 + t2 * t2;
}

bool degenerate(pii a, pii b, pii c) {
    pii AB = {a.fi - b.fi, a.se - b.se};
    pii BC = {b.fi - c.fi, b.se - c.se};
    return (1ll * AB.fi * BC.se == 1ll * AB.se * BC.fi);
}

vector<ll> edges(pii a, pii b, pii c) {
    ll t1 = dis(a, b);
    ll t2 = dis(b, c);
    ll t3 = dis(c, a);
    vector<ll> e;
    e.pb(t1);
    e.pb(t2);
    e.pb(t3);
    return e;
}

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;

    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j)
            for (int k = j + 1; k < i; ++k) {
                if (degenerate(a[i], a[j], a[k]))
                    continue;
                vector<ll> e = edges(a[i], a[j], a[k]);
                ++mm[e];
            }

        for (int j = i + 2; j <= n; ++j)
            for (int k = j + 1; k <= n; ++k) {
                if (degenerate(a[i + 1], a[j], a[k]))
                    continue;
                vector<ll> e;
                e = edges(a[i + 1], a[j], a[k]);
                // for (auto v : e)
                //     cout << v << ' ';
                // cout << '\n';
                // continue;
                ans += mm[e];
                e = edges(a[i + 1], a[k], a[j]);
                ans += mm[e];

                e = edges(a[j], a[i + 1], a[k]);
                ans += mm[e];
                e = edges(a[j], a[k], a[i + 1]);
                ans += mm[e];

                e = edges(a[k], a[i + 1], a[j]);
                ans += mm[e];
                e = edges(a[k], a[j], a[i + 1]);
                ans += mm[e];
            }
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
    xuly();
}

// Surely nothing could go wrong.