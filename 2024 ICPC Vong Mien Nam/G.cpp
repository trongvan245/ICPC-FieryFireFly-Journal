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
#define pii pair<ll, ll>
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
const long long MOD = 1e9 + 7;

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

vector<vector<ll>> matmul(vector<vector<ll>> mata, vector<vector<ll>> matb,
                          ll mod) {
    vector<vector<ll>> res = {
        {mata[0][0] * matb[0][0] % mod + mata[0][1] * matb[1][0] % mod,
         mata[0][0] * matb[0][1] % mod + mata[0][1] * matb[1][1] % mod},
        {mata[1][0] * matb[0][0] % mod + mata[1][1] * matb[1][0] % mod,
         mata[1][0] * matb[0][1] % mod + mata[1][1] * matb[1][1] % mod}};
    res[0][0] %= mod;
    res[0][1] %= mod;
    res[1][0] %= mod;
    res[1][1] %= mod;
    return res;
}

void solve() {
    ll n, n1;
    cin >> n;

    vector<vector<ll>> mat = {{1, 1}, {1, 0}};
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};

    if (n == 0) {
        n1 = 0;
        cout << "0\n";
        return;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n >= 2) {
        ll k = n - 1;
        while (k > 0) {
            if (k % 2 == 1)
                ans = matmul(ans, mat, MOD);
            mat = matmul(mat, mat, MOD);
            k /= 2;
        }
    }

    n1 = ans[0][0];
    ll len_m1 = (ans[0][0] + ans[0][1] - 1 + MOD) % MOD;

    mat = {{1, 1}, {1, 0}};
    ans = {{1, 0}, {0, 1}};
    ll k = n - 1;
    while (k > 0) {
        if (k % 2 == 1)
            ans = matmul(ans, mat, MOD - 1);
        mat = matmul(mat, mat, MOD - 1);
        k /= 2;
    }

    // debug(ans);
    // debug(n1);

    ll len_m22 = (ans[0][0] + ans[0][1] - 2 + MOD - 1) % (MOD - 1);
    ll len_m21 = (ans[0][0] + ans[0][1] - 1 + MOD - 1) % (MOD - 1);

    ll t1 =
        (pow_mod(2, len_m22, MOD) * len_m1 % MOD + pow_mod(2, len_m21, MOD));
    cout << (t1 % MOD * n1) % MOD << el;
}

int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("INP.inp", "r", stdin);
    // freopen("OUT.out", "w", stdout);

    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
        solve();

    // cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
