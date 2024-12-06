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

using namespace std;

int n;
int f[N][4];
char c[4] = {'A', 'T', 'G', 'C'};
string s;

void xuly() {
    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            f[i][j] = f[i - 1][j] + (s[i] == c[j]);
        }
    }

    cin >> q;
    while (q--) {
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