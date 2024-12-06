// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;



// bool check(int x, ld y, int xx, ld yy) {
//     if (x > xx) return false;
//     if (x == xx && y > yy) return false;
//     return true;
// }




// void xuly() {
//     string st, se;
//     int d;
//     cin>>st>>se>>d;

//     ld h1= stoi(st.substr(0, 2));
//     ld m1= stoi(st.substr(3, 2));
//     ld h2= stoi(se.substr(0, 2));
//     ld m2= stoi(se.substr(3, 2));

//     ld x= 0, y= 0;

//     int ans= 0;

//     // cout<<h1<<" "<<m1<<" "<<h2<<" "<<m2<<'\n';
    
    
//     for(int i=0;i<=23;++i) {
//         int x= i % 12;
//         if (d == 0) {
//             ld y= x*60/11.0;
//             if (y >= 60) continue;
//             if (check(h1, m1, x, y) && check(x, y, h2, m2)) ++ans; 
//         }

//         if (d == 90) {
//             ld y1= (x + 3)*60/11.0;
//             ld y2= (x + 9)*60/11.0;
//             cout<<x<<" "<<y1<<" "<<y2<<'\n';

//             if (y1 < 60) 
//                 if (check(h1, m1, x, y1) && check(x, y1, h2, m2)) ++ans;
             
//             if (y2 < 60)
//                 if (check(h1, m1, x, y2) && check(x, y2, h2, m2)) ++ans;
//         }

//         if (d == 180) {
//             ld y= (x + 6)*60/11.0;
//             if (y >= 60) continue;
//             if (check(h1, m1, x, y) && check(x, y, h2, m2)) ++ans; 
//         }

//     }
//     cout<<ans<<'\n';
// }

void xuly(){
    string st, se;
    int d;
    cin>>st>>se>>d;

    ld h1= stoi(st.substr(0, 2));
    ld m1= stoi(st.substr(3, 2));
    ld h2= stoi(se.substr(0, 2));
    ld m2= stoi(se.substr(3, 2));
    int ih1=h1;
    int ih2 = h2;
    int ans = 0;
    cout << fixed<<setprecision(7);
    for(int i =ih1;i<= ih2; i++){
        int tmp = i%12;

        if(d==0){
            ld mins = 60.0/11*tmp;
            if(mins - 60 < -1e-12 &&(i != ih1 || m1 <= mins)&&(i != ih2 || m2 >= mins)) ans++;
        }
        if(d == 90){
            ld mins1=61,mins2 = 61,mins3=61,mins4=61;
            if(tmp < 3){
                mins1 = 60.0/11*(tmp+3);
                mins3 = 60.0/11*(tmp+9);
            }
            else if(tmp >= 9){
                mins2 = 60.0/11*(tmp-3);
                 mins4 = 60.0/11*(tmp-9);
            }
            else {
                mins1 = 60.0/11*(tmp+3);
                mins2=60.0/11*(tmp-3);
            }
            if(mins1 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins1)&&(i != ih2 || m2 >= mins1)) ans++;
            }
            if(mins2 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins2)&&(i != ih2 || m2 >= mins2)) ans++;
            }
            if(mins3 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins3)&&(i != ih2 || m2 >= mins3)) ans++;
            }
            if(mins4 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins4)&&(i != ih2 || m2 >= mins4)) ans++;
            }
        }
        if(d==180){
            ld mins1=61,mins2 = 61;
            if(tmp < 6){
                mins1 = 60.0/11*(tmp+6);
            }
            else if(tmp >= 6){
                mins2 = 60.0/11*(tmp-6);
            }
            else {
                mins1 = 60.0/11*(tmp+6);
                mins2=60.0/11*(tmp-6);
            }
            if(mins1 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins1)&&(i != ih2 || m2 >= mins1)) ans++;
            }
            if(mins2 - 60 < -1e-12){
                if((i != ih1 || m1 <= mins2)&&(i != ih2 || m2 >= mins2)) ans++;
        }
    }}
    cout << ans<<'\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t; cin>>t;
    while(t--)
    xuly();
}

// Surely nothing could go wrong.