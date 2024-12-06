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

const int N = 2005;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, m, D;
int a[N], b[N], c[N], ans[N];
int tonext[11][11];
int temp[11];
int dp[N][N][11];
int truyvet1[N][N][11], truyvet2[N][N][11];
string s;

void xuly() {
    cin >> n >> m >> D;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 1; j <= n; ++j)
        cin >> b[j];
    cin >> s;
    s = " " + s;

    for (int i = 1; i <= m; ++i)
        c[i] = (s[i] == 'R');
    c[m + 1] = 2;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= i; ++j)
            temp[j] = c[j];
        for (int bit = 0; bit <= 1; ++bit) {
            temp[i + 1] = bit;
            // for (int x = 1; x <= i + 1; ++x)
            //     cout << temp[x] << " ";
            // cout << '\n';
            for (int j = 1; j <= i + 1; ++j) {
                bool check = true;

                for (int x = j; x <= i + 1; ++x) {
                    if (temp[x] != c[x - j + 1])
                        check = false;
                }
                if (check) {
                    // cout << "test " << bit << " " << i + 1 << " " << j <<
                    // '\n';
                    tonext[i][bit] = (i + 1) - j + 1;
                    break;
                }
            }
        }

        // cout << i << " " << tonext[i][0] << " " << tonext[i][1] << '\n';
    }
    // cout << '\n';

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= m; ++k)
                dp[i][j][k] = -2e9 - 1;

    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            for (int k = 0; k <= min(i, m); ++k) {
                for (int bit = 0; bit <= 1; ++bit) {
                    if (dp[i][j][k] == -2e9 - 1)
                        continue;
                    int nxt = tonext[k][bit];
                    int res = dp[i][j][k];
                    if (nxt == m)
                        res += D;
                    // cout << i << " " << j << " " << bit << " " << k << " "
                    //      << nxt << " " << res << '\n';
                    // dp[i-1][j][k]
                    if (dp[i + 1][j + bit][nxt] < res) {
                        truyvet1[i + 1][j + bit][nxt] = bit;
                        truyvet2[i + 1][j + bit][nxt] = k;
                        dp[i + 1][j + bit][nxt] = res;
                    }
                }
            }

    // for (int i = 1; i <= n; ++i)
    //     for (int j = 0; j <= i; ++j)
    //         for (int k = 0; k <= m; ++k)
    // cout << i << " " << j << " " << k << " " << dp[i][j][k] <<
    // '\n';

    // cout << "\n\n";
    ll maxx = -1e18, vt1 = -1, vt2 = -1;

    for (int j = 0; j <= n; ++j)
        for (int k = 0; k <= m; ++k) {
            ll res = dp[n][j][k];
            if (res == -2e9 - 1)
                continue;
            res -= a[j] + b[n - j];

            // cout << j << " " << k << " " << res << '\n';
            if (res > maxx) {
                maxx = res;
                vt1 = j;
                vt2 = k;
            }
        }

    for (int i = n; i >= 1; --i) {
        int nxt_vt1 = vt1, nxt_vt2 = vt2;
        ans[i] = truyvet1[i][vt1][vt2];
        nxt_vt1 -= truyvet1[i][vt1][vt2];
        nxt_vt2 = truyvet2[i][vt1][vt2];

        vt1 = nxt_vt1;
        vt2 = nxt_vt2;
    }

    cout << maxx << '\n';
    for (int i = 1; i <= n; ++i)
        cout << (ans[i] ? 'R' : 'B');
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