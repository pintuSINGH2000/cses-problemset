#include<bits/stdc++.h>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<"\n";
#define println(x) for(auto &a:x){cout<<a<<'\n';}
#define fr first
#define sc second 
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
#define mkp make_pair
using namespace std;
const ll mod=1000000007;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U','R','D','L'};
const int mxn=100005;
const int d=30;
bool vis[mxn];
int step;
queue<int> q;

 
void dfs(int i,vector<int> arr[]){
    vis[i]=true;
    for(auto aa:arr[i]){
        if(!vis[aa]) dfs(aa,arr);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> graph[n+1],revGraph[n+1];
    for(int i=0;i<m;i++){
       int a,b;
       cin>>a>>b;
       graph[a].pb(b);
       revGraph[b].pb(a);
    }
    dfs(1,graph);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(1,revGraph);
      for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
   return 0;

}