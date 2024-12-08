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

int n;
int a[N];

vector<int> A;

void check(int x, int y, int depth) {
    A.pb(x);
    A.pb(y);
    // s.insert(x);
    // s.insert(y);
    if (depth == 2)
        return;

    check(x, x & y, depth + 1);
    check(x, x ^ y, depth + 1);
    check(x, x | y, depth + 1);
}

void xuly() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // for (int i = 1; i <= 23; ++i)
    //     rand();
    // int n = 10;
    // int maxx = 1e9;
    // srand(time(NULL));
    // for (int i = 1; i <= n; ++i) {
    //     a[i] = 1;
    //     for (int j = 1; j <= 2; ++j)
    //         a[i] = 1ll * a[i] * rand() % maxx;
    // }

    A.pb(0);

    for (int i = 1; i < n; ++i)
        check(a[i], a[i + 1], 0), check(a[i + 1], a[i], 0);

    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    cout << A.size() << '\n';
    // for (auto e = s.begin(); e != s.end(); e++)
    //     cout << *e << " ";
    // cout << '\n';
    // cout << s.size() << '\n';
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