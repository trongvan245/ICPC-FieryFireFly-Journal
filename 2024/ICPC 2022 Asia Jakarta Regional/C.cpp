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
    int n, m;
    cin >> n >> m;
    vector<string> t(n);
    vector<int> x(n);
    string s(m + 1, '.');

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> t[i];
    }

    set<string> st;

    // asume all is true
    bool check1 = true;
    for (int i = 0; i < n && check1; i++) {
        for (int j = x[i]; j < x[i] + t[i].size(); j++) {
            if (s[j] == '.') {
                s[j] = t[i][j - x[i]];
            } else if (s[j] != t[i][j - x[i]]) {
                check1 = false;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++)
        if (s[i] == '.')
            check1 = false;

    if (check1) {
        st.insert(s);
    }

    check1 = true;
    for (int fid = 0; fid < n; fid++) {
        s.assign(m + 1, '.');
        check1 = true;
        for (int i = 0; i < n && check1; i++) {
            if (i == fid)
                continue;
            for (int j = x[i]; j < x[i] + t[i].size(); j++) {
                if (s[j] == '.') {
                    s[j] = t[i][j - x[i]];
                } else if (s[j] != t[i][j - x[i]]) {
                    check1 = false;
                    break;
                }
            }
        }

        for (int i = 1; i <= m; i++)
            if (s[i] == '.')
                check1 = false;

        if (check1) {
            st.insert(s);

            if (st.size() > 1) {
                cout << "-2\n";
                return;
            }
        }
    }

    if (st.size() == 1) {
        string ans = *st.begin();
        for (int i = 1; i <= m; i++)
            cout << ans[i];
    } else {
        cout << "-1";
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