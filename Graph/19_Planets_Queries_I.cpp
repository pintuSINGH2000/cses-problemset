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
int parent[mxn][d];
 
int jump(int a,int b){
    int i=0;
    while(b>0){
        if(b&1){
            a=parent[a][i];
        }
        b>>=1;
        i++;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>parent[i][0];
    }
    
  for(int i=1;i<d;i++){
      for(int j=1;j<=n;j++){
          parent[j][i]=parent[parent[j][i-1]][i-1];
      }
  }
  for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      cout<<jump(a,b)<<"\n";
  }
   return 0;

}