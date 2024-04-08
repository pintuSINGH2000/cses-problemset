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
const long long lmax=1e18;;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U', 'R', 'D', 'L'};
char  par[1000][1000], ans[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m , x;
    cin >> n >> m >> x;
    vector<vector<long long>> dist(n,vector<long long>(n,lmax));
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]&&dist[i][k]!=lmax&&dist[k][j]!=lmax){
                    dist[i][j]=dist[i][k]+dist[j][k];
                }
            }
        }
    }
    
    for(int i=0;i<x;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
        }else if(dist[a-1][b-1]==lmax){
            cout<<-1<<endl;
        }else{
           cout<<dist[a-1][b-1]<<endl;
        }
    }
    return 0;
}
