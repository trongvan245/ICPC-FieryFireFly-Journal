#include <bits/stdc++.h>
#define Nekan "test"
using namespace std;
#define ll long long

const int MAXN = 123456;

struct Node {
    int sum, lazy, tl, tr, l, r;
    Node() : sum(0), lazy(0), l(-1), r(-1) {}
};

struct SegTree {
    vector<Node> segtree;
    int cnt = 2;

    SegTree() { segtree.resize(64 * MAXN); }
    void init() {
        segtree[1].sum = 0;
        segtree[1].lazy = 0;
        segtree[1].tl = 1;
        segtree[1].tr = 1e9 + 5;
    }

    void push_lazy(int node) {
        if (segtree[node].lazy) {
            segtree[node].sum = segtree[node].tr - segtree[node].tl + 1;
            int mid = (segtree[node].tl + segtree[node].tr) / 2;
            if (segtree[node].l == -1) {
                segtree[node].l = cnt++;
                segtree[segtree[node].l].tl = segtree[node].tl;
                segtree[segtree[node].l].tr = mid;
            }
            if (segtree[node].r == -1) {
                segtree[node].r = cnt++;
                segtree[segtree[node].r].tl = mid + 1;
                segtree[segtree[node].r].tr = segtree[node].tr;
            }
            segtree[segtree[node].l].lazy = segtree[segtree[node].r].lazy = 1;
            segtree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r) {
        push_lazy(node);
        if (l == segtree[node].tl && r == segtree[node].tr) {
            segtree[node].lazy = 1;
            push_lazy(node);
        } else {
            int mid = (segtree[node].tl + segtree[node].tr) / 2;
            if (segtree[node].l == -1) {
                segtree[node].l = cnt++;
                segtree[segtree[node].l].tl = segtree[node].tl;
                segtree[segtree[node].l].tr = mid;
            }
            if (segtree[node].r == -1) {
                segtree[node].r = cnt++;
                segtree[segtree[node].r].tl = mid + 1;
                segtree[segtree[node].r].tr = segtree[node].tr;
            }

            if (l > mid)
                update(segtree[node].r, l, r);
            else if (r <= mid)
                update(segtree[node].l, l, r);
            else {
                update(segtree[node].l, l, mid);
                update(segtree[node].r, mid + 1, r);
            }

            push_lazy(segtree[node].l);
            push_lazy(segtree[node].r);
            segtree[node].sum =
                segtree[segtree[node].l].sum + segtree[segtree[node].r].sum;
        }
    }

    int query(int node, int l, int r) {
        push_lazy(node);
        if (l == segtree[node].tl && r == segtree[node].tr)
            return segtree[node].sum;
        else {
            int mid = (segtree[node].tl + segtree[node].tr) / 2;
            if (segtree[node].l == -1) {
                segtree[node].l = cnt++;
                segtree[segtree[node].l].tl = segtree[node].tl;
                segtree[segtree[node].l].tr = mid;
            }
            if (segtree[node].r == -1) {
                segtree[node].r = cnt++;
                segtree[segtree[node].r].tl = mid + 1;
                segtree[segtree[node].r].tr = segtree[node].tr;
            }

            if (l > mid)
                return query(segtree[node].r, l, r);
            else if (r <= mid)
                return query(segtree[node].l, l, r);
            else
                return query(segtree[node].l, l, mid) +
                       query(segtree[node].r, mid + 1, r);
        }
    }
};

int longestUnionRange(vector<pair<int, int>> &segments) {
    if (segments.empty())
        return 0;

    // Sort the segments by their starting position
    sort(segments.begin(), segments.end());

    int longest = 0;
    int currentStart = segments[0].first;
    int currentEnd = segments[0].second;

    // Iterate over the segments to merge
    for (int i = 1; i < segments.size(); ++i) {
        if (segments[i].first <= currentEnd + 1) {
            // Merge intervals if they overlap or are contiguous
            currentEnd = max(currentEnd, segments[i].second);
        } else {
            // Calculate the length of the current merged segment
            longest = max(longest, currentEnd - currentStart + 1);
            // Move to the next segment
            currentStart = segments[i].first;
            currentEnd = segments[i].second;
        }
    }

    // Check the last merged segment
    longest = max(longest, currentEnd - currentStart + 1);

    return longest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int t;
    int n, m, L;
    cin >> t >> n >> m >> L;
    vector<int> ops(m * 2);

    for (int &i : ops) {
        cin >> i;
    }

    int cntInvalidRed = 0, ctnInvalidBlue = 0;

    SegTree red, blue;

    red.init();
    blue.init();

    vector<pair<int, int>> segRed, segBlue;

    for (int i = 0; i < ops.size(); ++i) {
        int l = ops[i] + 2, r = ops[i] + L - 1 + 2;
        if (r - 2 >= n) {
            if (i & 1) {
                ctnInvalidBlue++;
            } else {
                cntInvalidRed++;
            }
            continue;
        }
        // cout << l - 2 << ' ' << r - 2 << ' ' << (i & 1) << '\n';
        if (i & 1) {
            if (red.query(1, l - 1, r + 1)) {
                // cout << "red " << i << '\n';
                ctnInvalidBlue++;
                continue;
            }
            blue.update(1, l, r);
            segBlue.emplace_back(l, r);
        } else {
            if (blue.query(1, l - 1, r + 1)) {
                // cout << "red " << i << '\n';
                cntInvalidRed++;
                continue;
            }
            red.update(1, l, r);
            segRed.emplace_back(l, r);
        }
    }

    if (t == 1) {
        return cout << cntInvalidRed << ' ' << ctnInvalidBlue, 0;
    }
    cout << longestUnionRange(segRed) << ' ' << longestUnionRange(segBlue);
}