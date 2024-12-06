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

int r, c, X;
int a[1005][1005];
ll ver[1005][1005], hor[1005][1005];

ll dist(int x, int y, int u, int v) { return pow(a[x][y] - a[u][v], X); }

void xuly() {
    cin >> r >> c >> X;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }

    bool flag = false;
    for (int i = 2; i <= r; ++i)
        for (int j = 2; j <= c; ++j) {
            ll a = dist(i, j, i - 1, j);
            ll b = dist(i - 1, j, i - 1, j - 1);
            ll c = dist(i - 1, j - 1, i, j - 1);
            ll d = dist(i, j - 1, i, j);

            if (a + b + c + d != 0)
                flag = true;
        }

    int q;
    cin >> q;
    if (flag) {
        for (int i = 1; i <= q; ++i)
            cout << "INVALID\n";
        return;
    }

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            hor[i][j] = hor[i - 1][j] + dist(i - 1, j, i, j);
            ver[i][j] = ver[i][j - 1] + dist(i, j - 1, i, j);
        }

    while (q--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        ll f1 = hor[max(u, x)][v] - hor[min(u, x)][v];
        if (u > x)
            f1 = -f1;

        ll f2 = ver[x][max(v, y)] - ver[x][min(v, y)];
        if (v > y)
            f2 = -f2;
        // cout << f1 << " " << f2 << '\n';

        cout << f1 + f2 << '\n';
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