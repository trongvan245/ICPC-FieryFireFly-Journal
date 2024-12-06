// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan ""
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

int n, maxx;
int id[1024];
vector<int> ans[15], even, odd;

void add(int depth, int l, int r) {
    for (int i = l; i <= r; ++i)
        ans[depth].pb(pos[i]);
    // for (int v : odd)
    //     if (l <= v && v <= r)
    //         ans[depth].pb(v);
    // for (int v : even)
    //     if (l <= v && v <= r)
    //         ans[depth].pb(v);
}
void build(int l, int r, int depth) {
    if (depth == 10)
        return;

    int mid = (l + r) / 2;
    add(depth, l, mid);

    if (l == r)
        return;
    build(l, mid, depth + 1);
    build(mid + 1, r, depth + 1);
}

void check(int l, int r) {
    string test;
    cin >> test;

    int mid = (l + r) / 2;
    if (test == "POSITIVE") {
        if (l == r) {
            cout << l << endl;
            return;
        }
        check(l, mid);
    } else {
        if (l == r) {
            cout << -1 << endl;
            return;
        }
        check(mid + 1, r);
    }
}

void test1() {
    for (int i = 1; i <= 10; ++i)
        cout << 1 << " " << 1 << '\n';
    cout.flush();

    string test;
    cin >> test;
    if (test == "POSITIVE")
        cout << 1;
    else
        cout << -1;
    cout.flush();
}
void xuly() {
    cin >> n;

    if (n == 1) {
        test1();
        return;
    }

    for (int i = 1; i <= n; i += 2)
        odd.pb(i);
    for (int i = 2; i <= n; i += 2)
        even.pb(i);

    int C = 0;
    for (int i = 1; i <= n; i += 2)
        id[i] = i;
    for (int i = n / 2 * 2; i >= 2; --i) {
        id[i] = even[C++];
    }

    // cout << even.size() << " ";
    // for (int v : even)
    //     cout << v << " ";
    // cout << '\n';

    build(1, 1024, 1);

    cout << odd.size() << " ";
    for (int v : odd)
        cout << v << " ";
    cout << '\n';

    for (int i = 1; i <= maxx; ++i) {
        cout << ans[i].size() << " ";
        for (int v : ans[i])
            cout << v << " ";
        cout << '\n';
    }
    for (int i = maxx + 1; i <= 10; ++i)
        cout << 0 << '\n';
    cout.flush();

    check(1, n);

    return;
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