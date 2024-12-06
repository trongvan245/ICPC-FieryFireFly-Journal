
#include <bits/stdc++.h>
#define Nekan "H"
#define fi first
#define se second
#define pb push_back
#define LL long long
#define pii pair<int, int>
const int N = 1e6 + 5;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 3;
const int base = 1003;

const double pi = 3.14159265358979323846;
using namespace std;

int n, k;
pii a[N];

typedef pair<double, int> pdi;

bool cmp(pdi a, pdi b) {
    if (a.fi == b.fi)
        return a.se > b.se;
    return a.fi < b.fi;
}
bool check(double R) {
    // cout << "\n\n";
    int Count = 0;
    vector<pdi> M;
    for (int i = 1; i <= n; ++i) {
        double x = a[i].fi, y = a[i].se;
        double K = sqrt(x * x + y * y);
        if (K > 2 * R)
            continue;
        double db = acos((K / 2) / R);

        double da = (x == 0) ? pi / 2 : atan(y / x);

        if (x == 0 && y < 0)
            da += pi;
        if (x < 0)
            da += pi;

        // cout << K << " " << R << '\n';
        // cout << x << " " << y << " " << da << " " << db << '\n';
        double nL = da - db, nR = da + db;

        M.pb({nL, 1});
        M.pb({nR, -1});
        M.pb({nL + 2 * pi, 1});
        M.pb({nR + 2 * pi, -1});
        M.pb({nL + 4 * pi, 1});
        M.pb({nR + 4 * pi, -1});
    }
    sort(M.begin(), M.end(), cmp);
    // cout << "\n";

    for (pdi v : M) {
        // cout << v.fi << " " << v.se << '\n';
        Count += v.se;
        if (Count >= k)
            return true;
    }
    return false;
}

void xuly() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;

    double L = 0, R = 1000000001;
    for (int i = 1; i <= 100; ++i) {
        double mid = (L + R) / 2.0;

        if (!check(mid))
            L = mid;
        else
            R = mid;
    }

    if (L > 1000000000)
        cout << -1;
    else
        cout << fixed << setprecision(10) << L;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}
