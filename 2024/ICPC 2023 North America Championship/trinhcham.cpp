#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "F";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên
// số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL % (h - l + 1);
}

int d[1005][1005];
int main() {
    srand(time(NULL));
    // for (int i = 0; i <= 1000; ++i)
    //     d[0][i] = d[i][0] = 1;
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp("test.inp");
        vector<pair<int, int>> a(4);
        for(int i=0;i<4;++i) {
            a[i].first= rand()%5 + 1;
            a[i].second= rand()%5 + 1;
        }
        
        for (auto [u, v] : a) inp<<u<<" "<<v<<'\n';
        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        
        if (system("fc test.out test.ans") != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}