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
int pre[100001];

void bfs(vector<int> arr[],int node,int dest){
     vis[node]=true;
     queue<int> q;
     vector<int> ans;
     ans.pb(node);
     q.push(node);
     int count=0;
     while(!q.empty()){
         int size=q.size();
         for(int i=0;i<size;i++){
             auto par=q.front();
             q.pop();
             for(auto child:arr[par]){
                 if(!vis[child]){
                     pre[child]=par;
                      vis[child]=true;
                     if(child==dest) return ;
                     q.push(child);
                 }
             }
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
    bfs(arr,1,n);
    if(pre[n]==0) {
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> ans;
        int a=n;
        ans.pb(n);
        while(a!=1){
            a=pre[a];
            ans.pb(a);
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
   return 0;
}