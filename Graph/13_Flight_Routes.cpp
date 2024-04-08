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
// char  par[1000][1000], ans[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m ,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    priority_queue<ll> dist[n+1];
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});
    dist[1].push(0);
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        if(a.fr>dist[a.sc].top()) continue;
        for(auto aa:adj[a.sc]){
            if(dist[aa.fr].size()<k){
                dist[aa.fr].push(aa.sc+a.fr);
                pq.push({aa.sc+a.fr,aa.fr});
            }else{
                if(dist[aa.fr].top()>aa.sc+a.fr){
                    dist[aa.fr].pop();
                    dist[aa.fr].push(aa.sc+a.fr);
                    pq.push({aa.sc+a.fr,aa.fr});
                }
               
            }
        }
    }
    
    vector<ll> ans(k);
    int i=k-1;
    while(!dist[n].empty()){
        ans[i--]=dist[n].top();
        dist[n].pop();
    }
    
    print(ans);
    return 0;
}
