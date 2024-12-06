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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n;
pii a[N];

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }

    a[0] = a[n];
    a[n + 1] = a[1];
    vector<pii> M;
    for (int i = 1; i <= n + 1; ++i) {
        int k = a[i].se - a[i - 1].se;
        if (k == 0)
            continue;

        M.pb({k, a[i].fi - a[i - 1].fi});
    }

    // cout << M.size() << '\n';

    int Count = 0;
    for (int i = 1; i < M.size(); ++i) {
        int Y1 = M[i - 1].fi, X1 = M[i - 1].se;
        int Y2 = M[i].fi, X2 = M[i].se;

        // cout << Y1 << " " << Y2 << " " << X1 << " " << X2 << '\n';

        if (X1 >= 0 && X2 >= 0 && Y1 < 0 && Y2 > 0)
            ++Count;
    }

    cout << Count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    // int t;
    // cin >> t;
    // while (t--)
    xuly();
}

// Surely nothing could go wrong.