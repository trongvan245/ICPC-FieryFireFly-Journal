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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

string n, m;
int d[100];

void upd() {
    string s = "";
    for (int i = 0; i <= 9; ++i)
        d[i] = 0;

    // cout << n << '\n';
    for (int j = 0; j < n.size(); ++j)
        ++d[n[j] - '0'];
    // cout << "asdf\n";
    for (int i = 0; i <= 9; ++i)
        if (d[i]) {
            string x = "";

            while (d[i]) {
                char digit = ('0' + d[i] % 10);
                x = digit + x;
                d[i] /= 10;
            }
            s += x;
            s += '0' + i;
        }
    n = s;
    // cout << s << '\n';
}

void xuly() {
    cin >> n >> m;
    // cout << n << '\n';
    for (int i = 1; i <= 1000; ++i) {
        if (n == m) {
            cout << i;
            return;
        }
        upd();
    }
    cout << "Does not appear";
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