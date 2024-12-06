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

int n, a[11][11];
int dp[2][(1 << 18)][11];

int num_triangle(int mask) {
    int ans = 0;
    for (int i = 1; i <= 18; i += 3) {
        if (BIT(mask, i - 1) && BIT(mask, i) && BIT(mask, i + 1))
            ++ans;
    }

    if (BIT(mask, 2) && BIT(mask, 4) && BIT(mask, 6))
        ++ans;
    if (BIT(mask, 5) && BIT(mask, 10) && BIT(mask, 12))
        ++ans;
    if (BIT(mask, 8) && BIT(mask, 13) && BIT(mask, 15))
        ++ans;

    return ans;
}
void add(int& turn, int& mask, int& m, int& s1) {
    int f1 = num_triangle(mask);
    mask += 1 << (m - 1);
    int f2 = num_triangle(mask);

    if (f1 < f2) {
        if (!turn)
            s1 += f2 - f1;
    } else
        turn = !turn;
}

int check(int turn, int mask, int s1) {
    // cout << turn << " " << mask << " " << s1 << '\n';
    // if (turn == 1 && mask == 8444 && s1 == 1)
    //     cout << turn << " " << mask << " " << s1 << '\n';
    if (dp[turn][mask][s1] != -1)
        return dp[turn][mask][s1];

    if (mask == (1 << 18) - 1) {
        int s2 = 9 - s1;
        dp[turn][mask][s1] = (s1 > s2 ? 0 : 1);
        return dp[turn][mask][s1];
    }

    // if (mask != 0)
    //     return 0;
    bool c = false;
    for (int i = 1; i <= 18; ++i) {
        if (BIT(mask, i - 1))
            continue;

        int n_turn = turn, n_mask = mask, n_s1 = s1;
        add(n_turn, n_mask, i, n_s1);
        // if (mask == 1 && n_mask == 9) {
        //     cout << turn << " " << mask << " " << s1 << " " << i << "
        //     240504\n";
        // }

        if (check(n_turn, n_mask, n_s1) == turn)
            c = true;
    }

    if (c)
        dp[turn][mask][s1] = turn;
    else
        dp[turn][mask][s1] = !turn;

    return dp[turn][mask][s1];
}

void xuly() {
    int turn = 0, cur = 0, s1 = 0, s2 = 0;
    cin >> n;
    // cout << '\n';
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        int m = a[u][v];

        add(turn, cur, m, s1);
        // cout << turn << " " << cur << " " << s1 << '\n';
    }

    int res = dp[turn][cur][s1];

    cout << (!res ? "A wins." : "B wins.") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    memset(dp, -1, sizeof(dp));
    // return 0;

    a[1][2] = 1;
    a[1][3] = 2;
    a[2][3] = 3;
    a[2][4] = 4;
    a[2][5] = 5;
    a[4][5] = 6;
    a[3][5] = 7;
    a[3][6] = 8;
    a[5][6] = 9;
    a[4][7] = 10;
    a[4][8] = 11;
    a[7][8] = 12;
    a[5][8] = 13;
    a[5][9] = 14;
    a[8][9] = 15;
    a[6][9] = 16;
    a[6][10] = 17;
    a[9][10] = 18;

    check(0, 0, 0);

    // cout << num_triangle((1 << 18) - 1);

    // for (int i = 0; i <= 1; ++i)
    //     for (int mask = 0; mask < (1 << 9); ++mask)
    //         for (int j = 0; j <= 9; ++j)
    //             cout << i << " " << mask << " " << j << " " << dp[i][mask][j]
    //                  << '\n';

    // cout << dp[1][9][0] << '\n';
    // return 0;

    // cout << dp[1][8440][1] << '\n';
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Game " << i << ": ";
        xuly();
    }
}

// Surely nothing could go wrong.