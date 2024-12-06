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

    const int N = 1e6 + 5;
    const long long mod = 1e9 + 7; /// 998244353

    using namespace std;

    int n, m;
    int a[N], b[N];
    string s;

    void dfs(int f[], string &s, int l, int r, int par) {
        int u = 0, pos = l;
        while (pos <= r) {
            if (s[pos] == '(')
                break;
            u = u * 10 + s[pos] - '0';
            ++pos;
        }
        f[u] = par;

        // cout << s << " " << l << " " << r << " " << u << " " << par << '\n';
        int C = 1;
        while (pos <= r) {
            int t1 = pos;
            C = 1;
            while (C) {
                ++pos;
                if (s[pos] == '(')
                    C++;
                else if (s[pos] == ')')
                    C--;
            }
            dfs(f, s, t1 + 1, pos - 1, u);
            ++pos;
        }
    }

    void solve(string s, int f[]) {
        int n = s.size();
        s = " " + s;

        string n_s = "";
        for (int i = 1; i <= n; ++i)
            if (s[i] != ' ')
                n_s += s[i];

        s = n_s;
        n = s.size();
        s = " " + s;
        // cout << s << " " << n << '\n';
        // return;
        dfs(f, s, 1, n, -1);
    }

    void xuly() {
        getline(cin, s);
        solve(s, a);

        // cout << "\n\n";

        getline(cin, s);
        solve(s, b);

        int ans = 1;
        // if (n != m) {
        //     ans = -1;
        // }
        for (int i = 1; i <= 1e6; ++i)
            if (a[i] != b[i]) {
                ans = -1;
                // cout << i << " " << a[i] << " " << b[i] << '\n';
            }

        cout << (ans == -1 ? "No" : "Yes");
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