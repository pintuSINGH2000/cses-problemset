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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m ;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.pb({a,b,c});
    }
    vector<ll> dist(n+1,lmax);
    vector<ll> par(n+1,0);
    dist[1]=0;
    int flag=0;
    for(int i=1;i<=n;i++){
        flag=0;
        for(auto edge:edges){
            ll a=edge[0];
            ll b=edge[1];
            ll c=edge[2];
            if(dist[a]+c<dist[b]){
                dist[b]=min(dist[b],dist[a]+c);
                par[b]=a;
                flag=b;
            }
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
     
        vector<int> ans;
        // traverse so flag end up in cycle
        for(int i=1;i<=n;i++){
            flag=par[flag];
        }
        int x=flag;
        // here we will find reverse cycle
        while(true){
            ans.pb(x);
            if(x==flag&&ans.size()>1) break;
            x=par[x];
        }
        reverse(all(ans));
        print(ans);
    }
   
    return 0;
}
