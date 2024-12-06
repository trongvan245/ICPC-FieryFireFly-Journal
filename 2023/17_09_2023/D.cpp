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
int a[N], dd[N];

bool check(ll X) {
    // cout << "\n\n";
    // cout << X << '\n';
    for (int i = 0; i <= n; ++i)
        dd[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int L = max(1, i - m + 1);
        ll R;
        if (a[i] + c >= X)
            R = i + 1;
        else {
            if (d == 0)
                R = L;
            else {
                R = i - (X - a[i] - c - 1) / d;
                R = max(1ll * L, R);
            }
        }
        // cout << i << " " << L << " " << R << '\n';
        ++dd[L], --dd[R];
    }

    int Count = 0;
    for (int i = m + 1; i <= n; ++i)
        if (a[i] >= X)
            ++Count;
    // cout << '\n';
    // cout << dd[1] << '\n';
    for (int i = 1; i <= n; ++i) {
        dd[i] += dd[i - 1];
        // cout << i << " " << dd[i] << " " << Count << '\n';
        if (Count + dd[i] >= k)
            return true;

        if (i + m <= n) {
            if (a[i + m] >= X)
                --Count;
        } else
            break;
        if (a[i] >= X)
            ++Count;
    }
    return false;
}

void xuly() {
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    ll L = 0, R = 1e18, res = -1;

    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            L = mid + 1;
            res = mid;
        } else {
            R = mid - 1;
        }
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
    // int t;
    // cin >> t;
    // while (t--)
    xuly();
}

// Surely nothing could go wrong.