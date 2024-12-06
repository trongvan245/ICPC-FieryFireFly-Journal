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
const ld pi = acos(-1);

using namespace std;

class Point {
  public:
    ld x, y;
};
int compareX(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

ld dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

ld bruteForce(Point P[], int n) {
    ld min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

ld min(ld x, ld y) { return (x < y) ? x : y; }

ld stripClosest(Point strip[], int size, ld d) {
    ld min = d;

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

ld closestUtil(Point P[], int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    ld dl = closestUtil(P, mid);
    ld dr = closestUtil(P + mid, n - mid);

    ld d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}

ld closest(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

struct three {
    int r, d, t;
} a[N];

bool cmp(three a, three b) { return a.t < b.t; }

set<int> s;
set<int, greater<int>> ss;
int findset(int r) {
    int ans = 1e9;
    if (s.lower_bound(r) != s.end()) {
        int v = *s.lower_bound(r);
        ans = min(ans, abs(v - r));
    }
    if (ss.lower_bound(r) != ss.end()) {
        int v = *ss.lower_bound(r);
        ans = min(ans, abs(v - r));
    }
    return ans;
}
void insert(int r) { s.insert(r), ss.insert(r); }

Point arr[N];
int sz = 0;
ld ans = FLT_MAX;
void sol(vector<three> &A) {
    if (A.size() == 0)
        return;
    sz = 0;
    for (auto [r, d, t] : A) {
        ld res = findset(r);
        // cout << r << " " << res << '\n';s
        ans = min(ans, res);
    }
    for (auto [r, d, t] : A) {
        ld angle = d / 1000.0 / (180.0 / pi);
        ld x = r * cos(angle), y = r * sin(angle);
        arr[sz++] = {x, y};
    }
    for (auto [r, d, t] : A) {
        insert(r);
    }

    ld res = closest(arr, sz);
    // cout << res << '\n';
    ans = min(ans, res);
    // cout << '\n';
}

void xuly() {
    cout << fixed << setprecision(12);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].r >> a[i].d >> a[i].t;
    sort(a + 1, a + 1 + n, cmp);

    int pre = -1;
    vector<three> A;
    for (int i = 1; i <= n; ++i) {
        if (a[i].t != pre) {
            sol(A);
            pre = a[i].t;
            A.clear();
        }
        A.pb(a[i]);
    }
    sol(A);

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