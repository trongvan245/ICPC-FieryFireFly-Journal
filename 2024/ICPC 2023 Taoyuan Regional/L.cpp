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

ll n;
ll ans = 1;
int Count = 0;
int a[100];
int check(int n) {
    if (n == -1)
        return -1;

    int val = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            if (BIT(mask, j))
                sum += a[j + 1];

        if (sum <= 9)
            val |= (1 << sum);
    }
    return val;
}
void build(int pos, int sum) {
    if (BIT(check(pos), 9))
        return;
    if (n - sum > 9)
        ans = max(ans, 1ll * pos + 1);
    if (sum > n)
        return;
    if (sum == n) {
        ans = max(ans, 1ll * pos);
        return;
    }

    for (int i = 1; i <= 8; ++i) {
        a[pos + 1] = i;
        build(pos + 1, sum + i);
    }
}
void xuly() {
    cin >> n;
    if (n <= 20) {
        build(0, 0);
    } else {
        ans = max(8 + (n - 8) / 10, 1 + (n - 10) / 2);
        if (n % 2 == 0)
            ans = max(ans, n / 2);
    }
    cout << ans % mod << '\n';
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