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
 
bool dfs(vector<int> adj[],int node,vector<int> &visited,vector<int> &ans, vector<int> &temp){
     visited[node]=true;
     temp[node]=true;
     for(auto aa:adj[node]){
         ans.pb(aa);
         if(!visited[aa]){
             if(dfs(adj,aa,visited,ans,temp)){
                 return true;
             }
         }else if(temp[aa]) return true;
         ans.pop_back();
     }
     temp[node]=false;
     return false;
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
    }
    vector<int> vis(n+1);
     vector<int> temp(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> ans;
            ans.pb(i);
            if(dfs(arr,i,vis,ans,temp)){
                int temp=ans[ans.size()-1];
                vector<int> res;
                res.pb(ans[ans.size()-1]);
                for(int i=ans.size()-2;i>=0;i--){
                    res.pb(ans[i]);
                    if(temp==ans[i]) break;
                }
                cout<<res.size()<<endl;
                reverse(all(res));
                print(res);
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
   
   return 0;
}
