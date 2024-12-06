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

int n, k, m, sz;
int a[N], b[N];

int sp[N][20];
void sol1() {
    for (int i = 0; i < n; ++i)
        sp[i][0] = a[i];
    for (int j = 1; j <= sz; ++j) {
        for (int i = 0; i < n; ++i) {
            int nxt = (i + (1 << (j - 1))) % n;
            sp[i][j] = 1ll * sp[i][j - 1] * sp[nxt][j - 1] % mod;

            // cout << i << " " << j << " " << sp[i][j] << '\n';
        }
    }

    // for (int i = 0; i < n; ++i)
    //     cout << sp[i][k] << " ";
}
int ppow(int A, int n) {
    ll res = 1, t = A;
    for (int j = 0; j <= 30; ++j) {
        if (BIT(n, j))
            res = res * t % mod;
        t = t * t % mod;
    }
    cout << A << " " << n << " " << res << '\n';
    return res;
}
void sol2() {
    if (k < sz) {
        for (int i = 0; i < n; ++i)
            cout << sp[i][k] << " ";
        return;
    }
    // cout << ppow(3, 3) << '\n';
    for (int i = 0; i < n; ++i)
        cout << ppow(sp[i][sz], 1 << (k - sz)) << " ";
}

void xuly() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sz = log2(n - 1) + 1;
    m = 1ll << sz;
    sol1();
    sol2();
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