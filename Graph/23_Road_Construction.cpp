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
    UnionAndFind kruskal(n);
    ll cost=0;
    
    unordered_map<int,set<int>> mp;
    int totalComponent=n;
    int mx=0;
    for(int i=1;i<=m;i++){
       int a,b;
       cin>>a>>b;
       int x=kruskal.Find(a);
       int y=kruskal.Find(b);
       if(x==y){
           cout<<totalComponent+mp.size()<<" "<<mx<<endl;
       }else{
           if(vis[a]&&vis[b]){
               int c=kruskal.Find(a);
               int d=kruskal.Find(b);
               kruskal.Union(a,b);
               int e=kruskal.Find(a);
               if(c==e){
                   mp[c].insert(all(mp[d]));
                   mp.erase(d);
                   mx=max(mx,(int)mp[c].size());
               }else{
                   mp[d].insert(all(mp[c]));
                   mx=max(mx,(int)mp[d].size());
                   mp.erase(c);
               }
           }else{
                kruskal.Union(a,b);
                if(!vis[a]){
                    vis[a]=true;
                    totalComponent--;
                } 
                if(!vis[b]){
                    vis[b]=true;
                  totalComponent--;  
                } 
                int c=kruskal.Find(a);
                mp[c].insert(a);
                mp[c].insert(b);
                mx=max(mx,(int)mp[c].size());
            }
                cout<<totalComponent+mp.size()<<" "<<mx<<endl;
          
       }
    }
    
   return 0;

}