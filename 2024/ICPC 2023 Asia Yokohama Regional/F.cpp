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

const int N = 5e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int n, q, s1, s2;
int a[N], b[N];

void change(int x, int a[], int &s) {
    if (x > 1)
        s += (a[x] == a[x - 1] ? 1 : -1);

    if (x < n)
        s += (a[x] == a[x + 1] ? 1 : -1);
    a[x] ^= 1;
}

void xuly() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        a[i] = i & 1, b[i] = i & 1;
    s1 = n, s2 = n;
    while (q--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (s == "ROW")
            change(x, a, s1);
        else
            change(x, b, s2);

        cout << 1ll * s1 * s2 << '\n';
    }
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