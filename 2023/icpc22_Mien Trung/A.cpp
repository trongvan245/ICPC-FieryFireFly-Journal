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

const int N = 305;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, k;
int dp[N][N][N], d[N];
char s[N];

int check(int l, int r, int s1) {
    // cout << l << " " << r << " " << s1 << " " << dp[l][r][s1] << '\n';
    if (dp[l][r][s1] != -1)
        return dp[l][r][s1];

    int s2 = d[l - 1] + d[n] - d[r] - s1;
    if (s1 == k) {
        dp[l][r][s1] = 1;
        return 1;
    } else if (s2 == k) {
        dp[l][r][s1] = 0;
        return 0;
    }

    if (l > r) { // not supposed to happen
        return 0;
    }

    int turn = n - (r - l + 1);
    turn %= 2;

    int add = !turn;
    int res1 = check(l + 1, r, s1 + add * (s[l] == 'B'));
    int res2 = check(l, r - 1, s1 + add * (s[r] == 'B'));
    // cout << turn << " " << l << " " << r << " " << s1 << " " << res1 << " "
    //      << res2 << '\n';

    dp[l][r][s1] = ((turn == res1 || turn == res2) ? turn : !turn);

    return dp[l][r][s1];
}

void xuly() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        d[i] = d[i - 1] + (s[i] == 'B');
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            for (int x = 0; x <= k + 1; ++x)
                dp[i][j][x] = -1;

    check(1, n, 0);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = i; j <= n; ++j)
    //         for (int x = 0; x <= k; ++x) {
    //             cout << i << " " << j << " " << x << " " << dp[i][j][x] <<
    //             '\n';
    //         }

    cout << (dp[1][n][0] == 0 ? "YES\n" : "NO\n");
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