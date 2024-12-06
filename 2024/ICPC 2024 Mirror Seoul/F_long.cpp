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
#define debug(x)                                                               \
    if (enable_debug)                                                          \
        cerr << "[debug] " << #x << " : " << x << endl;
#define M_PI 3.14159265358979323846

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

typedef tree<ll, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const long long MOD = 998244353;
const bool enable_debug = true;

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

void solve(int ith) {
    int n;
    // cin >> n;
    n = ith;
    if (n < 3)
        return;

    vector<vector<int>> v(2, vector<int>(n + 1));
    vector<vector<pii>> pos(2, vector<pii>(n + 1));

    for_(n) {
        v[0][i + 1] = n - i;
        v[1][i + 1] = n - i;
    }

    auto rank = [&](int t, int i) {
        return max(v[0][i - 1] - v[t][i], v[1][i - 1] - v[t][i]);
    };

    auto logv = [&]() -> void {
        for (int i = 1; i <= n; i++)
            cout << v[0][i] << " ";
        cout << el;
        for (int i = 1; i <= n; i++)
            cout << v[1][i] << " ";
        cout << el;
        cout << endl;
    };

    int total = 0;
    vector<vector<int>> ans;
    // logv();

    for (int i = 1; i <= n; i++) {
        // debug(i);
        pii p1 = mp(-1, -1), p2 = mp(-1, -1);
        for (int j = i; j <= n; j++) {
            if (v[0][j] == i) {
                if (p1.fi == -1)
                    p1 = mp(0, j);
                else
                    p2 = mp(0, j);
            }
            if (v[1][j] == i) {
                if (p1.fi == -1)
                    p1 = mp(1, j);
                else
                    p2 = mp(1, j);
            }
        }

        if (p1.fi == -1)
            continue;

        // debug(v[p1.fi][p1.se] << " " << v[p2.fi][p2.se]);
        // debug(i << " " << p1 << " " << p2);

        if (rank(p1.fi, p1.se) < rank(p2.fi, p2.se)) {
            swap(p1, p2);
        }

        // debug(i << " " << p1 << " " << p2);
        // debug(rank(p1.fi, p1.se) << " " << rank(p2.fi, p2.se))

        int cnt = 0;
        while (p1.se != i) {
            if (v[0][p1.se - 1] > v[1][p1.se - 1]) {
                ans.pb({p1.se - 1, v[0][p1.se - 1], v[p1.fi][p1.se]});
                swap(v[0][p1.se - 1], v[p1.fi][p1.se]);
                p1.fi = 0;
                p1.se = p1.se - 1;

            } else {
                ans.pb({p1.se - 1, v[1][p1.se - 1], v[p1.fi][p1.se]});
                swap(v[1][p1.se - 1], v[p1.fi][p1.se]);
                p1.fi = 1;
                p1.se = p1.se - 1;
            }
            cnt++;
            total++;
        }

        // cout << cnt << el;
        // logv();

        cnt = 0;
        while (p2.se != i) {
            if (v[0][p2.se - 1] > v[1][p2.se - 1]) {
                ans.pb({p2.se - 1, v[0][p2.se - 1], v[p2.fi][p2.se]});
                swap(v[0][p2.se - 1], v[p2.fi][p2.se]);
                p2.fi = 0;
                p2.se = p2.se - 1;
            } else {
                ans.pb({p2.se - 1, v[1][p2.se - 1], v[p2.fi][p2.se]});
                swap(v[1][p2.se - 1], v[p2.fi][p2.se]);
                p2.fi = 1;
                p2.se = p2.se - 1;
            }
            cnt++;
            total++;
        }

        // cout << cnt << el;
        // logv();
    }

    cout << n << '\n';
    cout << ans.size() << el;
    for (auto vec : ans) {
        cout << vec << el;
    }
}

// PLEASE DO CHECK THE CASE THAT YOU CHANGE THE ORIGINAL VALUE OF SOME VAR AND
// THEN TRY TO USE THE OLD VALUE OF THAT VAR FOR ANOTHER EVALUATION IN THE SAME
// SCOPE

int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    t = 100;
    for_(t) solve(i + 1);
    // cerr << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}