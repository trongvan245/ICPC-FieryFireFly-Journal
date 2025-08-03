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
    vector<pii> A(4);
    int area= 0;
    for (int i = 0; i < 4 ; ++i) {
        cin >> A[i].fi >> A[i].se;
        area+= A[i].fi * A[i].se;
    }
    int edge= ceil(sqrt(area));
    if (edge * edge != area) {
        cout << 0;
        return;
    }
    vector<pii> B= A;

    // cout << edge << '\n';
    for (int mask = 0; mask < (1 << 4); ++mask) {
        A= B;
        for (int i=0;i<4;++i) if (BIT(mask, i)) swap(A[i].fi, A[i].se);


        auto check= [&](vector<pii> A) {
            function<bool(int, int, int)> vet= [&](int id, int h, int w) {
                if (id == 4) 
                    return (h == 0 || w == 0);
                
                

                int pre= 0, curr_h= h;
                while(id < 4 && curr_h > 0) {
                    if (pre == 0 && curr_h >= A[id].fi) {
                        curr_h-= A[id].fi;
                        pre= A[id].se;
                    }
                    else if (A[id].se == pre && curr_h >= A[id].fi) {
                        curr_h-= A[id].fi;
                    }
                    else return false;
                    ++id;
                }

                if (curr_h != 0) return false;
                if (pre > w) return false;
                w-= pre;
                if (vet(id, h, w)) return true;
                if (vet(id, w, h)) return true;
                return false;
            };

            
            return vet(0, edge, edge);
        };


        do {
            // for (auto [u, v] : A) cout <<u<<" "<<v<<'\n';
            // cout<<'\n';
            if (check(A)) {
                cout << 1;
                return;
            }
        } while(next_permutation(A.begin(), A.end()));
    }

    cout << 0 << '\n';
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