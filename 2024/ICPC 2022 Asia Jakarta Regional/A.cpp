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

bool valid(vector<string> &s, int i, int cf, int dist) {
    int b2 = (cf / 4 % 2 == 1);
    int b1 = (cf / 2 % 2 == 1);
    int b0 = (cf % 2 == 1);

    int val = (s[0][i] == '.') * 4 + (s[1][i] == '.') * 2 + (s[2][i] == '.');

    // cout << "VL " << i << " " << cf << endl;
    // cout << "PP  " << b2 << b1 << b0 << endl;

    bool check_dis = true;
    if (dist > 4) {
        if (b0 + b1 + b2 > 1)
            return false;
    } else if (dist > 1) {
        if (b2 == 1 && b1 == 1)
            return false;
        if (b1 == 1 && b0 == 1)
            return false;
    }

    return (val == (val | cf));
}

bool check_pair(int dist, int i, int cf1, int j, int cf2) {
    for (int ii = 0; ii < 3; ii++) {
        for (int jj = 0; jj < 3; jj++) {
            if (((1 << ii) & cf1) && ((1 << jj) & cf2)) {
                if ((j - i) * (j - i) + (ii - jj) * (ii - jj) < dist)
                    return false;
            }
        }
    }
    return true;
}

int nbit(int a) {
    int re = 0;
    while (a > 0) {
        if (a % 2 == 1)
            re++;
        a /= 2;
    }
    return re;
}

bool check(int dist, int n, int k, vector<string> &s) {
    // cout << "CD:" << dist << endl;
    vector<vector<int>> dp(n + 1, vector<int>(8, 0));

    for (int i = 1; i <= n; i++) {
        // cout << i << endl;
        for (int cf = 0; cf <= 7; cf++) {
            if (i == 1 || valid(s, i - 2, cf, dist))
                dp[i][0] = max(dp[i][0], dp[i - 1][cf]);
            if (valid(s, i - 1, cf, dist)) {
                // cout << i << " " << cf << endl;
                dp[i][cf] = max(dp[i][cf], nbit(cf));
            }
        }

        for (int j = i - 1; j >= 1; j--) {
            for (int cf1 = 1; cf1 <= 7; cf1++) {
                for (int cf2 = 1; cf2 <= 7; cf2++) {
                    if (valid(s, i - 1, cf1, dist) &&
                        valid(s, j - 1, cf2, dist)) {
                        // cout << "YY: " << i << " " << cf1 << " " << j << " "
                        //      << cf2 << endl;
                        if (check_pair(dist, i, cf1, j, cf2)) {
                            // cout << "XX: " << i << " " << cf1 << " " << j <<
                            // " "
                            //<< cf2 << endl;
                            dp[i][cf1] =
                                max(dp[i][cf1], dp[j][cf2] + nbit(cf1));
                        }
                    }
                }
            }
        }

        // cout << dp[i][5] << endl;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int cf = 0; cf <= 7; cf++) {
            ans = max(ans, dp[i][cf]);
        }
    }

    // cout << "DP:" << ans << endl;

    return (ans >= k);
}

bool check5(int dist, int n, int k, vector<string> &s) {
    // cout << "CD:" << dist << endl;
    vector<vector<int>> dp(n + 1, vector<int>(8, 0));
    vector<bool> dup(n + 1, false);

    for (int i = 1; i <= n; i++) {
        // cout << i << endl;
        for (int cf = 0; cf <= 7; cf++) {
            if (i == 1 || valid(s, i - 2, cf, dist))
                dp[i][0] = max(dp[i][0], dp[i - 1][cf]);
            if (valid(s, i - 1, cf, dist)) {
                // cout << i << " " << cf << endl;
                dp[i][cf] = max(dp[i][cf], nbit(cf));
            }
        }

        for (int j = i - 1; j >= 1; j--) {
            for (int cf1 = 1; cf1 <= 7; cf1++) {
                for (int cf2 = 1; cf2 <= 7; cf2++) {
                    if (valid(s, i - 1, cf1, dist) &&
                        valid(s, j - 1, cf2, dist)) {
                        // cout << "YY: " << i << " " << cf1 << " " << j << " "
                        //      << cf2 << endl;
                        if (check_pair(dist, i, cf1, j, cf2)) {
                            // cout << "XX: " << i << " " << cf1 << " " << j <<
                            // " "
                            //<< cf2 << endl;
                            if (dp[i][cf1] < dp[j][cf2] + 1) {
                                if (i - j == 1 && dup[j]) {

                                } else if (i - j == 1) {
                                    dp[i][cf1] = dp[j][cf2] + 1;
                                    dup[i] = true;
                                } else {
                                    dp[i][cf1] = dp[j][cf2] + 1;
                                }
                            } else if (dp[i][cf1] == dp[j][cf2] + 1) {
                                if (dup[i] && i-j>1) {
                                    dup[i] = false;
                                }
                            }
                        }
                    }
                }
            }
        }

        // cout << dp[i][5] << endl;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int cf = 0; cf <= 7; cf++) {
            ans = max(ans, dp[i][cf]);
        }
    }

    // cout << "DP:" << ans << endl;

    return (ans >= k);
}

void xuly() {
    int n, k;
    cin >> n >> k;
    vector<string> s(3);

    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    // cout << "XX" << endl;
    int ans = -1;
    for (int i = 2; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int dist = i * i + j * j;
            // cout << "DIST: " << dist << endl;

            if (dist == 0)
                break;

            if (dist != 5 && check(dist, n, k, s)) {
                // cout << dist << endl;
                ans = max(ans, dist);
            } else if (dist == 5 && check5(5, n, k, s)) {
                ans = max(ans, 5);
            }
        }
    }

    if (ans > 0) {
        cout << fixed << setprecision(7) << (ld)sqrt((ld)ans) << endl;
    } else {
        cout << "-1" << endl;
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