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
    int n; cin >>n;

    int ans= 0;
    vector<int> c(n), t(n), depth(n);

    int cnt= 0;
    for (int i= 0; i < n ;++i) {
        string s; cin >> s;
        char type= s.back();
        s= s.substr(0, (int)s.size() - 1);

        for (char x : s) if (x == 's') ++c[i]; else ++t[i];
        if (type == '}') --cnt;
        depth[i]= cnt;
        if (type == '{') ++cnt;
    }


    for (int indent = 1; indent <= 1000; ++indent) {

        auto check= [&](int indent) {
            int val= 0;
            for (int i = 0; i < n; ++i) {
                int space = indent * t[i] + c[i];

                if (depth[i] == 0) {
                    if (space != 0) return false;
                    continue;
                }

                // cout << indent << " " << i << " " << space << " " << depth[i] <<'\n';
                if (space % depth[i] != 0) return false;
                if (val == 0) val= space / depth[i];
                else if (val != space / depth[i]) return false;
            }

            return true;
        };

        if (check(indent)) {
            cout << indent;
            return;
        }
    }

    cout << -1;
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