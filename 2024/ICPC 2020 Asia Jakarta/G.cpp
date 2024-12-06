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
const int LIM = 1e5;
const long long mod = 998244353;

using namespace std;

// Function to calculate (base^exp) % mod using fast exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate Euler's Totient function φ(n)
int euler_totient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Function to get all divisors of a number
std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

// Function to find the smallest K such that 2^K ≡ 1 (mod X)
int find_smallest_k(int X) {
    int phi_x = euler_totient(X);
    std::vector<int> divisors = get_divisors(phi_x);

    for (int K : divisors) {
        if (mod_exp(2, K, X) == 1) {
            return K;
        }
    }
    return -1; // Should never reach here if X > 1 and coprime to 2
}

int n;
int vis[N], p[N], d[N], maxx[N];
int dfs(int u) {
    vis[u] = 1;
    if (!vis[p[u]])
        return dfs(p[u]) + 1;
    else
        return 1;
}

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    int init = 0;
    ll ans = 1;
    bool flag = true;

    for (int i = 1; i <= n; ++i) {
        int Count = 0;
        if (vis[i])
            continue;
        int sz = dfs(i);

        while (sz % 2 == 0) {
            sz /= 2;
            ++Count;
        }
        init = max(Count, init);

        if (sz == 1)
            continue;

        int turn = 1;
        ll val = 2;
        while (val != 1) {
            val = val * 2 % sz;
            ++turn;
        }

        // cout << turn << '\n';

        flag = false;
        while (turn != 1) {
            int t = d[turn], Count = 0;
            while (turn % t == 0)
                turn /= t, ++Count;

            maxx[t] = max(maxx[t], Count);
        }
    }

    for (int i = 1; i <= LIM; ++i) {
        while (maxx[i]) {
            --maxx[i];
            ans = ans * i % mod;
            // cout << i << '\n';
        }
    }
    cout << (ans + init) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    for (int i = 2; i <= LIM; ++i) {
        if (d[i])
            continue;
        for (int j = i; j <= LIM; j += i)
            d[j] = i;
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.