#include<bits/stdc++.h>

using namespace std;
#define N 500010
#define ll long long
#define ii pair<ll,int>
#define fs first
#define sc second
#define pb push_back
#define int ll
#define iii pair<int,pair<int32_t,int32_t>>

vector<int> g[N];

int ans=0,cnt,Low[N], Visited[N], Parent[N], LastComponent[N];

stack<int> st;

int ComponentCount;

bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }
void visit(int u){

   Low[u]=Visited[u]=++cnt;
  //  cout<<u<<endl;
   for (auto v:g[u])
    {

      if (Visited[v]) minimize(Low[u], Visited[v]);

      else {

         st.push(u);

         Parent[v]=u; visit(v); minimize(Low[u], Low[v]);

         if (Low[v]>=Visited[u]) {

            int Current=0;

            ComponentCount++;

            do {

               v=st.top(); st.pop();

               if (maximize(LastComponent[v], ComponentCount))

               Current++;

            } while (u!=v);
            ans-=(Current*(Current-1)/2);
         //   cout<<Current<<endl;
         }

      }

   }

   st.push(u);
}

int n,m;
char a[510][510];
vector<int>h={0,0,-1,1},c={-1,1,0,0};

int get_id(int u,int v)
{
    return  (u-1)*m+v;
}


int32_t main()
{
    #ifdef SKY
    freopen("A.inp","r",stdin);
    freopen("A.out","w",stdout);
    #endif // SKY
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    int dem=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='.')
                dem++;
        }
    ans=(dem*(dem-1)/2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.')
            {
                for(int t=0;t<4;t++)
                    if(a[i+h[t]][j+c[t]]=='.')
                    {
                        g[get_id(i,j)].pb(get_id(i+h[t],j+c[t]));
                    }
            }
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i][j]=='.'&&Low[get_id(i,j)]==0)
            visit(get_id(i,j));
    cout<<ans*2;
    return 0;
}