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
    int C;
    cin >> C;

    vector<int> A, a, b;

    int x = 0;
    while (cin >> x) {
        A.pb(x);
        x = 0;
    }

    for (int i = 0; i < (int)A.size() / 2; ++i) {
        a.pb(A[i]);
    }
    for (int i = (int)A.size() / 2; i < A.size(); ++i) {
        b.pb(A[i]);
    }

    int n = (int)A.size() / 2;
    vector<int> dp(C + 5, 0), pre(C + 5, 0);
    for (int i = 0; i < n; ++i) {
        int v = a[i], w = b[i];
        for (int j = 0; j <= C; ++j) {
            if (j - w < 0)
                continue;
            dp[j] = max(dp[j], pre[j - w] + v);
        }

        for (int j = 0; j <= C; ++j)
            pre[j] = max(pre[j], dp[j]);
        // for (int j = 0; j <= C; ++j)
        //     cout << pre[j] << " ";
        // cout << '\n';
    }

    int ans = 0;
    for (int j = 0; j <= C; ++j)
        ans = max(ans, pre[j]);

    cout << ans;
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