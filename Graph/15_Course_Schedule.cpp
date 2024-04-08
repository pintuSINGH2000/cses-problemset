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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> in(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        in[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(in[i]==0) {
            q.push(i);
            ans.push_back(i);
        }
    }
    
    while(!q.empty()){
        auto a=q.front();
        q.pop();
        for(auto aa:adj[a]){
            if(in[aa]>0){
                in[aa]--;
                if(in[aa]==0){
                    q.push(aa);
                    ans.pb(aa);
                }
            }
        }
    }
    if(ans.size()<n){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        print(ans);
    }
    
   
   return 0;
}
