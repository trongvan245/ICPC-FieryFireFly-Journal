
#include <bits/stdc++.h>
#define Nekan ""
#define fi first
#define se second
#define pb push_back
#define LL long long
#define pii pair<int, int>
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
using namespace std;

void xuly() {
    int t = 1, n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        t = t * i % 10;
    cout << t << '\n';
    ;
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
