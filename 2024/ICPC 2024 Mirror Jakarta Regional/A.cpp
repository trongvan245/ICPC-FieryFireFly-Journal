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

string s;
int get(int cnt_vowel, int cnt_consonant, int cnt_N, int cnt_G) {
    int cnt_NG = 0;

    function<int()> get_consonant = [&]() -> int {
        if (cnt_N && cnt_G) {
            ++cnt_NG;
            --cnt_N, --cnt_G;
            return 2;
        }
        if (cnt_consonant) {
            --cnt_consonant;
            return 1;
        }

        if (cnt_NG) {
            --cnt_NG;
            // ++cnt_consonant;
            return 0;
        }

        return -1;
    };

    function<int()> get_vowel = [&]() -> int {
        if (cnt_vowel) {
            --cnt_vowel;
            return 1;
        }
        return -1;
    };

    int res = 0;

    while (true) {
        int x = get_consonant();
        int y = get_vowel();
        int z = get_consonant();
        // cout << x << " " << y << " " << z << '\n';
        if (x == -1 || y == -1 || z == -1)
            break;
        res += x + y + z;
    }
    return res;
}

void xuly() {
    cin >> s;
    int cnt_vowel = 0, cnt_consonant = 0, cnt_N = 0, cnt_G = 0, cnt_NG = 0, cnt_Y = 0;
    for (char v : s) {
        if (v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U')
            ++cnt_vowel;
        else if (v == 'Y')
            ++cnt_Y;
        else if (v == 'N')
            ++cnt_N;
        else if (v == 'G')
            ++cnt_G;
        else
            ++cnt_consonant;
    }

    int t = min(cnt_N, cnt_G);
    cnt_consonant += max(cnt_N, cnt_G) - t;
    cnt_N = cnt_G = t;

    int ans = 0;
    for (int Y = 0; Y <= cnt_Y; ++Y) {
        int res = get(cnt_vowel + Y, cnt_consonant + cnt_Y - Y, cnt_N, cnt_G);
        ans = max(ans, res);
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