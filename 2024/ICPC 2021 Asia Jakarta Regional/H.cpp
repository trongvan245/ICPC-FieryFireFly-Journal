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
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

int r, c, s;
int pre[N], dp[N], d[500];

void knapsack(int x, int c) {
    c -= 'a';
    for (int i = 0; i <= s; ++i)
        pre[i] = dp[i];
    for (int i = 0; i <= s - x; ++i) {
        if (pre[i] == -1)
            continue;
        dp[i + x] = pre[i] + (1 << c);
    }
}

void pr(vector<char> &A) {
    if (A.size()) {
        cout << A.back();
        A.pop_back();
    } else
        cout << '.';
}

void xuly() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j) {
            char x;
            cin >> x;
            if (x != '.') {
                d[x]++;
                ++s;
            }
        }
    for (int i = 0; i <= s; ++i)
        dp[i] = -1;
    dp[0] = 0;

    for (int i = 'a'; i <= 'z'; ++i) {
        if (!d[i])
            continue;
        knapsack(d[i], i);
        // for (int j = 0; j <= s; ++j)
        //     cout << dp[j] << " ";
        // cout << '\n';
    }

    pii p = {0, s};
    for (int i = 0; i <= s / 2; ++i) {
        if (dp[i] == -1)
            continue;
        if (abs(s - i - i) <= abs(p.fi - p.se))
            p = {i, s - i};
    }
    // cout << p.fi << " " << p.se << '\n';
    // cout << '\n';
    int mask = dp[p.fi];

    pii ans = {r * 3, c * 3};
    for (int i = r; i <= r * 3; ++i)
        for (int j = c; j <= c * 3; ++j) {
            int x = i * j / 2, y = x;
            if ((i * j) % 2)
                ++y;
            if (p.fi <= x && p.se <= y) {
                // cout << i << " " << j << '\n';
                if (ans.fi * ans.se >= i * j)
                    ans = {i, j};
                break;
            }
        }

    vector<char> A1, A2;
    for (int j = 'a'; j <= 'z'; ++j) {
        while (d[j]) {
            --d[j];

            if (BIT(mask, j - 'a'))
                A1.pb(j);
            else
                A2.pb(j);
        }
    }

    cout << ans.fi << " " << ans.se << '\n';
    for (int i = 1; i <= ans.fi; ++i, cout << '\n')
        for (int j = 1; j <= ans.se; ++j) {
            if ((i + j) % 2 == 0)
                pr(A2);
            else
                pr(A1);
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