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
    string s = "0110110101101101011010110110101101";
    // string s = "0110110101101";
    // string s = "01101";
    int n = s.size();

    ll ans = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        ll sz = 0, val = 0;
        for (int j = 0; j < n; ++j) {
            if (BIT(mask, j)) {
                ++sz;
                val += s[j] - '0';
            }
        }
        ans += sz * val % mod;
        ans %= mod;
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
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.