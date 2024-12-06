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

map<vector<int>, int> m;
int id[500];
void xuly() {
    //
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(52, -1);
    int top = 0;
    for (char x = 'a'; x <= 'z'; ++x)
        id[x] = top++;
    for (char x = 'A'; x <= 'Z'; ++x)
        id[x] = top++;

    for (char x : s)
        cnt[id[x]] = 0;


    string s= "aabb";
    for(int i=0;i<s.size();++i) {
        if (s[i] == 'a') ++cnt['a'];
        else ++cnt['b'];
        
        int chuanhoa= cnt['a'] - cnt['b'];
        ans+= dem[chuanhoa];

        dem[chuanhoa]++;
    }  
    O(n/3 * n)
           0 1 2 3 4 
    cnt[a] 0 1 2 2 2 
    cnt[b] 0 0 0 1 2
    
    cnt[a] - cnt[b]
    bababbabababa


    ll ans = 0;
    ++m[cnt];
    for (char x : s) {
        int minn = 1e9;

        ++cnt[id[x]];
        vector<int> ch(52, 0);
        for (int i = 0; i < 52; ++i)
            if (cnt[i] != -1)
                minn = min(cnt[i], minn);

        if (minn == 0) {
            ++m[cnt];
            continue;
        }
        for (int i = 0; i < 52; ++i) {
            ch[i] = cnt[i];
            if (cnt[i] == -1)
                continue;
            ch[i] -= minn;
        }
        ans += m[ch];
        ans %= mod;
        ++m[ch];
    }
    cout << ans << '\n';
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