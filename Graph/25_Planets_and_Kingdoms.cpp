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
stack<int> st;
 
void dfs(int i,vector<int> arr[]){
    vis[i]=true;
    for(auto aa:arr[i]){
        if(!vis[aa]) dfs(aa,arr);
    }
    st.push(i);
}
void dfs2(int i,vector<int> arr[],vector<int> &temp){
    vis[i]=true;
    temp.pb(i);
    for(auto aa:arr[i]){
        if(!vis[aa]) dfs2(aa,arr,temp);
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
    for(int i=1;i<=n;i++){
        if(!vis[i]){
             dfs(i,graph);
        }
    }
   
    memset(vis,false,sizeof(vis));
    vector<int> ans(n+1);
    int count=1;
    while(!st.empty()){
        auto aa=st.top();
        st.pop();
        if(!vis[aa]){
            vector<int> temp;
            dfs2(aa,revGraph,temp);
            for(int i=0;i<temp.size();i++){
                ans[temp[i]]=count;
            }
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
   return 0;
 
}