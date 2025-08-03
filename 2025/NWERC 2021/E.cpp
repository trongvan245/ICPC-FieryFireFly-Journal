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
    string s; cin >> s;
    int pos = s.find('/');
    int a = stoi(s.substr(0, pos));
    int b = stoi(s.substr(pos + 1));

    int c = __gcd(a, b);
    a /= c; b /= c;

    if (a < b) {
        if (a != b - 1) {
            cout << "impossible" << '\n';
            return;
        }

        cout << b << " " << b - 1 << '\n';
        for (int i = 2; i < b; ++i) {
            cout << i << " " << 1 << '\n';
        }
        return;
    }
    
    if (b == 1) {
        b *= 3000, a *= 3000;
    }
    else {
        b = b * 1000, a = a * 1000;
    }

    a -= b - 1;

    vector<int> d(b + 1, 0);
    int maxx = -1;
    for (int i = 2; i <= b; ++i) {
        d[i] = min(a, maxx + 1);
        a -= d[i];
        maxx = max(d[i], maxx);
    }

    cout << b << " " << b - 1 << '\n';
    for (int i = 2; i <= b; ++i) {
        if (d[i] == 0) d[i] = 1;
        else d[i] += 1;
        cout << i << " " << d[i] << '\n';
    }

    assert(a == 0);
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