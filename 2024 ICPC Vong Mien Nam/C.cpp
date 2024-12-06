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

const int N = 1e6 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int n, minn;
int w[N], a[N], t[N], b[N], d[N];
ll ans;
vector<int> A;
void dfs(int u) {
    A.pb(w[u]);
    d[u] = 1;
    int nxt = a[t[u]];

    if (!d[nxt])
        dfs(nxt);
}

void xuly() {
    int n;
    cin >> n;
    ll zmin = 1e9;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        zmin = min(zmin, 1ll * w[i]);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        t[b[i]] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i])
            continue;
        A.clear();
        dfs(i);
        if (A.size() == 1)
            continue;
        ll minn = 1e9, s = 0;
        for (int v : A) {
            s += v;
            minn = min(1ll * v, minn);
        }

        ll sz = A.size();
        ll t1 = 2 * (zmin + minn) + (s - minn) + (sz - 1) * zmin;
        
        ll t2 = s + minn * (sz - 2);
        ans += min(t1, t2);
    }

    cout << ans;



    /// 2^F(n)
    ///F(n)%mod
    
    //2^F(n) %mod != 2^(F(n)%mod)
    //a^(P-1) dong du 1 (mod P)
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