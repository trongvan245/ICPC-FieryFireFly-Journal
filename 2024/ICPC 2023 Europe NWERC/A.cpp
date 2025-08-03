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
    ll n, s;
    cin >> n >> s;

    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(s == 1 || n==1) {
        cout << 1;
        return;
    }

    s -= 2;
    ll ans  = 2;
    ll total = 0;

    ll r1 = 0, r2 = 0;

    for(int i=0; i<n-2; i++) {
        ll slot = (a[i] / 3 + (a[i]%3!=0));
        total += slot;
        
        if(a[i]%3==1) r1++;
        else if(a[i]%3==2) r2++;
    
        ll sub = 0;
        if(r1 > r2) sub = r2 + (r1 - r2)/2;
        else sub  = r1;

        if(total - sub <= s) ans = 2 + i + 1;
        else break;
    }

    cout << ans << endl;
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