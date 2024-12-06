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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int sum = 1, Count = 1, card;
int n, a[N];

void xuly() {
    sum = Count = 1;
    card = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            ++sum;
            ++Count;
        }
        if (a[i] == -1) {
            if (Count == 1) {
                if (card) {
                    --card;
                    sum += 1;
                    Count += 2;
                } else {
                    cout << -1 << '\n';
                    return;
                }
            }
            --Count;
        }
        if (a[i] == 0) {
            if (Count == 1) {
                ++sum;
                ++Count;
            } else {
                --Count;
                ++card;
            }
        }
        // cout << sum << " " << Count << '\n';
    }
    int t = __gcd(sum, Count);
    cout << sum / t << " " << Count / t << '\n';

    // cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.