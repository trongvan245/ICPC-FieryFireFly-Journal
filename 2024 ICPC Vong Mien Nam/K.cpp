#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define ld long double
#define for_(n) for (ll i = 0; i < n; i++)
#define for__(a, b) for (ll i = a; i < b; i++)
#define _for(i, a, b) for (ll i = a; i < b; i++)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define el "\n"
#define debug(x) cerr << "[debug] " << #x << " : " << x << endl;
#define M_PI 3.14159265358979323846

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const long long MOD = 1000000007;

template <class T, class P>
ostream &operator<<(ostream &os, const pair<T, P> &a) {
    os << "{" << a.first << ";" << a.second << "}";
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    ;
    for (auto it : a)
        os << it << " ";
    ;
    return os;
}
template <class T> ostream &operator<<(ostream &os, const deque<T> &a) {
    ;
    for (auto it : a)
        os << it << " ";
    ;
    return os;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &a) {
    ;
    for (auto it : a)
        os << it << " ";
    ;
    return os;
}
template <class T> ostream &operator<<(ostream &os, const multiset<T> &a) {
    ;
    for (auto it : a)
        os << it << " ";
    ;
    return os;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / (gcd(a, b)) * b; }

ll pow_mod(ll x, ll y, ll mod) { // mod<3.10^9
    ll ans = 1;
    while (y > 0) {
        if (y % 2 == 1)
            ans = ans * x % mod;
        y = y >> 1;
        x = x * x % mod;
    }
    return ans % mod;
}

void solve() {
    int n, p, m;
    cin >> n >> p >> m;
    vector<vector<int>> pac(p);
    vector<pair<char, int>> qr;

    for_(p) {
        int u, v, d;
        cin >> u >> v >> d;
        d--;
        pac[i] = {u, v, d};
    }

    int lsz = -1;
    for_(m) {
        char c;
        int k;
        cin >> c >> k;
        qr.pb(mp(c, k));
    }

    for_(m) if (qr[i].fi == 'Z') lsz = i;

    // debug(lsz);

    pii vec = {0, 0};
    pii pos = {0, 0};
    int dir = 0;

    vector<pii> gd(4);
    gd[0] = mp(-1, 0);
    gd[1] = mp(0, 1);
    gd[2] = mp(1, 0);
    gd[3] = mp(0, -1);

    for (int i = lsz + 1; i < m; i++) {
        if (qr[i].fi == 'A') {
            pos.fi += qr[i].se * gd[dir].fi;
            pos.se += qr[i].se * gd[dir].se;
        } else {
            dir = (dir + qr[i].se) % 4;
        }
    }

    // debug(pos);

    if (lsz == -1) {
        for_(p) {
            if (pac[i][2] == 0)
                vec = pos;
            else if (pac[i][2] == 1)
                vec = mp(pos.se, -pos.fi);
            else if (pac[i][2] == 2)
                vec = mp(-pos.fi, -pos.se);
            else
                vec = mp(-pos.se, pos.fi);

            int x = pac[i][0] + vec.first;
            int y = pac[i][1] + vec.se;

            x = (x + n + 2ll * n * m) % n;
            y = (y + n + 2ll * n * m) % n;

            cout << x << " " << y << el;
        }
    } else {
        int add = 0;
        for_(lsz) if (qr[i].fi == 'R') add = (add + qr[i].se) % 4;
        int fx = qr[lsz].se / n;
        int fy = qr[lsz].se % n;

        for_(p) {
            int pd = (pac[i][2] + add) % 4;

            if (pd == 0)
                vec = pos;
            else if (pd == 1)
                vec = mp(pos.se, -pos.fi);
            else if (pd == 2)
                vec = mp(-pos.fi, -pos.se);
            else
                vec = mp(-pos.se, pos.fi);

            int x = (fx + vec.fi + n + 2ll * n * m) % n;
            int y = (fy + vec.se + n + 2ll * n * m) % n;

            cout << x << " " << y << el;
        }
    }
}

int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("INP.inp", "r", stdin);
    //   freopen( "OUT.out", "w", stdout);

    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    // cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
