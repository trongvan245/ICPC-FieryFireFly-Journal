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
const long long mod = 998244353;

using namespace std;

int n, m, k;
int w, num_stage;
string s;

void add(int &a, int b) { a = (a + b) % mod; }

int dp[105][(1 << 4)][1 << 17];

vector<int> get(int n) {

    for (int i = 1; i <= n; ++i)
        for (int last_mask = 0; last_mask < (1 << k); ++last_mask)
            for (int stage = 0; stage < (1 << num_stage); ++stage)
                dp[i][last_mask][stage] = 0;

    for (int last_mask = 0; last_mask < (1 << k); ++last_mask) {
        dp[k][last_mask][0] = 1;
    }

    for (int i = k; i < n; ++i)
        for (int stage = 0; stage < (1 << num_stage); ++stage)
            for (int last_mask = 0; last_mask < (1 << k); ++last_mask)
                for (int c = 0; c <= 1; ++c) {
                    int nxt_mask = ((last_mask % (1 << (k - 1))) << 1) + c;
                    int add_stage = (last_mask << 1) + c;

                    int nxt_stage = stage | (1 << add_stage);
                    // if (add_stage == 7)
                    //     cout << i << " " << stage << " " << nxt_stage << " " << last_mask << " " << c << '\n';
                    add(dp[i + 1][nxt_mask][nxt_stage], dp[i][last_mask][stage]);
                }

    // cout << dp[2][3][0] << '\n';
    // cout << dp[3][3][128] << '\n';
    // // cout << dp[3][3][255] << '\n';
    // // cout << dp[2][3][3] << '\n';

    // cout << '\n';

    vector<int> res((1 << num_stage), 0);

    for (int stage = 0; stage < (1 << num_stage); ++stage)
        for (int last_mask = 0; last_mask < (1 << k); ++last_mask)
            add(res[stage], dp[n][last_mask][stage]);

    auto invalid = [&](int stage) -> bool {
        for (int mask = 0; mask < num_stage; ++mask)
            if (BIT(stage, mask))
                if (mask / 2 == w || mask % (1 << k) == w)
                    return false;
        return true;
    };

    // cout << res[0] << '\n';
    // cout << dp[n][3][128] << '\n';
    // cout << res[128] << '\n';
    // cout << '\n';
    // cout << "end debug\n";
    // cout << invalid(2) << '\n';
    for (int stage = 0; stage < (1 << num_stage); ++stage)
        if (invalid(stage))
            res[stage] = 0;

    return res;
}

void xuly() {
    cin >> n >> m >> k;
    if (n > m)
        swap(n, m);
    num_stage = (1 << (k + 1));
    for (int i = 1; i <= k; ++i) {
        char c;
        cin >> c;
        w = w * 2 + (c == '1');
    }

    // cout << w << '\n';

    vector<int> s = get(n);
    vector<int> t = get(m);

    if (n == k && m == k) {
        cout << 1;
        return;
    } else if (n == k) {
        int ans = 0;
        for (int mask_v = 1; mask_v < (1 << num_stage); ++mask_v)
            add(ans, t[mask_v]);
        cout << ans << '\n';
        return;
    }

    int ans = 0;
    for (int mask_s = 0; mask_s < (1 << num_stage); ++mask_s) {
        int mask_v = (1 << num_stage) - 1 - mask_s;
        for (int mask = mask_v; mask > 0; mask = (mask - 1) & mask_v) {
            int res = 1ll * s[mask_s] * t[mask] % mod;
            add(ans, res);

            // if (s[mask_s] && t[mask])
            // cout << mask_s << " " << mask_v << " " << s[mask_s] << " " << t[mask] << '\n';
        }
    }

    cout << ans;
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