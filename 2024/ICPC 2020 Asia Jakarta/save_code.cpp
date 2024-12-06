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


int a[N], b[N], c[N];

void xuly() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = i + 1;
    a[n] = 1;

    for (int i = 1; i <= n; ++i)
        b[i] = a[i];

    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << '\n';
    int mv = 0;
    while (true) {
        ++mv;
        for (int i = 1; i <= n; ++i)
            c[i] = b[i];
        for (int i = 1; i <= n; ++i)
            b[i] = c[b[i]];

        bool flag = true;
        for (int i = 1; i <= n; ++i)
            if (c[i] != b[i])
                flag = false;
        for (int i = 1; i <= n; ++i)
            cout << b[i] << " ";
        cout << '\n';
        if (flag)
            break;
        if (mv >= 10)
            break;
    }

    cout << mv << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // if (fopen(Nekan ".inp", "r")) {
    //     freopen(Nekan ".inp", "r", stdin);
    //     freopen(Nekan ".out", "w", stdout);
    // }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.