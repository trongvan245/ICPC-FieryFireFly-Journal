// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "testcase"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, a[N], d[N];
ll dp[N];

void xuly() {
    ll n;
    cin >> n;

    ll odd = (n + 1) / 2;
    ll Mai = odd * odd;
    ll draw = odd * (n - odd) * 2;
    ll Cuong = 0;
    for (int i = 1, j = 2; j <= n; ++i, j *= 2) {
        ll num = n / j;
        ll num2 = n / (j * 2);

        num -= num2;

        if (i % 2) {
            Cuong += num * num;
            Cuong += num * num2 * 2;
        } else {
            Mai += num * num;
            draw += num * num2 * 2;
        }
    }

    cout << Cuong << '\n';
    cout << draw << '\n';
    cout << Mai;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    // int t;
    // cin >> t;
    // while (t--)
    xuly();
}

// Surely nothing could go wrong.