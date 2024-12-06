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
    vector<pii> a(n + 1, {0, 0});
    vector<pii> A;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;

        A.pb({a[i].fi, a[i].se});
        if (a[i].fi != a[i].se) {
            A.pb({a[i].se, a[i].fi});
        }
    }

    sort(A.begin(), A.end(), greater<pii>());

    multiset<int, greater<int>> s;

    ll ans = 0;
    ll ans2 = 0;
    for (auto [w, h] : A) {
        if (w < h)
            s.erase(s.find(w));
        if (s.size()) {
            int v = *s.begin();
            ans = max(ans, 1ll * w * min(h, v));
        }
        if (w < h)
            s.insert(w);

        ans2 = max({ans2, 1ll * w * h});
        s.insert(h);
    }

    ld rans = max((ld)ans2 / 2.0, (ld)ans);
    cout << fixed << setprecision(1) << rans << '\n';
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