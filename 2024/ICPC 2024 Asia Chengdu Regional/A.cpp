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

    int P50, P95, P99;
    cin >> P50 >> P95 >> P99;

    cout << 100 << '\n';
    for (int i = 1; i <= 50; ++i)
        cout << P50 << " ";
    for (int i = 51; i <= 95; ++i)
        cout << P95 << " ";
    for (int i = 96; i <= 99; ++i)
        cout << P99 << " ";
    cout << P99 + 1;
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