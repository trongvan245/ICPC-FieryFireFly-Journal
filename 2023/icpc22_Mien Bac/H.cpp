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

multiset<int> s1;
multiset<int, greater<int>> s2;

int q, Count;

void add(int x) {
    if (Count % 2 == 0)
        s1.insert(x);
    else
        s2.insert(x);
    ++Count;

    if (s1.size() && s2.size()) {
        int t1 = *s1.begin();
        int t2 = *s2.begin();
        if (t1 < t2) {
            // swap(s1.begin(), s2.begin());
            s1.erase(s1.begin());
            s1.insert(t2);

            s2.erase(s2.begin());
            s2.insert(t1);
        }
    }
}
void del(int x) {
    int t1 = *s1.begin();

    if (x >= t1) {
        s1.erase(s1.find(x));
        if (Count % 2 == 0) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    } else {
        s2.erase(s2.find(x));
        if (Count % 2 == 1) {
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }
    }
    --Count;
}

void xuly() {
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "IN") {
            int x;
            cin >> x;
            add(x);
        } else if (s == "OUT") {
            int x;
            cin >> x;
            del(x);
        } else {
            if (Count % 2)
                cout << *s1.begin() << '\n';
            else {
                if (Count == 0) {
                    cout << 0 << '\n';
                } else {
                    int t1 = *s1.begin(), t2 = *s2.begin();
                    // cout << t1 << " " << t2 << '\n';
                    cout << (t1 + t2) / 2.0 << '\n';
                }
            }
        }
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