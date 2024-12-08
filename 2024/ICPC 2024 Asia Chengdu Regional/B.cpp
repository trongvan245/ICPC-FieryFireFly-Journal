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

int n, m;
string s;
int dp[305][305][3], pre[305][305][3], f[305][305][305];
void xuly() {
    cin >> n >> m;
    cin >> s;
    s = " " + s;

    int Count = 0;
    for (int i = 1; i <= n; ++i)
        if (s[i] == '?')
            ++Count;

    if (s[1] == '?') {
        pre[1][0][1] = 1;
        pre[0][1][2] = 1;
        pre[0][0][0] = 1;
    } else
        for (int c = 0; c <= 2; ++c) {
            if (s[1] == 'a' + c)
                pre[0][0][c] = 1;
        }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= Count; ++j)
            for (int k = 0; k <= Count; ++k) {
                // choose b
                if (s[i] == 'b') {
                    dp[j][k][1] = (pre[j][k][0] + pre[j][k][2]) % mod;
                } else if (s[i] == '?')
                    dp[j][k][1] = (pre[j - 1][k][0] + pre[j - 1][k][2]) % mod;

                // choose c
                if (s[i] == 'c') {
                    dp[j][k][2] = (pre[j][k][0] + pre[j][k][1]) % mod;
                } else if (s[i] == '?')
                    dp[j][k][2] = (pre[j][k - 1][0] + pre[j][k - 1][1]) % mod;

                // choose a
                if (s[i] == 'a' || s[i] == '?')
                    dp[j][k][0] = (pre[j][k][1] + pre[j][k][2]) % mod;

                // cout << i << " " << j << " " << k << " " << dp[j][k][0] << " " << dp[j][k][1] << " " << dp[j][k][2]
                //      << '\n';
                // cout << dp[0][1][2] << '\n';
            }

        for (int j = 0; j <= Count; ++j)
            for (int k = 0; k <= Count; ++k)
                for (int c = 0; c <= 2; ++c)
                    pre[j][k][c] = dp[j][k][c], dp[j][k][c] = 0;
    }

    for (int j = 0; j <= n; ++j)
        for (int k = 0; k <= n; ++k) {
            int i = Count - j - k;
            if (i < 0)
                continue;
            f[i + 1][j + 1][k + 1] = (1ll * pre[j][k][0] + pre[j][k][1] + pre[j][k][2]) % mod;
            // cout << j << " " << k << " " << i << " " << f[i + 1][j + 1][k + 1] << '\n';
        }
    int LIM = 301;

    for (int i = 1; i <= LIM; ++i)
        for (int j = 1; j <= LIM; ++j)
            for (int k = 1; k <= LIM; ++k) {
                f[i][j][k] = (mod * mod + 1ll * f[i][j][k] + f[i - 1][j][k] + f[i][j - 1][k] + f[i][j][k - 1] -
                              f[i - 1][j - 1][k] - f[i][j - 1][k - 1] - f[i - 1][j][k - 1] + f[i - 1][j - 1][k - 1]) %
                             mod;

                // cout << j << " " << k << " " << i << " " << f[i + 1][j + 1][k + 1] << '\n';
            }

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << f[a + 1][b + 1][c + 1] << '\n';
    }
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