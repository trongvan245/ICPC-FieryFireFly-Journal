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

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int r, c, n, p[11];
int dp[105][105][11], f[105][105];

void add(int& a, int b) {
    a += b;
    a %= mod;
}

void xuly() {
    cin >> r >> c >> n;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            int x;
            cin >> x;
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + x;
        }

    for (int i = 1; i <= n; ++i)
        cin >> p[i];

    for (int i = r; i >= 1; --i)
        for (int j = c; j >= 1; --j) {
            int x = f[r][c] - f[i - 1][c] - f[r][j - 1] + f[i - 1][j - 1];
            if (x <= p[n]) {
                dp[i][j][n] = 1;
            }
            // cout << i << " " << j << " " << 5 << " " << dp[i][j][5] << '\n';
            for (int k = n - 1; k >= 1; --k) {
                for (int ii = i; ii < r; ++ii) {
                    int x =
                        f[ii][c] - f[i - 1][c] - f[ii][j - 1] + f[i - 1][j - 1];
                    if (x <= p[k])
                        add(dp[i][j][k], dp[ii + 1][j][k + 1]);
                }
                for (int jj = j; jj < c; ++jj) {
                    int x =
                        f[r][jj] - f[i - 1][jj] - f[r][j - 1] + f[i - 1][j - 1];
                    if (x <= p[k])
                        add(dp[i][j][k], dp[i][jj + 1][k + 1]);
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k] <<
                // '\n';
            }
        }

    cout << dp[1][1][1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.