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

const int N = 5005;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int D[N][N];
pii dp[N][N];

void maxx(pii &a, pii b) { a = max(a, b); }
void xuly() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int j = n; j >= 1; --j)
        for (int i = j; i >= 1; --i) {
            if (s[i] != s[j])
                D[i][j] = 0;
            else
                D[i][j] = D[i + 1][j + 1] + 1;
        }

    dp[1][1] = {1, 0};
    pii ans = {0, 0};
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) {
            // cout << i << " " << j << " " << dp[i][j] << " " << f[i][j] << '\n';
            dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);

            if (dp[i][j].fi == 0)
                continue;

            if (j == n) {
                ans = max(ans, {dp[i][j].fi, i});
            } else {
                int k = D[i][j + 1];

                if (k >= j - i + 1) {
                    int nxt = j + 1 + (j - i + 1);
                    maxx(dp[j + 1][nxt], {dp[i][j].fi + 1, i});
                } else {
                    if (s[i + k] < s[j + 1 + k])
                        maxx(dp[j + 1][j + 1 + k], {dp[i][j].fi + 1, i});
                }
            }
        }

    cout << ans.fi << '\n';

    int p = ans.se;
    int curr = n;
    vector<pii> E;
    while (p) {
        E.pb({p, curr});
        // cout << p << " " << curr << '\n';
        int pre = dp[p][curr].se;
        curr = p - 1;
        p = pre;
    }
    reverse(E.begin(), E.end());

    for (auto [u, v] : E) {
        for (int i = u; i <= v; ++i)
            cout << s[i];
        cout << '\n';
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