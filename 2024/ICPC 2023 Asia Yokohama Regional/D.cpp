#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    string s;
    cin >> s;

    int n = (int)s.size();
    s = ' ' + s;

    vector<long long> hsh(n + 5, 0);
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
    vector<long long> pw(n + 5, 0);

    const int base = 331;
    const long long mod = 1e9 + 7;

    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        hsh[i] = (hsh[i - 1] * base + s[i] - 'a' + 1) % mod;
        pw[i] = pw[i - 1] * base % mod;
    }

    auto getHash = [&](int l, int r) {
        return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % mod + mod * mod) % mod;
    };

    auto umin = [&](int &a, int b) {
        if (a > b) {
            a = b;
            return true;
        }
        return false;
    };

    function<int(int, int)> solve = [&](int l, int r) -> int {
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        if (l > r) {
            return 0;
        }

        dp[l][r] = n;

        for (int len = 1; len <= r - l + 1; ++len) {
            if ((r - l + 1) % len != 0 || (r - l + 1) / len >= 10 ||
                (r - l + 1) / len <= 1) {
                continue;
            }
            int ok = 1;
            for (int i = l; i <= r; i += len) {
                ok &= getHash(l, l + len - 1) == getHash(i, i + len - 1);
            }
            if (ok) {
                if (umin(dp[l][r], solve(l, l + len - 1) + 3)) {
                }
            }
        }

        for (int mid = l; mid < r; ++mid) {
            umin(dp[l][r], solve(l, mid) + solve(mid + 1, r));
        }

        umin(dp[l][r], r - l + 1);
        return dp[l][r];
    };

    solve(1, n);

    // cout << solve(1, 12) << endl;

    function<string(int, int)> trace = [&](int l, int r) -> string {
        if (l > r) {
            return "";
        }

        // cout << l << ' ' << r << endl;

        for (int len = 1; len <= r - l + 1; ++len) {
            if ((r - l + 1) % len != 0 || (r - l + 1) / len >= 10 ||
                (r - l + 1) / len <= 1) {
                continue;
            }
            int ok = 1;
            for (int i = l; i <= r; i += len) {
                ok &= getHash(l, l + len - 1) == getHash(i, i + len - 1);
            }
            if (ok) {
                if (dp[l][r] == solve(l, l + len - 1) + 3) {
                    string res = to_string((r - l + 1) / len) + "(" +
                                 trace(l, l + len - 1) + ")";
                    // cout << "CAC " << l << ' ' << r << ' ' << res << '\n';
                    return res;
                }
            }
        };

        for (int mid = l; mid < r; ++mid) {
            if (dp[l][r] == solve(l, mid) + solve(mid + 1, r)) {
                string a = trace(l, mid);
                string b = trace(mid + 1, r);
                // cout << l << ' ' << r << ' ' << a + b << '\n';
                return a + b;
            }
        }

        // cout << l << ' ' << r << ' ' << s.substr(l, r - l + 1) << '\n';
        return s.substr(l, r - l + 1);
    };

    cout << trace(1, n);
}