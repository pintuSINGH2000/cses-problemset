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
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    vector<bool> vis(n+1,false);
    vector<long long> dist(n+1,1e18);
    dist[1]=0;
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
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
