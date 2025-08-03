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
    int s; cin >> s;
    ld l = 1, r = 20000;
    for (int i = 1; i <= 500; ++i) {
        ld mid = (l + r) / 2.0;
        
        long long total = 0;
        long long min_y = 20000;
        for (long long x = 1; x <= 20000; ++x) {
            if (x > mid) break;
            while(min_y * min_y + x * x > mid * mid) --min_y;
            total += min_y;
        }
        if (total * 4 > s) {
            r = mid;
        }
        else {
            l = mid;
        }
    }

    cout << fixed << setprecision(12) << l << '\n';
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