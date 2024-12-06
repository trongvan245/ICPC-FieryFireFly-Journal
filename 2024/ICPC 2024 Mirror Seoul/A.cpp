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

int a[105][305];
void xuly() {
    int n, m;
    cin >> n >> m;
    vector<int> timeline;
    timeline.pb(0);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];

            timeline.pb(a[i][j] - 1);
        }

    sort(timeline.begin(), timeline.end());

    vector<int> track(n + 2, 1), res(m + 1, 0);

    for (int v : timeline) {
        vector<int> cnt(m + 1, 0);

        // cout << v << '\n';
        for (int i = 1; i <= n; ++i) {
            while (a[i][track[i]] <= v && track[i] <= m)
                ++track[i];
            ++cnt[track[i]];
            // cout << track[i] << " ";
        }
        // cout << '\n';

        for (int i = 1; i <= m; ++i)
            res[i] = max(res[i], cnt[i]);
    }

    for (int i = 1; i <= m; ++i)
        cout << res[i] << " ";
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