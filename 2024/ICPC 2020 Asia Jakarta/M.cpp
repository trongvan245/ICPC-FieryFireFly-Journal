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
    int n, minn_x = 1e9, maxx_x = -1e9, minn_y = 1e9, maxx_y = -1e9;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        minn_x = min(minn_x, x);
        maxx_x = max(maxx_x, x);

        minn_y = min(minn_y, y);
        maxx_y = max(maxx_y, y);
    }

    if (n == 1) {
        cout << "0 0";
        return;
    }
    cout << (maxx_x - minn_x + 1) / 2 << " " << (maxx_y - minn_y + 1) / 2;
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