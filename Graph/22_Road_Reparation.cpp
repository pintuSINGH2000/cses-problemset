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
const int mxn=200005;
const int d=30;
bool vis[mxn];
int step;
queue<int> q;
int ans[mxn],arr[mxn];
 
class UnionAndFind{
    vector<int> parent;
    vector<int> rank;
    public:
    UnionAndFind(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    void Union(int a,int b){
        int x=Find(a);
        int y=Find(b);
        if(x!=y){
            if(rank[x]>rank[y]){
                parent[y]=parent[x];
            }else if(rank[y]>rank[x]){
                parent[x]=parent[y];
            }else{
                parent[y]=parent[x];
                rank[x]++;
            }
        }
    }
    
    int Find(int a){
        if(a!=parent[a]) return parent[a]=Find(parent[a]);
        return a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    UnionAndFind kruskal(n);
    ll cost=0;
    while(!pq.empty()){
        auto aa=pq.top();
        pq.pop();
        int x=kruskal.Find(aa.sc.fr);
        int y=kruskal.Find(aa.sc.sc);
        if(x==y) continue;
        kruskal.Union(aa.sc.fr,aa.sc.sc);
        cost+=aa.fr;
    }
    
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++){
        mp[kruskal.Find(i)]++;
    }
    
    if(mp.size()==1){
        cout<<cost<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    cout<<endl;
    
   return 0;

}