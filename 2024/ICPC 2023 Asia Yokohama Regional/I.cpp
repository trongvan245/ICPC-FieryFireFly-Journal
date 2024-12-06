#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
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

typedef long double ld;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<long double, long double>> pi(n), f(m), po(m);

    for_(n) cin >> pi[i].fi;
    for_(n) cin >> pi[i].se;
    for_(m) cin >> f[i].fi;
    for_(m) cin >> f[i].se;

    sort(pi.begin(), pi.end(), [](pair<ld, ld> a, pair<ld, ld> b) -> bool {
        return a.fi / a.se > b.fi / b.se;
    });
    sort(f.begin(), f.end(), [](pair<ld, ld> a, pair<ld, ld> b) -> bool {
        return a.fi / a.se > b.fi / b.se;
    });

    ld x = 0, y = 0, nx, ny;
    for_(m) {
        x = x + f[i].fi;
        y = y + f[i].se;
        po.pb(mp(x, y));
    }

    x = 0;
    y = 0;
    for (int i = 0; i < n; i++) {
        nx = x + pi[i].fi;
        ny = y + pi[i].se;

        // debug(x << " " << y <<  " " << nx << " " << ny );

        for (auto it : po) {
            ld fx = it.fi;
            ld fy = it.se;

            if ((fx - x) * (ny - fy) - (fy - y) * (nx - fx) > 0) {
                // debug(fx <<  " " <<fy )
                cout << "No\n";
                return;
            }
        }

        x = nx;
        y = ny;
    }
    cout << "Yes\n";
}

int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("INP.inp","r",stdin);
    // freopen( "OUT.out", "w", stdout);

    int t = 1;
    // cin >> t;
    for_(t) solve();

    // cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}