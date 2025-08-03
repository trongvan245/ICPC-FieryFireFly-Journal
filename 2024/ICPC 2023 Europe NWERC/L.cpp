#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
bool vis[105][105];
int n, k;

bool ask(int x, int y) {
    cout << x << ' ' << y << endl;
    string s;
    cin >> s;
    if (s == "sunk") {
        cnt++;
    }    
    if (cnt == k) {
        exit(0);
    }
    return (s == "hit" || s == "sunk");
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    if (vis[x][y]) {
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (!(u >= 1 && u <= n && v >= 1 && v <= n)) {
            continue;
        }
        if (vis[u][v]) {
            continue;
        }
        if (ask(u, v)) {
            dfs(u, v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        int start = (i - 1) % 5 + 1;
        for (int j = start; j <= n; j += 5) {
            if (!vis[i][j] && ask(i, j)) {
                dfs(i, j);
            }
        }
    }
}