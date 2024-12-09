// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

typedef tree<vector<int>, null_type, less<vector<int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const long long MOD = 998244353;
const bool enable_debug = true;

template <class T, class P> ostream &operator<<(ostream &os, const pair<T, P> &a) {
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

vector<int> p, d;
vector<ll> f1, f2, mf, mc, c1, c2;

ll go_all(int i, int des) {
    if (i == 0)
        return 0;
    if (p[i] == des) {
        return go_all(i - 1, des);
    }

    if (p[i] == 1 && des == 3)
        return (go_all(i - 1, 3) + 1 + f2[i - 1] + 1 + f2[i - 1]) % MOD;
    if (p[i] == 3 && des == 1)
        return (go_all(i - 1, 1) + 1 + f2[i - 1] + 1 + f2[i - 1]) % MOD;
    if (p[i] == 1 && des == 2)
        return (go_all(i - 1, 3) + 1 + f1[i - 1]) % MOD;
    if (p[i] == 2 && des == 1)
        return (go_all(i - 1, 3) + 1 + f2[i - 1]) % MOD;
    if (p[i] == 2 && des == 3)
        return (go_all(i - 1, 1) + 1 + f2[i - 1]) % MOD;
    if (p[i] == 3 && des == 2)
        return (go_all(i - 1, 1) + 1 + f1[i - 1]) % MOD;
}

pll first_go(int i, int des) {
    ll total = 0;
    int rep = 0;
    // debug(i << " " << des);
    if (p[i] == 1 && des == 3) {
        // debug("XX");
        total += go_all(i - 1, 3) + 1 + f2[i - 1] + 1;
        total %= MOD;
        rep = 1;
    }

    if (p[i] == 3 && des == 1) {
        total += go_all(i - 1, 1) + 1 + f2[i - 1] + 1;
        total %= MOD;
        rep = 3;
    }

    if (p[i] == 1 && des == 2) {
        total += go_all(i - 1, 3) + 1;
        total %= MOD;
        rep = 3;
    }

    if (p[i] == 2 && des == 1) {
        total += go_all(i - 1, 3) + 1;
        total %= MOD;
        rep = 3;
    }

    if (p[i] == 2 && des == 3) {
        total += go_all(i - 1, 1) + 1;
        total %= MOD;
        rep = 1;
    }

    if (p[i] == 3 && des == 2) {
        total += go_all(i - 1, 1) + 1;
        total %= MOD;
        rep = 1;
    }

    p[i] = des;
    return mp(total, rep);
}

void solve(int ith) {
    int n;
    cin >> n;
    p.assign(n + 1, 0), d.assign(n + 1, 0);

    for_(n) cin >> p[i + 1];
    for_(n) cin >> d[i + 1];

    // debug(d);

    f1.assign(n + 1, 0), f2.assign(n + 1, 0), mf.assign(n + 1, 0), mc.assign(n + 1, 0), c1.assign(n + 1, 0),
        c2.assign(n + 1, 0);

    f1[1] = 1;
    f2[1] = 2;
    mf[1] = 1;
    mc[1] = 1;
    c1[1] = 1;
    c2[1] = 2;

    for (int i = 2; i <= n; i++)
        f2[i] = (2 + 3 * f2[i - 1]) % MOD;
    for (int i = 2; i <= n; i++)
        f1[i] = (1 + f2[i - 1] + f1[i - 1]) % MOD;
    for (int i = 2; i <= n; i++)
        mf[i] = (mf[i - 1] + 1 + f2[i - 1]) % MOD;
    for (int i = 2; i <= n; i++)
        mc[i] = (mf[i - 1] + 1) % MOD;
    for (int i = 2; i <= n; i++)
        c1[i] = (1 + f2[i - 1]) % MOD;
    for (int i = 2; i <= n; i++)
        c2[i] = (2 + 2 * f2[i - 1]) % MOD;

    debug(f2);

    ll ans = 0, crp = 0, cri = 0;
    for (int i = n; i >= 1; i--) {
        if (p[i] != d[i]) {
            pll re = first_go(i, d[i]);
            // debug(i << " " << re);
            ans += re.fi;
            crp = re.se;
            cri = i;
            break;
        }
    }

    for (int i = cri - 1; i >= 1; i--) {
        if (crp != d[i]) {
            if (crp == 1 && d[i] == 3) {
                ans += c2[i];
                crp = 1;
            } else if (crp == 3 && d[i] == 1) {
                ans += c2[i];
                crp = 3;
            } else if (crp == 1 && d[i] == 2) {
                ans += c1[i];
                crp = 3;
            } else if (crp == 2 && d[i] == 1) {
                ans += mc[i];
                crp = 3;
            } else if (crp == 3 && d[i] == 2) {
                ans += c1[i];
                crp = 1;
            } else if (crp == 2 && d[i] == 3) {
                ans += mc[i];
                crp = 1;
            }
            ans %= MOD;
        }
    }

    cout << ans << el;
}

// PLEASE DO CHECK THE CASE THAT YOU CHANGE THE ORIGINAL VALUE OF SOME VAR AND THEN TRY TO USE THE OLD VALUE OF THAT VAR
// FOR ANOTHER EVALUATION IN THE SAME SCOPE

int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for_(t) solve(i);
    // cerr << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}