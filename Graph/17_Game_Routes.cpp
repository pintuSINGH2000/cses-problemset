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

void dfs(vector<int> adj[],int i,vector<ll> &dp,vector<bool> &vis){
    vis[i]=true;
    for(auto aa:adj[i]){
        if(!vis[aa])  dfs(adj,aa,dp,vis);
            dp[i]=(dp[i]+dp[aa])%mod;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    vector<ll> dp(n+1,0);
    vector<bool> vis(n+1,false);
    dp[n]=1;
    dfs(adj,1,dp,vis);
    cout<<dp[1]<<endl;
    
   
   return 0;
}
