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
 
void dfs(int planet){
   q.push(planet);
   if(vis[planet]){
       step+=ans[planet];
       return;
   }
   vis[planet]=true;
   step++;
   dfs(arr[planet]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            step=0;
            dfs(i);
            int dec=1;
            while(!q.empty()){
                if(q.front()==q.back()) dec=0;
                ans[q.front()]=step;
                step-=dec;
                q.pop();
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
   return 0;

}