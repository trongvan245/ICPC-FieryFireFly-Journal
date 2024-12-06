/* try <3 */
#include <bits/stdc++.h>

using namespace std;

#define task "test"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007; /// 998244353
const ll base = 331;
const int N = 1e5 + 5;

int n, m, a[N];

int solve(int x, int y, int z) {
    a[0] = -1e9 - 15;
    for (int l = 0, r = 0, i = 1; i <= n; ++i) {
        while (r + 1 <= i && a[i] - a[r + 1] >= x) {
            r++;
        }

        while (l < i && a[i] - a[l] > y) {
            l++;
        }

        z -= r - l + 1;
        // if (r < i && l < i && l <= r && a[i] - a[r] >= x && a[i] - a[r] <= y
        // &&
        //     a[i] - a[l] >= x && a[i] - a[l] <= y) {
        //     z -= r - l + 1;
        // }
        if (z <= 0) {
            return a[i];
        }
    }
    return -1;
}
void gogo() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z <= 0)
            continue;
        int tmp = solve(x, y, z);
        if (tmp == -1) {
            cout << -1;
            return;
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    gogo();
}