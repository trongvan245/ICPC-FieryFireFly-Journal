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

struct Point {
    ld X, Y;
};
struct Circle {
    Point C;
    ld R;
};
ld dist(const Point& a, const Point& b) {
    return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}
bool is_inside(const Circle& c, const Point& p) { return dist(c.C, p) <= c.R; }
Point get_circle_center(ld bx, ld by, ld cx, ld cy) {
    ld B = bx * bx + by * by;
    ld C = cx * cx + cy * cy;
    ld D = bx * cy - by * cx;
    return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
}
Circle circle_from(const Point& A, const Point& B, const Point& C) {
    Point I = get_circle_center(B.X - A.X, B.Y - A.Y, C.X - A.X, C.Y - A.Y);

    I.X += A.X;
    I.Y += A.Y;
    return {I, dist(I, A)};
}

Circle circle_from(const Point& A, const Point& B) {
    Point C = {(A.X + B.X) / 2.0, (A.Y + B.Y) / 2.0};

    return {C, dist(A, B) / 2.0};
}
bool is_valid_circle(const Circle& c, const vector<Point>& P) {
    for (const Point& p : P)
        if (!is_inside(c, p))
            return false;
    return true;
}
Circle min_circle_trivial(vector<Point>& P) {
    assert(P.size() <= 3);
    if (P.empty()) {
        return {{0, 0}, 0};
    } else if (P.size() == 1) {
        return {P[0], 0};
    } else if (P.size() == 2) {
        return circle_from(P[0], P[1]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {

            Circle c = circle_from(P[i], P[j]);
            if (is_valid_circle(c, P))
                return c;
        }
    }
    return circle_from(P[0], P[1], P[2]);
}
Circle welzl_helper(vector<Point>& P, vector<Point> R, int n) {
    if (n == 0 || R.size() == 3) {
        return min_circle_trivial(R);
    }

    int idx = rand() % n;
    Point p = P[idx];
    swap(P[idx], P[n - 1]);

    Circle d = welzl_helper(P, R, n - 1);
    if (is_inside(d, p)) {
        return d;
    }
    R.push_back(p);

    return welzl_helper(P, R, n - 1);
}

Circle welzl(vector<Point>& P) {
    // vector<Point> P_copy = P;
    return welzl_helper(P, {}, P.size());
}

int n;

void xuly() {
    srand(time(0));
    cin >> n;
    vector<Point> M;
    n = 500;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            Point e;
            e.X = rand(), e.Y = rand();
            // cin >> e.X >> e.Y;
            M.pb(e);
        }
        cout << M.size() << '\n';
        Circle S = welzl(M);
        cout << fixed << setprecision(7) << S.C.X << " " << S.C.Y << " " << S.R
             << '\n';
    }
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