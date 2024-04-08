#include <bits/stdc++.h>
#define input(x)      \
    for (auto &a : x) \
    cin >> a
#define print(x)          \
    for (auto &a : x)     \
    {                     \
        cout << a << ' '; \
    }                     \
    cout << "\n";
#define println(x)         \
    for (auto &a : x)      \
    {                      \
        cout << a << '\n'; \
    }
#define fr first
#define sc second
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
#define mkp make_pair
using namespace std;
const long long lmax=1e18;
const ll mod = 1000000007;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U', 'R', 'D', 'L'};
char  par[1000][1000], ans[1000000];
int  dist[1000][1000];
vector<long long> dijkstra(vector<pair<int,int>> arr[],int i,int n){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,i});
    vector<bool> vis(n+1,false);
    vector<long long> dist(n+1,1e18);
    dist[i]=0;
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        if(vis[a.sc]) continue;
        vis[a.sc]=true;
        for(auto aa:arr[a.sc]){
            if(dist[a.sc]+aa.sc<dist[aa.fr]){
                dist[aa.fr]=dist[a.sc]+aa.sc;
                pq.push({dist[aa.fr],aa.fr});
            }
        }
    }
    return dist;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m ;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<pair<int,int>> arr1[n+1];
    vector<pair<int,int>> arr2[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr1[a].pb({b,c});
        arr2[b].pb({a,c});
        edges.pb({a,b,c});
    }
    auto start=dijkstra(arr1,1,n);
    auto end=dijkstra(arr2,n,n);
    vector<vector<ll>> dist(n+1,vector<ll>(2,lmax));
    ll ans=lmax;
    for(int i=1;i<=n;i++){
        for(auto aa:edges){
            auto u=aa[0];
            auto v=aa[1];
            auto w=aa[2];
            if(start[u]==lmax||end[v]==lmax) continue;
            ans=min(ans,start[u]+end[v]+w/2);
        }
    }
    cout<<ans<<endl;
    return 0;
}

// optimize code
#include <bits/stdc++.h>
#define input(x)      \
    for (auto &a : x) \
    cin >> a
#define print(x)          \
    for (auto &a : x)     \
    {                     \
        cout << a << ' '; \
    }                     \
    cout << "\n";
#define println(x)         \
    for (auto &a : x)      \
    {                      \
        cout << a << '\n'; \
    }
#define fr first
#define sc second
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
#define mkp make_pair
using namespace std;
const long long lmax=1e18;
const ll mod = 1000000007;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U', 'R', 'D', 'L'};
char  par[1000][1000], ans[1000000];
int  dist[1000][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pair<int,int>> arr[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].pb({b,c});
    }
    priority_queue<pair<ll,pair<bool,int>>,vector<pair<ll,pair<bool,int>>> ,greater<pair<ll,pair<bool,int>>>> pq;
    pq.push({0,{false,1}});
    vector<bool> vis(n+1,false);
    vector<vector<ll>> dist(n+1,vector<ll>(2,lmax));
    dist[1][0]=0;
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        ll cost=dist[a.sc.sc][a.sc.fr];
        if(a.fr!=cost) continue;
        if(a.sc.sc==n) break;
        for(auto aa:arr[a.sc.sc]){
            if(!a.sc.fr){
                ll newCost=cost+aa.sc/2;
                if(newCost<dist[aa.fr][true]){
                    dist[aa.fr][true]=newCost;
                    pq.push({dist[aa.fr][true],{true,aa.fr}});
                }
            }
            if (cost + aa.sc < dist[aa.fr][a.sc.fr]) {
			   dist[aa.fr][a.sc.fr] = cost + aa.sc;
			   pq.push({dist[aa.fr][a.sc.fr],{a.sc.fr,aa.fr}});
			}
            
        }
    }
    cout<<dist[n][1]<<endl;
    return 0;
}
