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
ll nRoute[mxn];
int minRoute[mxn],maxRoute[mxn];

long long dijkstra(vector<pair<int,int>> arr[],int i,int n){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,i});
    vector<long long> dist(n+1,1e18);
    dist[i]=0;
    nRoute[i]=1;
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        if(a.fr!=dist[a.sc]) continue;
        for(auto aa:arr[a.sc]){
            if(dist[a.sc]+aa.sc<dist[aa.fr]){
                dist[aa.fr]=dist[a.sc]+aa.sc;
                nRoute[aa.fr]=(nRoute[a.sc])%mod;
                minRoute[aa.fr]=minRoute[a.sc]+1;
                maxRoute[aa.fr]=maxRoute[a.sc]+1;
                pq.push({dist[aa.fr],aa.fr});
            }else if(dist[a.sc]+aa.sc==dist[aa.fr]){
                nRoute[aa.fr]=(nRoute[aa.fr]+nRoute[a.sc])%mod;
                minRoute[aa.fr]=min(minRoute[aa.fr],minRoute[a.sc]+1);
                maxRoute[aa.fr]=max(maxRoute[aa.fr],maxRoute[a.sc]+1);
            }
        }
    }
    return dist[n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    auto route=dijkstra(adj,1,n);
    cout<<route<<" "<<nRoute[n]<<" "<<minRoute[n]<<" "<<maxRoute[n]<<endl;
    
   
   return 0;
}
