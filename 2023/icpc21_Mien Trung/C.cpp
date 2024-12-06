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

const int N = 1e6 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, top;
int d[N];
ld a[N], b[N], A[N], B[N], f[N];

ld get(int l, int r, ld x) {
    cout << l << " " << r << " " << a[r] << " " << '\n';
    cout << A[r] - A[l - 1] << " " << B[r] - B[l - 1] << '\n';
    return (A[r] - A[l - 1]) - (B[r] - B[l - 1]) * x + (r - l + 1) * x * x;
}

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        A[i] = A[i - 1] + a[i] * a[i];
        B[i] = B[i - 1] + 2 * a[i];
        f[i] = f[i - 1] + a[i];
    }

    a[0] = -1e5;
    for (int i = 1; i <= n; ++i) {
        ld avg = a[i];
        int l = i;
        while (top > 0 && b[top] > avg) {
            l = d[top--];
            avg = (f[i] - f[l - 1]) / (i - l + 1);
        }
        d[++top] = l;
        b[top] = avg;
    }

    // for (int i = 1; i <= top; ++i)
    //     cout << d[i] << " " << b[i] << '\n';

    ld ans = 0;
    int pos = n;
    for (int i = top; i >= 1; --i) {
        while (pos >= d[i]) {
            ld t1 = a[pos] - b[i];
            ans += t1 * t1;
            --pos;
        }
    }
    cout << fixed << setprecision(6) << sqrt(ans) << '\n';
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