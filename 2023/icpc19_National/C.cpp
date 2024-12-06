// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test2"
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

struct six {
    int u, v, w, x, y, z;
};

int a, b, c, m;
int x[1003], y[1003], z[1003];
six A[1003];

bool inside(six e, int X, int Y, int Z) {
    if (e.u <= X && X <= e.x && e.v <= Y && Y <= e.y && e.w <= Z && Z <= e.z)
        return true;
    return false;
}

bool in_interval(int u, int v, int x, int y) {
    if (u <= x && x <= v)
        return true;
    if (u <= y && y <= v)
        return true;
    if (x <= u && u <= y)
        return true;
    if (x <= v && v <= y)
        return true;
    return false;
}

bool check(six a, six b) {
    int A[3];
    for (int mask = 0; mask <= 7; ++mask) {
        A[0] = (BIT(mask, 0) ? b.u : b.x);
        A[1] = (BIT(mask, 1) ? b.v : b.y);
        A[2] = (BIT(mask, 2) ? b.w : b.z);

        if (inside(a, A[0], A[1], A[2]))
            return true;
    }
    return false;
}
void xuly() {
    bool ans = true;
    cin >> b >> c >> m;
    for (int i = 1; i <= m; ++i)
        cin >> x[i] >> y[i] >> z[i];

    ll area = 0;
    area += 1ll * a * b * c;
    for (int i = 1; i <= m; ++i) {
        cin >> A[i].u >> A[i].v >> A[i].w >> A[i].x >> A[i].y >> A[i].z;
        if (A[i].u > A[i].x)
            ans = false;
        // swap(A[i].x, A[i].u);
        if (A[i].v > A[i].y)
            ans = false;
        // swap(A[i].v, A[i].y);
        if (A[i].w > A[i].z)
            ans = false;
        // swap(A[i].w, A[i].z);

        if (A[i].x > a)
            ans = false;
        if (A[i].y > b)
            ans = false;
        if (A[i].z > c)
            ans = false;

        if (A[i].u < 1)
            ans = false;
        if (A[i].v < 1)
            ans = false;
        if (A[i].w < 1)
            ans = false;
        six e = A[i];
        if (!inside(e, x[i], y[i], z[i]))
            ans = false;

        int Count = 0;
        for (int j = 1; j <= m; ++j)
            if (inside(e, x[j], y[j], z[j]))
                ++Count;

        if (Count != 1) {

            ans = false;
            cout << i << '\n';
        }

        area -= 1ll * (e.x - e.u + 1) * (e.y - e.v + 1) * (e.z - e.w + 1);
        if (area < 0)
            ans = false;
    }
    // cout << ans << '\n';
    for (int i = 1; i <= m; ++i)
        for (int j = i + 1; j <= m; ++j) {
            six e = A[i], ee = A[j];

            bool c = true;
            if (!in_interval(e.u, e.x, ee.u, ee.x))
                c = false;
            if (!in_interval(e.v, e.y, ee.v, ee.y))
                c = false;
            if (!in_interval(e.w, e.z, ee.w, ee.z))
                c = false;

            if (c)
                ans = false;
        }

    if (area != 0)
        ans = false;

    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    while (1) {
        cin >> a;
        if (a == -1)
            return 0;
        xuly();
    }
}

// Surely nothing could go wrong.