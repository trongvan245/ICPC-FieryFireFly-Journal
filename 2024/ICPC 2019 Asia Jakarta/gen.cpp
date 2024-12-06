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
#define rd rand

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

void xuly() {
    srand(time(NULL));
    int n = 1e5, q = 1e5;
    cout << n << " " << q << '\n';
    for (int i = 1; i <= n; ++i) {
        int t = rand() % 2;
        if (t)
            cout << "A";
        else
            cout << "B";
    }
    cout << '\n';

    for (int i = 1; i <= q; ++i) {
        int t = rand() % 2;
        if (t) {
            int l = Rand(1, n), r = Rand(l, n);
            cout << 1 << " " << l << " " << r << '\n';
        } else {
            int l = Rand(1, n), r = Rand(l, n);
            cout << 2 << " " << l << " " << r << " " << Rand(1, 100) << " "
                 << Rand(1, 100) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen(Nekan ".inp", "w", stdout);
    // if (fopen(Nekan ".inp", "r")) {
    //     freopen(Nekan ".inp", "r", stdin);
    // }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.