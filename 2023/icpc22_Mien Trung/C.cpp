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

struct fenwick {
    vector<ll> fw;
    int n;
    void kc(int x) {
        n = x;
        fw.resize(n + 5);
    }
    void upd(int i, ll val) {
        for (; i <= n; i += i & (-i))
            fw[i] += val;
    }
    ll get(int l, int r) {
        ll ans = 0;
        for (; r >= 1; r -= r & (-r))
            ans += fw[r];
        for (--l; l >= 1; l -= l & (-l))
            ans += fw[l];
        return ans;
    }
};
fenwick fw[11];

int n, k;
ll f[11];
pii a[N];

void xuly() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n);

    for (int i = 0; i <= k; ++i)
        fw[i].kc(n + 1);
    fw[0].upd(1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            f[j] = fw[j - 1].get(1, a[i].se + 1);
        }
        for (int j = 1; j <= min(i, k); ++j)
            fw[j].upd(a[i].se + 1, f[j]);
        // cout << '\n';

        // cout << a[i].fi << " " << a[i].se << '\n';

        // for (int j = 1; j <= min(i, k); ++j)
        //     cout << i << " " << j << " " << f[j] << '\n';
    }

    ll ans = fw[k].get(1, n + 1);
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