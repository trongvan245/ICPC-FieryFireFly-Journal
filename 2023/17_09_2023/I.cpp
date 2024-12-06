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

string s;
int d[500];

void xuly() {
    for (int j = 'a'; j <= 'z'; ++j)
        d[j] = 0;
    cin >> s;
    int maxx = 0;
    for (int i = 0; i < s.size(); ++i)
        d[s[i]]++;
    for (int j = 'a'; j <= 'z'; ++j)
        maxx = max(maxx, d[j]);

    cout << (int)s.size() - maxx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.