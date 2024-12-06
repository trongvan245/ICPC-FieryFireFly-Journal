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

const int N = 5e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

string s;
int n;
int d[N], f[N];

void add(int& a, int b) {
    a += b;
    a %= mod;
}
void xuly() {
    cin >> s;
    n = s.size();
    s = " " + s;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        d[i] = d[i - 1] + s[i] - 'a' + 1;

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int val = s[i] - 'a' + 1;
        f[i] = f[i - 1];
        add(f[i], sum);

        add(sum, 1ll * val * i % mod);

        int t = 1ll * i * (i + 1) / 2 * val % mod;
        add(f[i], t);

        add(ans, f[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.