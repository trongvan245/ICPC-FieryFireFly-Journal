// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan ""
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
const ll base = 31;

using namespace std;

struct four {
    int l, r, i, type;
};
vector<four> M;

int n, m;
int hashT[N], hashS[N], P[N];
string s;

bool check(int i, int j, int u, int v) {
    int hash1 = (mod * mod + hashT[j] - hashT[i - 1] * P[j - i]) % mod;
    int hash2 = (mod * mod + hashS[i] - hashS[j + 1] * P[j - i]) % mod;
    return (hash1 == hash2);
}

void xuly() {
    cin >> n >> m;
    cin >> s;
    s = " " + s;

    P[0] = 1;
    for (int i = 1; i <= n; ++i)
        P[i] = P[i - 1] * base % mod;
    for (int i = 1; i <= n; ++i)
        hashT[i] = (hashT[i - 1] * base + s[i] - 'a') % mod;

    for (int i = n; i >= 1; --i)
        hashS[i] = (hashS[i + 1] * base + s[i] - 'a') % mod;

    for (int i = 1; i <= n; ++i) {
        int L = 1, R = n, res = 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (i - mid < 1 || i + mid > n) {
                R = mid - 1;
                continue;
            }

            if (check(i - mid, i - 1, i + 1, i + mid)) {
                L = mid + 1;
                res = mid;
            } else
                R = mid - 1;
        }

        M.pb({i - res, i, i + res, 1});

        L = 1, R = n, res = 0;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (i - mid + 1 < 1 || i + mid > n) {
                R = mid - 1;
                continue;
            }

            if (check(i - mid + 1, i, i + 1, i + mid)) {
                L = mid + 1;
                res = mid;
            } else
                R = mid - 1;
        }

        if (res != 0) {
            M.pb({i - res + 1, i, i + res, 0});
        }
    }

    for (four v : M) {
        int L= v.L, R= v.R;
        d[L]
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