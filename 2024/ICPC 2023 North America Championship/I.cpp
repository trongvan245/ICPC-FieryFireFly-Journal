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

void xuly() {
    ll n; cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }

    
    auto num_divisor=[&](int n) {
        int LIM= sqrt(n);
        int ans= 1;
        for (int i=2;i<=LIM;++i) {
            if (n % i != 0) continue;
            int cnt= 0;
            while(n % i == 0) {
                n/= i;
                ++cnt;
            }
            ans*= cnt + 1;
        }
        if (n != 1) ans*= 2;
        return ans;
    };

    auto nth_root= [&](double N, double x) {
        return ceil(std::pow(N, 1.0 / x));
    };
    for (int i = 2; i <= 60; ++i) {
        int core= nth_root(n, i);
        ll t= 1;
        for (int j = 1; j <= i; ++j) t*= core;
        if (t != n) continue;

        if (num_divisor(core) == i) {
            cout << core << '\n';
            return;
        }
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
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.