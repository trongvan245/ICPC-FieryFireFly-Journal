
#include <bits/stdc++.h>
#define Nekan "C"
#define fi first
#define se second
#define pb push_back
#define LL long long
#define pii pair<int, int>
const int N = 1e6 + 5;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 3;
const int base = 1003;
using namespace std;

string a, b;
int d[500], dd[500];
map<pii, bool> m;

void xuly() {
    m.clear();
    cin >> a >> b;

    int n = b.size(), M = a.size();
    a = " " + a;
    b = " " + b;

    d['a' - 1] = dd['a'] = 1;
    for (int i = 'a'; i <= 'z'; ++i) {
        int base1 = rand(), base2 = rand();
        d[i] = 1ll * d[i - 1] * base1 % mod1;
        dd[i] = 1ll * d[i - 1] * base2 % mod2;
        // cout << d[i] << " ";
    }
    // cout << '\n';

    for (int i = 1; i <= n; ++i) {
        int hash1 = 0, hash2 = 0;
        for (int j = i; j <= n; ++j) {
            hash1 = (hash1 + d[b[j]]) % mod1;
            hash2 = (hash2 + dd[b[j]]) % mod2;
            m[{hash1, hash2}] = true;
        }
    }

    int ans = 0, vt = 0;

    for (int i = 1; i <= M; ++i) {
        int hash1 = 0, hash2 = 0;
        for (int j = i; j <= M; ++j) {
            hash1 = (hash1 + d[a[j]]) % mod1;
            hash2 = (hash2 + dd[a[j]]) % mod2;
            if (m[{hash1, hash2}]) {
                if (j - i + 1 > ans) {
                    ans = j - i + 1;
                    vt = i;
                }
            }
        }
    }

    if (!ans) {
        cout << "NONE\n";
        return;
    }
    for (int i = vt; i <= vt + ans - 1; ++i)
        cout << a[i];
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        xuly();
}
