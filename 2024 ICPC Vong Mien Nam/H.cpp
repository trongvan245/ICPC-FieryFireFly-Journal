#include <bits/stdc++.h>
#define Nekan "test"
using namespace std;

int dp[1005][(1 << 10) + 5];
string s[1005];
#define BIT(x, i) ((x) >> (i) & 1)

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (1 << m); ++j) {
            dp[i][j] = 1e7;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        int currentMask = 0;
        for (int j = 0; j < m; ++j) {
            currentMask += (1 << j) * (s[i][j] == '#');
        }
        for (int mask = (1 << m) - 1; mask >= 0; --mask) {
            for (int subMask = mask;; subMask = (subMask - 1) & mask) {
                dp[i][subMask] =
                    min(dp[i][subMask],
                        dp[i][mask] + __builtin_popcount(mask - subMask));
                if (subMask == 0) {
                    break;
                }
            }
        }

        for (int mask = 0; mask < (1 << m); ++mask) {
            for (int subMask = mask;; subMask = (subMask - 1) & mask) {
                dp[i][mask] = min(dp[i][mask], dp[i][subMask]);
                if (subMask == 0) {
                    break;
                }
            }
        }
        for (int subMask = currentMask;;
             subMask = (subMask - 1) & currentMask) {

            int remMask = currentMask - subMask;
            int cnt = 0;
            for (int k = 0; k < m; ++k) {
                if (BIT(remMask, k) == 1 && BIT(remMask, k + 1) == 0) {
                    cnt++;
                }
            }

            // if (i == 3 && subMask == 0) {
            //     cout << cnt << ' ' << dp[i][subMask] << ' ' << dp[i][0] <<
            //     endl;
            // }

            dp[i + 1][subMask] = min(dp[i + 1][subMask], cnt + dp[i][subMask]);

            if (subMask == 0) {
                break;
            }
        }
    }

    cout << dp[n][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int t = 1;
    while (t--)
        sol();
    return 0;
}