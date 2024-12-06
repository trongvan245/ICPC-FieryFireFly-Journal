#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int a[1005];
int dp[1005][1005];
int c_dp[1005][1005];

void umax(int &a, int b) { a = max(a, b); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }

    int c, n;
    cin >> c >> n;

    // memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j)
            for (int k = 0; k <= c; ++k)
                c_dp[j][k] = 0;

        for (int j = 0; j <= c; ++j)
            for (int k = 0; k <= c; ++k) {
                if (j + a[i] <= c) {
                    c_dp[j + a[i]][k] |= dp[j][k];
                }
                if (k + a[i] <= c) {
                    c_dp[j][k + a[i]] |= dp[j][k];
                }
            }

        for (int j = 0; j <= c; ++j)
            for (int k = 0; k <= c; ++k) {
                // cout << j << " " << k << " " << c_dp[j][k] << '\n';
                dp[j][k] |= c_dp[j][k];
            }

        dp[0][0] = 1;
        // for (int j = 0; j <= c; ++j) {
        //     if (dp[i][j] != -1) {
        //         umax(dp[i + 1][j], dp[i][j]);
        //         if (j + a[i + 1] <= c) {
        //             umax(dp[i + 1][j + a[i + 1]], dp[i][j]);
        //         } else {
        //             umax(dp[i + 1][j], dp[i][j] + a[i + 1]);
        //         }
        //     }
        // }
    }

    int ans = 0;
    pair<int, int> res = {0, 0};
    for (int j = 0; j <= c; ++j) {
        for (int k = 0; k <= c; ++k)
            if (dp[j][k]) {
                // cout << j << " " << k << " " << '\n';
                if (j + k > ans) {
                    ans = j + k;
                    res = {j, k};
                } else if (j + k == ans) {
                    if (abs(res.fi - res.se) > abs(j - k))
                        res = {j, k};
                }
            }
    }

    if (res.fi < res.se)
        swap(res.fi, res.se);
    cout << res.fi << " " << res.se << '\n';
}