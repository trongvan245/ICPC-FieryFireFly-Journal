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

const int N = 1e7 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int P[N], ans[N];

void add(int& a, int b) {
    a += b;
    a %= mod;
}

void xuly() {
    int N = 1e7;
    P[0] = 1;

    int invalid = 0;
    int invalid_invalid1 = 0;
    int invalid_invalid2 = 0;

    for (int i = 1; i <= N; ++i) {
        P[i] = 1ll * P[i - 1] * i % mod;

        if (i == 1)
            add(invalid, 1);
        else
            add(invalid, 2 * P[i - 1] % mod);

        if (i != 1)
            add(invalid_invalid2, P[i - 2]);
        add(invalid_invalid1, invalid_invalid2);

        ans[i] = P[i];
        add(ans[i], (mod - 1) * invalid % mod);
        add(ans[i], invalid_invalid1);
        // if (i <= 10000)
        //     cout << ans[i] << '\n';
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
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