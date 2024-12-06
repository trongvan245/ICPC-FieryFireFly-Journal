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

int n, q;
int a[N], b[N];
ll f[N], ff[N];

ll calf(int u, int v) {
    if (u == v)
        return 0;
    if (u <= v)
        return f[v - 1] - f[u - 1];
    return f[n] - f[u - 1] + f[v - 1];
}

ll calff(int u, int v) {
    if (u == v)
        return 0;
    if (v <= u)
        return ff[u - 1] - ff[v - 1];
    return ff[u - 1] + ff[n] - ff[v - 1];
}

void xuly() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (a[i] + b[i] < 0)
            flag = true;

    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] + a[i], ff[i] = ff[i - 1] + b[i];

    if (f[n] < 0 || ff[n] < 0)
        flag = true;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (flag) {
            cout << "flawed\n";
            continue;
        }
        // cout << calf(u, v) << " " << calff(u, v) << '\n';
        cout << min(calf(u, v), calff(u, v)) << '\n';
    }
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