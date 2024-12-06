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

int n, f[10], res[10];

void xuly() {

    cin >> n;

    if (n == 1) {
        cout << 0;
        return;
    }

    f[0] = 1;
    for (int i = 1; i <= 9; ++i)
        f[i] = f[i - 1] * i;

    for (int i = 9; i >= 1; --i)
        res[i] = n / f[i], n %= f[i];

    res[0] = res[1];
    res[1] = 0;
    if (res[0]) {
        --res[0];
        cout << 1;
    }
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= res[i]; ++j)
            cout << i;
    }
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