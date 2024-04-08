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

bool bfs(vector<int> adj[],int node,int n,vector<int> &team){
     queue<int> q;
     q.push(node);
     team[node]=0;
     while(!q.empty()){
         int par=q.front();
         q.pop();
         for(auto child:adj[par]){
             if(team[child]==-1){
                 team[child]=!team[par];
                 q.push(child);
             }else if(team[child]==team[par]){
                 return false;
             }
         }
     }
     return true;
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
    vector<int> team(n+1,-1);
    for(int i=1;i<=n;i++){
        if(team[i]==-1){
            auto ans=bfs(arr,i,n,team);
            if(!ans){
               cout<<"IMPOSSIBLE"<<endl;
               return 0;
            }
        }    
    }
   
    for(int i=1;i<=n;i++){
        cout<<team[i]+1<<" ";
    }
   
   return 0;
}