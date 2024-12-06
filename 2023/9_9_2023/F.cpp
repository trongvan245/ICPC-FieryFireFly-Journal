
#include <bits/stdc++.h>
#define Nekan "F"
#define fi first
#define se second
#define pb push_back
#define LL long long
#define pii pair<int, int>
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
using namespace std;

int n;
map<string, int> m;
vector<string> A;

bool cmp(string a, string b) {
    if (m[a] == m[b])
        return a < b;
    return m[a] > m[b];
}

void xuly() {
    m.clear();
    A.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        int t;
        cin >> s >> t;
        if (!m[s])
            A.pb(s);
        m[s] += t;
    }
    sort(A.begin(), A.end(), cmp);

    cout << A.size() << '\n';
    for (string v : A)
        cout << v << " " << m[v] << '\n';

    // for (auto v : m) {
    //     cout << v.fi << " " << v.se << '\n';
    // }
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
