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
const ll mod = 1000000007;
const long long lmax=1e18;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U', 'R', 'D', 'L'};
char  par[1000][1000], ans[1000000];
void dfs(vector<int> a[],vector<bool> &vis,int i){
    vis[i]=true;
    for(auto aa:a[i]){
        if(!vis[aa])
           dfs(a,vis,aa);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m ;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<int> arr1[n+1];
    vector<int> arr2[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr1[a].pb(b);
        arr2[b].pb(a);
        edges.pb({a,b,-c});
    }
    vector<ll> dist(n+1,lmax);
    dist[1]=0;
    for(int i=1;i<=n;i++){
        for(auto edge:edges){
            ll a=edge[0];
            ll b=edge[1];
            ll c=edge[2];
            if(dist[a]!=lmax){
                dist[b]=min(dist[b],dist[a]+c);
            }
        }
    }
    vector<bool> vis1(n+1,false);
    vector<bool> vis2(n+1,false);
    dfs(arr1,vis1,1);
    dfs(arr2,vis2,n);
    bool flag=false;
	for(auto aa:edges){
	       ll u=aa[0];
	       ll v=aa[1];
	       ll w=aa[2];
	       if(vis1[u]&&vis2[v]&&dist[v]>dist[u]+w){
	           flag=true;
	             dist[v]=dist[u]+w;
	       }
	     
	}
	if(flag){
	    cout<<-1<<endl;
	}else{
	    cout<<-1*dist[n]<<endl;
	}
    return 0;
}
