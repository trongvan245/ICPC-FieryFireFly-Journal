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

void xuly() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
        cin >> c[i][j];
    }

    vector<vector<long double>> dp(2 * h + 5, vector<long double>(2 * w + 5, 1e9));

    ld w1 = 5;
    ld w2 = 3.1415926535897932384626433832795 * 5 / 2.0;
    dp[0][0] = 0;
    for (int i = 0; i <= 2 * h; ++i)
    for (int j = 0; j <= 2 * w; ++j) {
        if (i % 2 == 1 && j % 2 == 1) continue;
        // cout << i << " " << j << " " << dp[i][j] << '\n';
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + w1);
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + w1);

        if (i == 2 * h || j == 2 * w) continue;
        if (c[i / 2][j / 2] == 'O' && !(i % 2 == 0 && j % 2 == 0)) {
            dp[i + 1][j + 1] = min(dp[i + 1][j +1], dp[i][j] + w2);
        }
    }

    cout << fixed << setprecision(12) << dp[2 * h][2 * w];
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