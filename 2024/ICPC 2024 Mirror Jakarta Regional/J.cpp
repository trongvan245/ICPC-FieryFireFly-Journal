// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "J"
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

int n, m;
bool isEqual[31];

int Count = 1, cnt[N * 30];
int trie[N * 30][2];

void add(int val) {
    int root = 1;
    ++cnt[root];
    for (int bit = 29; bit >= 0; --bit) {
        bool c = BIT(val, bit);
        if (!trie[root][c])
            trie[root][c] = ++Count;
        root = trie[root][c];
        ++cnt[root];
    }
}

void dfs(int root, int bit) {
    if (cnt[root] > 1)
        isEqual[bit] = true;

    int L = trie[root][0], R = trie[root][1];

    if (L)
        dfs(L, bit - 1);
    if (R)
        dfs(R, bit - 1);
}

void xuly() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        
        add(x);
    }

    dfs(1, 30);

    map<int, int> mm;

    ll ans = 0;
    for (int i = 0; i < 30; ++i)
        cout << isEqual[i] << " ";
    cout << "\n\n";

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < 30; ++j)
            if (!isEqual[j]) {
                bool bit = BIT(x, j);
                x -= bit << j;
            }

        // cout << i << " " << x << " " << mm[x] << '\n';
        ans += mm[x];
        ++mm[x];
    }
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