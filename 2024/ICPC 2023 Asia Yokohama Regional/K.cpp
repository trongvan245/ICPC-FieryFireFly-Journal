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

ld ask(int x1, int y1, int x2, int y2) {
    ld a;
    cout << "query " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cin >> a;
    return a;
}

void solve() {
    ll bl, ans_x, ans_y;
    ld x;
    for (int i = 1; i < 100000; i += 199) {
        ld rep = ask(i, 0, i, 100000);
        if (rep > 0) {
            x = rep / 2.0;
            bl = i;
            break;
        }
    }

    int lo = bl, hi = 100000;
    int mid = (lo + hi) / 2;
    while (lo < hi) {
        if (ask(mid, 0, mid, 100000) > 0.5)
            lo = mid + 1;
        else
            hi = mid;
        mid = (lo + hi) / 2;
    }
    ll rg = lo;

    lo = 0;
    hi = bl;
    mid = (lo + hi + 1) / 2;
    while (lo < hi) {
        if (ask(mid, 0, mid, 100000) > 0.5)
            hi = mid - 1;
        else
            lo = mid;
        mid = (lo + hi + 1) / 2;
    }
    ll lf = lo;

    ans_x = ((lf + rg) / 2);
    ll r = ans_x - lf;

    lo = 0;
    hi = 100000;
    mid = (lo + hi + 1) / 2;
    while (lo < hi) {
        if (ask(ans_x, 0, ans_x, mid) > 0.5)
            hi = mid - 1;
        else
            lo = mid;
        mid = (lo + hi + 1) / 2;
    }

    cout << "answer " << ans_x << " " << lo + r << " " << r << endl;
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