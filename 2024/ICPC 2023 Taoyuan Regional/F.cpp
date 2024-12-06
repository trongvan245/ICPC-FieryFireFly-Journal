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

struct three {
    ll d, s, pos;
    bool operator<(const three &other) const {
        if (d * other.s == other.d * s)
            return pos < other.pos;
        return d * other.s < other.d * s;
    }
} a[1005];

void xuly() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].d >> a[i].s;
        a[i].pos = i;
    }
    sort(a + 1, a + 1 + n);

    int sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cout << a[i].pos << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.