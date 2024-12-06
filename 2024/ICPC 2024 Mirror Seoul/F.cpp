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

int a[N], b[N];
void xuly() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = n - i + 1;

    int total;
    cin >> total;
    for (int i = 1; i <= total; ++i) {
        int pos, A, B;
        cin >> pos >> A >> B;
        assert(pos >= 1 && pos < n);
        if (a[pos] != A)
            swap(a[pos], b[pos]);
        if (a[pos + 1] != B)
            swap(a[pos + 1], b[pos + 1]);

        // cerr << i << endl;
        // cerr << a[pos] << " " << a[pos + 1] << '\n';
        assert(a[pos] == A);
        assert(a[pos + 1] == B);

        swap(a[pos], a[pos + 1]);
    }

    assert(total <= n * n * 0.7);
    cerr << n << '\n';
    for (int i = 1; i <= n; ++i)
        assert(a[i] == i && b[i] == i);
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