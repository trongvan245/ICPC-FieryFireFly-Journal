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
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    vector<vector<char>> ans(n + 1, vector<char>(n + 1));

    vector<bool> marked(n + 1, false);
    int c_f = 0, c_s = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i <= j || a[i][j] == '?')
                continue;
            if (a[i][j] == 'F')
                ++c_f;
            else
                ++c_s;
            marked[i] = marked[j] = true;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] != '?') {
                ans[i][j] = a[i][j];
                continue;
            }

            if (!marked[i] || !marked[j]) {
                ans[i][j] = (c_f < c_s ? 'F' : 'S');
            } else {
                ans[i][j] = (c_f < c_s ? 'S' : 'F');
            }
        }

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << ans[i][j];
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