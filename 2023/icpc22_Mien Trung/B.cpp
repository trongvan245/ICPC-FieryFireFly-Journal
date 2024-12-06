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
const ll mod1 = 1e9 + 7; /// 998244353
const ll mod2 = 998244353;
const ll base1 = 31;
const ll base2 = 37;

using namespace std;

int n;
int P1[N], P2[N], hash1[N], hash2[N], d[N];
string s;

pii getHash(int l, int r) {
    int t1 =
        (mod1 * mod1 + 1ll * hash1[l - 1] * P1[r - l + 1] - hash1[r]) % mod1;
    int t2 =
        (mod2 * mod2 + 1ll * hash2[l - 1] * P2[r - l + 1] - hash2[r]) % mod2;

    return {t1, t2};
}

bool cmp(int l, int r, int u, int v) {
    return (getHash(l, r) == getHash(u, v));
}

void xuly() {
    cin >> s;
    n = s.size();
    s = " " + s;

    P1[0] = P2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        P1[i] = P1[i - 1] * base1 % mod1;
        P2[i] = P2[i - 1] * base2 % mod2;
        hash1[i] = (hash1[i - 1] * base1 + s[i] - 'A') % mod1;
        hash2[i] = (hash2[i - 1] * base2 + s[i] - 'A') % mod2;
    }

    // cout << cmp(1, 2, n - 1, n) << '\n';
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = n - i + 1, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (cmp(1, mid, i, i + mid - 1)) {
                l = mid + 1;
                res = mid;
            } else
                r = mid - 1;
        }
        // cout << i << " " << res << '\n';

        d[0]++;
        d[res + 1]--;
    }

    for (int i = 1; i <= n; ++i)
        d[i] += d[i - 1];
    // cout << d[2] << '\n';

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        if (cmp(1, x, n - x + 1, n) && d[x] >= 3) {
            cout << "YES " << d[x] << '\n';
        } else
            cout << "NO\n";
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