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
    multiset<int> s;
    int n;
    cin >> n;

    int val = 0;
    for (int i = 1; i <= n; ++i) {
        int x, C = 0;
        cin >> x;
        while (x % 2 == 0)
            x /= 2, ++C;
        if (!val)
            val = x;
        else
            val = __gcd(x, val);
        // cout << C << '\n';
        s.insert(C);
    }

    while (s.size() != 1) {
        int u = *s.begin();
        s.erase(s.begin());
        int v = *s.begin();
        s.erase(s.begin());
        // cout << u << " " << v << " " << s.size() << '\n';
        s.insert(min(u, v) + 1);
    }

    int res = *s.begin();
    ll ans = 1ll << res;

    ans *= val;

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