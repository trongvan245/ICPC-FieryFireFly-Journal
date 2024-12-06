/* try <3 */
#include <bits/stdc++.h>

using namespace std;

#define task "sol"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007;  /// 998244353
const ll base = 331;

void gogo() {
    int n;
    cin >> n;
    vector<char> ans(n);
    for (char &c : ans) {
        cin >> c;
    }
    int res = 0;
    for (int i = 0; i + 1 < (int)ans.size(); ++i) {
        res += (ans[i] == ans[i + 1]);
    }
    cout << res;
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
