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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, k, m, c, d;
int a[N], dd[N], b[N];

void xuly() {
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << " ";
    // cout << '\n';
    // cout << "asdf\n";
    int ans = 0;
    while (1) {
        // cout << "go\n";
        bool cc = false;
        for (int j = 1; j + m - 1 <= n; ++j) {
            // cout << j << '\n';
            int dd = 0;
            for (int i = 1; i <= n; ++i)
                b[i] = a[i];
            for (int i = j; i <= j + m - 1; ++i)
                b[i] = a[i] + c + dd, dd += d;

            // cout << 123 << '\n';
            int Count = 0;
            for (int i = 1; i <= n; ++i)
                if (b[i] >= ans)
                    ++Count;
            // cout << ans << " " << j << '\n';

            // for (int i = 1; i <= n; ++i)
            //     cout << b[i] << " ";
            // cout << '\n';
            if (Count >= k)
                cc = true;
        }
        if (!cc)
            break;

        ++ans;
    }
    cout << ans - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".ans", "w", stdout);
    }
    // int t;
    // cin >> t;
    // while (t--)
    xuly();
}

// Surely nothing could go wrong.