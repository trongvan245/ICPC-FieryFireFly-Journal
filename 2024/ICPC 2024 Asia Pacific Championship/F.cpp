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

const int N = 1e6 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;


int d[N];
int group[N];
int a[N], b[N];
void xuly() {
    int n; cin >> n;

    
    int p= 0, q= 1000;
    
    for (int i=0;i<n;++i) {
        cin>>a[i];
        b[i]= a[i];
        p= max(p, a[i]), q= min(q, a[i]);
    }


    for (int k = 2; k < n; ++k) {
        if (d[k] || n % k) continue;
        for (int i=0; i<k;++i) group[i]= 0;
        for (int i=0;i<n;++i) a[i]= b[i];
        multiset<int> s;
        multiset<int, greater<int>> ss;

        auto add= [&](int x) {
            // cout << " add " << x << '\n';
            s.insert(x);
            ss.insert(x);
        };
        auto remove= [&](int x) {
            // cout << " remove " << x << '\n';
            s.erase(s.find(x));
            ss.erase(ss.find(x));
        };

        for (int i= 0; i < n; ++i) 
            group[i%k]+= a[i];
        
        for (int i= 0; i < k; ++i) add(group[i]);


        auto get_ans= [&]() {
            int P= *ss.begin(), Q= *s.begin();
            // cout << P <<" " << Q << '\n';
            
            if (1ll * p * Q < 1ll * P * q) return;
            p= P, q= Q;
        };
        get_ans();
        for (int i = 0; i + 1 < n; ++i) {
            int curr= i%k, nxt= (i+1)%k;
            remove(group[curr]);
            remove(group[nxt]);
            group[curr]+= a[i + 1] - a[i];
            group[nxt]+= a[i] - a[i + 1];
            swap(a[i + 1], a[i]);
            add(group[curr]);
            add(group[nxt]); 

            get_ans();
        }
    }

    int c= __gcd(p, q);
    cout << p/c <<" " << q/c << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int LIM= 1e6;
    for (int i=2;i<=LIM;++i)
    for (int j=i*2;j<=LIM;j+=i) d[j]= 1;
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.