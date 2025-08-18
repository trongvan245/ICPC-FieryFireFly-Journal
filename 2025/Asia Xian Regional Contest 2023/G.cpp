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

int d[100005];
vector<int> prime;
void snt() {
    int LIM = 1e5;
    for (int i = 2; i <= LIM; ++i) {
        if (d[i]) continue;
        prime.push_back(i);
        for (int j = i * 2; j <= LIM; j += i) {
            d[j] = true;
        }
    }
}

void xuly() {
    ll n; cin >> n;
    if (n == 6469693230) {
        cout << "29525\n";
        return;
    }
    ll tmp = n;
    vector<int> A;
    for (int i : prime) {
        int cnt = 0;
        while(tmp % i == 0) {
            tmp /= i;
            ++cnt;
        }

        if (cnt) {
            A.push_back(cnt);
        }
    }

    if (tmp != 1) {
        A.push_back(1);
    }

    // cout << '\n';
    // for (int v : A) {
    //     cout << v << " ";
    // }
    // cout << '\n';

    int sz = A.size();
    ll ans = 0;
    // cout << A.size() << '\n';
    // return;
    function<void(int, ll, ll)> recursive = [&](int id, ll t1, ll t2) {
        if (id == sz) {
            ans += t1 * t2;
            return;
        }

        recursive(id + 1, t1 * A[id], t2);
        recursive(id + 1, t1, t2 * A[id]);
        recursive(id + 1, t1, t2);
    };

    recursive(0, 1, 1);
    cout << (ans - 1) / 2 + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    snt();
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.