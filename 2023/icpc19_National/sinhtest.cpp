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

int d[100][100][100];
void xuly() {

    srand(time(NULL));
    int a = 10, b = 10, c = 10, m = 10;
    cout << a << " " << b << " " << c << " " << m << '\n';

    while (m) {

        int x = rand() % a + 1;
        int y = rand() % b + 1;
        int z = rand() % c + 1;
        if (!d[x][y][z]) {
            --m;
            d[x][y][z] = 1;
            cout << x << " " << y << " " << z << '\n';
        }
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen(Nekan ".inp", "w", stdout);
    // if (fopen(Nekan ".inp", "r")) {
    //     freopen(Nekan ".inp", "r", stdin);
    //     freopen(Nekan ".out", "w", stdout);
    // }
    xuly();
}

// Surely nothing could go wrong.