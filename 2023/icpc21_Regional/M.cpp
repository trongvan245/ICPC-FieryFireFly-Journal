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
string s;

void add(ll& a, ll b) {
    a += b;
    a %= mod;
}

void xuly() {
    cin >> s;
    n = s.size();
    s = " " + s;

    ll x = 0, xx = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        int digit = s[i] - '0';
        ll t = 100ll * xx + 20ll * digit * x + i * s[i] * s[i];

        xx = (i * digit * digit + 20 * digit * x + 100ll * xx) % mod;
        x = (x * 10 + i * digit) % mod;

        add(ans, xx);
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