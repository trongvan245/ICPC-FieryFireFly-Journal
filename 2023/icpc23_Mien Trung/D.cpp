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

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;
int n, m, k;

bool check(vector<vector<char>>& a, int x) {

    int Count = 0;
    x = x * 2 + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'x') {
                for (int t = 1; t < x; ++t) {
                    ++j;
                    if (a[i][j] == '#')
                        break;
                    if (j > m)
                        break;
                }
                ++Count;
            }
        }
    }

    return (Count <= k);
}

void xuly() {
    cin >> n >> m >> k;

    vector<vector<char>> a;
    a.assign(n + 5, vector<char>(m + 5, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    int L = 0, R = m, res = -1;

    while (L <= R) {
        int mid = (L + R) / 2;

        if (check(a, mid)) {
            R = mid - 1;
            res = mid;
        } else
            L = mid + 1;
    }

    cout << res << '\n';
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