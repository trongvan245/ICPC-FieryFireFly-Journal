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

void xuly() {
    int n, q; cin >> n >> q;
    set<pii> A;
    ll sum= 0, mul= 1;
    for (int i = 0 ; i < n; ++i) {
        A.insert({i, i});
    }

    int N= n;
    ll g_sum= 0, g_mul= 1;
    ll l_sum= 0, l_mul= 1;
    while(q--) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') {
            (l_sum+= x)%= n;
            (g_sum+= x)%= n;
        }
        else if (c == '*') {
            (l_sum*= x)%= n;
            (l_mul*= x)%= n;
            (g_sum*= x)%= n;
            (g_mul*= x)%= n;
            int c= __gcd(x, N);
            if (c == 1) continue;
            vector<int> maxx(N);
            for (int i = 1; i <= n; ++i) {
                int id= (i * g_mul + g_sum) % n;
                id%= (N / c);
                maxx[id]= i;
            }
            
            for (int i = 1; i <= n; ++i) {
                int id= (i * g_mul + g_sum) % n;
                id%= (N / c);
                if (i != maxx[id]) 
                maxx[id]= i;
            }
            N/= c;
            for (int i = 1; i <= n; ++i) {
                int id= (i * g_mul + g_sum) % n;
                id%= N;
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
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.