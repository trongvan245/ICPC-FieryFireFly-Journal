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
    vector<int> mof, origin;
    bool v; cin >> v;
    for (int i = 1; i <= 55; ++i) {
        cout << "? right" << endl;
        bool v; cin >> v;
        bool nv = rand() % 2;

        if (nv != v) {
            cout << "? flip" << endl;
            int tmp; cin >>tmp;
        }

        origin.push_back(v);
        mof.pb(nv);
    }

    int ans = 1;
    while (true) {
        cout << "? right" << endl;
        bool v; cin >> v;
        // bool v;
        // cin >> v;
        origin.erase(origin.begin());
        origin.push_back(v);

        if (mof == origin) {
            cout << "! " << ans << endl;
            return;
        }
        ++ans;
        
        bool nv = rand() % 2;

        if (nv != v) {
            cout << "? flip" << endl;
            int tmp; cin >>tmp;
        }

        // bool nv = rand() % 2;
        // cout << "> " << nv << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // if (fopen(Nekan ".inp", "r")) {
    //     freopen(Nekan ".inp", "r", stdin);
    //     freopen(Nekan ".out", "w", stdout);
    // }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.
