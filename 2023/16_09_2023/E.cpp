// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<ld, ld>
#define mp(x, y) make_pair(x, y)

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353
const ld alpha = sqrt(3) / 2;

using namespace std;

pii A, B, C;

ld area(pii a, pii b, pii c) {
    return (a.fi + b.fi) * (a.se - b.se) + (b.fi + c.fi) * (b.se - c.se) +
           (c.fi + a.fi) * (c.se - a.se);
}

pii find(pii A, pii B, pii C) {
    pii M = mp((A.fi + B.fi) / 2, (A.se + B.se) / 2);
    pii nAB = mp(-(A.se - B.se), A.fi - B.fi);
    pii N = mp(M.fi + nAB.fi * alpha, M.se + nAB.se * alpha);

    // cout << "test\n";
    // cout << M.fi << " " << M.se << '\n';
    // cout << N.fi << " " << N.se << "\n";

    if (area(A, B, N) * area(A, B, C) >= 0)
        N = mp(M.fi - nAB.fi * alpha, M.se - nAB.se * alpha);

    return N;
}

ld dis(pii A, pii B) {
    return sqrt((A.fi - B.fi) * (A.fi - B.fi) + (A.se - B.se) * (A.se - B.se));
}

bool check(pii A, pii B, pii C) {
    ld a = dis(B, C), b = dis(A, C), c = dis(A, B);

    ld alpha = acos(-1) * 2 / 3;
    // cout << alpha << '\n';
    return (acos((b * b + c * c - a * a) / (2 * b * c)) >= alpha);
}

void xuly() {
    cin >> A.fi >> A.se >> B.fi >> B.se >> C.fi >> C.se;

    pii N = find(A, B, C);
    pii Q = find(A, C, B);

    if (check(A, B, C)) {
        cout << fixed << setprecision(6) << A.fi << " " << A.se;
        return;
    }
    if (check(B, C, A)) {
        cout << fixed << setprecision(6) << B.fi << " " << B.se;
        return;
    }
    if (check(C, A, B)) {
        cout << fixed << setprecision(6) << C.fi << " " << C.se;
        return;
    }

    // cout << N.fi << " " << N.se << '\n';
    // cout << Q.fi << " " << Q.se << "\n\n";

    ld L = 0, R = 1;
    for (int i = 1; i <= 100; ++i) {
        ld mid = (L + R) / 2;

        pii NC = mp(C.fi - N.fi, C.se - N.se);
        pii K = mp(N.fi + NC.fi * mid, N.se + NC.se * mid);

        if (area(B, Q, K) * area(B, Q, N) >= 0)
            L = mid;
        else
            R = mid;
    }

    pii NC = mp(C.fi - N.fi, C.se - N.se);
    pii K = mp(N.fi + NC.fi * L, N.se + NC.se * L);
    cout << fixed << setprecision(6) << K.fi << " " << K.se << '\n';

    // if (a.fi > b.fi)
    //     swap(a, b);
    // if (a.fi > c.fi)
    //     swap(a, c);
    // if (b.fi > c.fi)
    //     swap(b, c);

    // pii M = make_pair((a.fi + b.fi) / 2.0, (a.se + b.se) / 2.0);
    // pii nAB = make_pair(-(a.se - b.se), a.fi - b.fi);
    // if (nAB.se > 0)
    //     nAB.fi *= -1, nAB.se *= -1;

    // ld alpha = sqrt(3) / 2;
    // pii N = make_pair(M.fi + nAB.fi * alpha, M.se + nAB.se * alpha);

    // // cout << M.fi << " " << M.se << "\n";
    // // cout << N.fi << " " << N.se << "\n\n";
    // ld L = 0, R = 1;

    // for (int i = 1; i <= 100; ++i) {
    //     // cout << L << " " << R << '\n';
    //     ld p1 = L + (R - L) / 3.0;
    //     ld p2 = R - (R - L) / 3.0;
    //     if (dist(p1, N, c) > dist(p2, N, c))
    //         L = p1;
    //     else
    //         R = p2;
    // }

    // // cout << L;

    // pii NC = {c.fi - N.fi, c.se - N.se};

    // pii G = {N.fi + NC.fi * L, N.se + NC.se * L};

    // // cout << "\n\n";

    // // cout << NC.fi << " " << NC.se << '\n';

    // cout << fixed << setprecision(6) << G.fi << " " << G.se << '\n';
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