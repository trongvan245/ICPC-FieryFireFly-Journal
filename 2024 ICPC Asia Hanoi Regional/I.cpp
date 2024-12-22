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
const long long mod = 998244353;

using namespace std;

void xuly() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    ll res = 1;

    auto powd = [&](int a, int n) -> int {
        ll t = a, res = 1;
        while (n) {
            if (n & 1)
                res = res * t % mod;
            t = t * t % mod;
            n /= 2;
        }
        return res;
    };

    for (int i = 1; i <= n; ++i)
        res = res * a[i] % mod;

    cout << (res * powd(a[1], mod - 2) - 1 + mod) % mod << '\n';
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