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
    vector<ll> a(n + 5, 0);
    vector<ll> L_max(n + 5, 0), L_min(n + 5, 0), R_max(n + 5, 0),
        R_min(n + 5, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        L_max[i] = max(L_max[i - 1] + a[i], a[i]),
        L_min[i] = min(L_min[i - 1] + a[i], a[i]);

    for (int i = n; i >= 1; --i)
        R_max[i] = max(R_max[i + 1] + a[i], a[i]),
        R_min[i] = min(R_min[i + 1] + a[i], a[i]);

    ll ans = 0;
    for (int i = 1; i < n; ++i)
        ans = max(
            {ans, abs(R_max[i + 1] - L_min[i]), abs(R_min[i + 1] - L_max[i])});

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