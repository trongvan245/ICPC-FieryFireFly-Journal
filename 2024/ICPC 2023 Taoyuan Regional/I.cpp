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

struct three {
    int x, y, z;
};
vector<three> Q;

int A[10004];
map<int, vector<int>> m;
void add(int x, int y, int z) {
    int val = A[x] + A[y];
    if (m[val].size() < 3)
        m[val].pb(z);
}

bool check(int x, int y, int z) {
    vector<int> va, vb;

    for (int v : m[A[x] + A[y]])
        if (v != z)
            va.pb(v);

    for (int v : m[A[x] + A[z]])
        if (v != y)
            vb.pb(v);

    for (int u : va)
        for (int v : vb) {
            // cout << x << " " << u << " " << y << " " << z << " " << v << '\n';
            if (u == v)
                continue;
            cout << x << " " << u << " " << y << " " << z << " " << v << '\n';
            cout << '\n';
            return true;
        }
    return false;
}
void xuly() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        A[i] = 1ll * rand() * rand() % mod;
    // for (int i = 1; i <= n; ++i)
    //     cout << A[i] << " ";
    // cout << '\n';

    for (int i = 1; i <= q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(x, z, y);
        add(y, z, x);
        Q.pb({x, y, z});
    }
    // return;

    for (auto [x, y, z] : Q) {
        if (check(x, y, z))
            return;
        if (check(y, x, z))
            return;
        if (check(z, x, y))
            return;
    }

    cout << -1;
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