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
    int n; cin >> n;
    vector<int> a;
    vector<int> init(1e6 + 2, 0);
    vector<int> curr(1e6 + 2, 0);

    for(int i = 0;i < n;++i) {
        int x; cin>>x;
        init[x]++;
        ++curr[x];
    }

    sort(a.begin(), a.end());

    while(true) {
        //2 2 1 1
        while(curr[2] >= 2 && curr[1] >= 2) {
            curr[2]-= 2;
            curr[1]-= 2;
            curr[3]+= 2;
        }
        
        if (curr[1] >= 2) {
            curr[1]-= 2;
            curr[2]++;
            continue;
        }
        
        //curr[1]= 1
        if (curr[1] == 1) {
            for(int i=2;i<=1e6;++i) if (curr[i]) {
                --curr[i], ++curr[i+1];
                --curr[1];
                break;
            }
        }
        
        break;
    }

    

    vector<string> ans;

    for(int i = 1e6 + 1; i >= 1; --i) {
        while(curr[i]) {
            vector<int> A;
            int s= i;
            for (int j = i; j >= 1; --j) {
                while (init[j] && s >= j) {
                    A.pb(j);
                    --init[j];
                    s-= j;
                }
                if (s == 0) break;
            }

            assert(A.size() != 0);
            string res = to_string(A[0]);

            for(int k=1;k<A.size();++k) res+= "+"+to_string(A[k]);
            res= '(' + res + ')';
            ans.pb(res);

            --curr[i];
        }
    }

    cout<<ans[0];
    for(int i = 1; i < ans.size(); ++i) cout <<"*"<<ans[i];
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