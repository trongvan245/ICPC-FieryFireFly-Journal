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

pii a[N];

void xuly() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].se;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi;

    sort(a + 1, a + 1 + n);

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i].fi << " " << a[i].se << '\n';
    if (a[1].fi < a[1].se) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i].fi < a[i].se) {
            cout << -1 << '\n';
            return;
        }
        if ((a[i].fi == a[i - 1].fi && a[i].se != a[i - 1].se) || a[i].se < a[i - 1].se) {
            cout << -1 << '\n';
            return;
        }
        if (a[i].se < a[i - 1].se || a[i].fi - a[i].se < a[i - 1].fi - a[i - 1].se) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << a[n].fi - a[n].se << '\n';
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