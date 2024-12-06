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

int n, L, R, k;
int a[N], b[N];
int mL[N], mR[N];

void xuly() {
    cin >> n >> L >> R >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int base = 0;
    for (int i = n - 1; i >= 1; --i) {
        int diff;
        if (a[i] < a[i + 1])
            ++base;
        else if (a[i] > a[i + 1])
            --base;
        mL[i] = min(mL[i + 1], base), mR[i] = max(mR[i + 1], base);
        cout << i << " " << mL[i] << " " << mR[i] << '\n';
    }

    int pre = 0;
    for (int i = 0; i < n; ++i) {
        cout << i << '\n';
        if (a[i] == a[i + 1]) {
            if (b[i] + mR[i + 1] > R || b[i] + mL[i + 1] < L) {
                cout << -1;
                return;
            }
            b[i + 1] = b[i];
        } else if (a[i] < a[i + 1]) {
            int l = 1, r = 1e9, res = -1;
            // b[i] + mid
            while (l <= r) {
                int mid = (l + r) / 2;
                if (b[i] + mid + mL[i + 1] >= L) {
                    res = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            b[i + 1] = b[i] + res;
            cout << res << " " << b[i + 1] << '\n';
            cout << mR[i + 1] << '\n';

            if (res == -1 || b[i + 1] + mR[i + 1] > R) {
                cout << -1;
                return;
            }
        } else if (a[i] > a[i + 1]) {
            int l = 1, r = 1e9, res = -1;
            // b[i]- mid;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (b[i] - mid + mL[i + 1] >= L) {
                    l = mid + 1;
                    res = mid;
                } else
                    r = mid - 1;
            }

            b[i + 1] = b[i] + res;
            if (res == -1 || b[i + 1] + mR[i + 1] > R) {
                cout << 1;
                return;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << b[i] << " ";
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