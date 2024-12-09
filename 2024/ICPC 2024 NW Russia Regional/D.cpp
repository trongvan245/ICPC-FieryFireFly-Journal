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

int n;
int poww(int a, int n) {
    ll res = 1, t = a;
    while (n) {
        if (n & 1)
            res = res * t % mod;
        t = t * t % mod;
        n /= 2;
    }
    return res;
}

int inv(int val) { return poww(val, mod - 2); }
bool check(vector<int> &v) {
    vector<int> k(n + 2, 0);
    int inv2 = inv(mod - 2);

    for (int i = 1; i <= n; ++i)
        if (v[i] < 0)
            return false;

    ll base = poww(2, n - 1);
    for (int i = 1; i <= n; ++i) {
        k[1] = (k[1] + base * v[i]) % mod;
        base = base * inv2 % mod;
    }

    int mauso = poww(2, n);
    if (n % 2 == 0)
        mauso = (mauso - 1 + mod) % mod;
    else
        mauso = (mauso + 1) % mod;

    k[1] = 1ll * k[1] * inv(mauso) % mod;

    for (int i = 2; i <= n; ++i)
        k[i] = (2 * mod + v[i - 1] - 2 * k[i - 1]) % mod;

    // for (int i = 1; i <= n; ++i)
    //     cout << k[i] << " ";
    // cout << '\n';
    // cout << '\n';

    for (int i = 1; i <= n; ++i)
        if (k[i] < 0)
            return false;

    k[n + 1] = k[1];
    for (int i = 1; i <= n; ++i)
        if (v[i] != 2ll * k[i] + k[i + 1])
            return false;

    return true;
}

void xuly() {

    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int LIM = 1e9;
    int ans = 0;
    for (int c = 0; c <= 2; ++c) {
        int l = 0, r = LIM / 3, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            vector<int> nA(n + 1);
            for (int i = 1; i <= n; ++i)
                nA[i] = a[i] - (mid * 3 + c);
            if (check(nA)) {
                res = mid * 3 + c;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        // cout << res << '\n';
        ans = max(ans, res);
    }
    cout << ans << '\n';
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