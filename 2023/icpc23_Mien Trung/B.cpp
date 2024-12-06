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

const int N = 105;
const long long mod = 2023; /// 998244353

using namespace std;

int n;
int a[N], b[N];
bool gccd[N][N];
int dp[N][N][N], ans[N][N][N];

void xuly() {
    vector<int> A;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
        cin >> a[i];
        A.pb(a[i]);
    }

    sort(a + 1, a + 1 + n);
    sort(A.begin(), A.end());

    for (int i = 1; i <= n; ++i) {
        b[i] = lower_bound(A.begin(), A.end(), a[i]) - A.begin() + 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int k = __gcd(a[i], a[j]);
            // int k = 1;
            gccd[i][j] = (k == 1);
            // cout << i << " " << j << " " << gccd[i][j] << '\n';
        }

    // cout << "asdf\n";
    for (int i = 1; i <= n; ++i) {
        dp[i][i][1] = 1;
        for (int j = i; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                if (!dp[i][j][k])
                    continue;
                // cout << i << " " << j << " " << k << '\n';
                for (int x = j + 1; x <= n; ++x) {
                    if (!gccd[j][x])
                        continue;
                    dp[i][x][k + 1] += dp[i][j][k];
                    dp[i][x][k + 1] %= mod;
                }
            }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                ans[b[i]][b[j]][k] += dp[i][j][k];
                ans[b[i]][b[j]][k] %= mod;
            }

    int q;
    cin >> q;
    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        int nU = 0, nV = 0;
        for (int i = 1; i <= n; ++i) {
            if (u == a[i])
                nU = b[i];
            if (v == a[i])
                nV = b[i];
        }

        // cout << u << " " << v << " " << w << '\n';
        // cout << nU << " " << nV << '\n';
        cout << ans[nU][nV][w + 1] << '\n';
    }
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