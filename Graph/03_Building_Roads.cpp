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
bool vis[100001];

void dfs(vector<int> arr[],int node,int par){
     vis[node]=true;
     for(auto aa:arr[node]){
         if(par!=aa&&!vis[aa]){
             dfs(arr,aa,node);
         }
     }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    int count=0;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            count++;
            ans.pb({1,i});
            dfs(arr,i,-1);
        }
    }
    cout<<count-1<<endl;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i].fr<<" "<<ans[i].sc<<endl;
    }
    cout<<endl;
   return 0;
}