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
    int k = 1, p = 3;
    int n = 5000;
    vector<vector<long long>> C(n+1, vector<long long>(n+1, 0));

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            if (k == 0 || k == i)
                C[i][k] = 1; // base case
            else
                C[i][k] = (C[i-1][k] + C[i-1][k-1]) % p; // recurrence
        }
    }

    for (int k = 1; k <= 5; ++k) {
        ll target = 1;
        for (int i = 1; i <= k; ++i) target *= p;

        vector<int> d(p);
        if (target >= n) break;
        for (int a = 0; a < target; ++a) 
        for (int b = 0; b <= a; ++b) {
            int val = C[a][b];
            d[val]++;
        }

        cout << "This is for k = " << k << '\n';
        for (int m = 0; m < p; ++m) cout << d[m] << " ";
        cout << '\n';
        cout << '\n';
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