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
// typedef pair<int, int> pii;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, q;
int f[4][N];
int st[4 * N], lazy[4][4 * N];

ll getf(int f[], int l, int r) {
    int ans = f[r] - f[l - 1];
    if (ans < 0)
        ans += mod;
    return ans;
}
int getb0(int l, int r) { return mod - 1 * getf(f[0], l, r); }
int getb1(int l, int r) {
    return (1ll * 3 * getf(f[1], l, r) + 6 * getf(f[0], l, r)) % mod;
}
int getb2(int l, int r) {
    ll ans = mod * mod - 3 * getf(f[2], l, r) - 12 * getf(f[1], l, r) -
             11 * getf(f[0], l, r);
    // cout << "asaaaaaaaaaaa\n";
    // cout << l << " " << r << " " << ans % mod << '\n';
    return ans % mod;
}
ll getb3(int l, int r) {
    ll ans = getf(f[3], l, r) + 6 * getf(f[2], l, r) + 11 * getf(f[1], l, r) +
             6 * getf(f[0], l, r);
    return ans % mod;
}

void add(int &a, int b) {
    a += b;
    a %= mod;
}
void down(int id, int l, int r) {
    for (int i = 0; i <= 3; ++i)
        add(lazy[i][id * 2], lazy[i][id]),
            add(lazy[i][id * 2 + 1], lazy[i][id]);

    int mid = (l + r) / 2;
    ll b0 = getb0(l, mid);
    ll b1 = getb1(l, mid);
    ll b2 = getb2(l, mid);
    ll b3 = getb3(l, mid);

    add(st[id * 2], b0 * lazy[0][id] % mod);
    add(st[id * 2], b1 * lazy[1][id] % mod);
    add(st[id * 2], b2 * lazy[2][id] % mod);
    add(st[id * 2], b3 * lazy[3][id] % mod);

    b0 = getb0(mid + 1, r);
    b1 = getb1(mid + 1, r);
    b2 = getb2(mid + 1, r);
    b3 = getb3(mid + 1, r);

    add(st[id * 2 + 1], b0 * lazy[0][id] % mod);
    add(st[id * 2 + 1], b1 * lazy[1][id] % mod);
    add(st[id * 2 + 1], b2 * lazy[2][id] % mod);
    add(st[id * 2 + 1], b3 * lazy[3][id] % mod);
    for (int i = 0; i <= 3; ++i)
        lazy[i][id] = 0;
}
void upd(int id, int l, int r, int u, int v, int sign) {
    if (l > v || r < u)
        return;
    if (l >= u && r <= v) {
        ll b0 = getb0(l, r);
        ll b1 = getb1(l, r);
        ll b2 = getb2(l, r);
        ll b3 = getb3(l, r);

        ll t3 = 1;
        ll t2 = u;
        ll t1 = 1ll * u * u;
        ll t0 = 1ll * u * u * u;

        if (sign == -1) {
            t0 = (1ll * mod * mod - t0) % mod;
            t1 = (1ll * mod * mod - t1) % mod;
            t2 = (1ll * mod * mod - t2) % mod;
            t3 = (1ll * mod * mod - t3) % mod;
        }
        t0 %= mod;
        t1 %= mod;
        t2 %= mod;
        t3 %= mod;

        add(st[id], b0 * t0 % mod);
        add(st[id], b1 * t1 % mod);
        add(st[id], b2 * t2 % mod);
        add(st[id], b3 * t3 % mod);

        add(lazy[0][id], t0);
        add(lazy[1][id], t1);
        add(lazy[2][id], t2);
        add(lazy[3][id], t3);
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, u, v, sign);
    upd(id * 2 + 1, mid + 1, r, u, v, sign);
    st[id] = (st[id * 2] + st[id * 2 + 1]) % mod;
}
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v)
        return st[id];

    down(id, l, r);

    int mid = (l + r) / 2;
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) %
           mod;
}

void xuly() {
    cin >> n >> q;
    for (int k = 0; k <= 3; ++k) {
        for (int i = 1; i <= n; ++i) {
            int t = 1;
            for (int j = 1; j <= k; ++j)
                t = (1ll * t * i) % mod;

            f[k][i] = f[k][i - 1];
            add(f[k][i], t);
            // cout << k << " " << i << " " << f[k][i] << '\n';
        }
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        // cout << t << " " << x << " " << y << '\n';
        if (t == 0) {
            cout << get(1, 1, n, x, y) << '\n';
        } else {
            upd(1, 1, n, x, y, (t == 1) ? 1 : -1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.