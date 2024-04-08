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
string dir = "URDL";
 
void bfs(vector<string> &arr,int i,int j,string &ans){
    int n=arr.size();
    int m=arr[0].size();
    queue<pair<int,pair<int,string>>> q;
    q.push({i,{j,""}});
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto aa=q.front();
            q.pop();
            int a=aa.fr;
            int b=aa.sc.fr;
            string c=aa.sc.sc;
            for(int j=0;j<4;j++){
                if (a+dx[j] < 0 || a+dx[j] >= n || b+dy[j] < 0 || b+dy[j] >= m) continue;
                if(arr[a+dx[j]][b+dy[j]]=='#') continue;
                  
                  if(arr[a+dx[j]][b+dy[j]]=='B'){
                      ans=(c+dir[j]);
                      return ;
                  }else{
                      arr[a+dx[j]][b+dy[j]]='#';
                      q.push({a+dx[j],{b+dy[j],c+dir[j]}});
                  }
                }
            }
        }
    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<string> arr(n);
    input(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
               string ans;
                bfs(arr,i,j,ans);
                if(ans.size()>0){
                    cout<<"YES"<<endl;
                    cout<<ans.length()<<endl;
                    cout<<ans<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
                return 0;
            } 
        }
    }
   return 0;
}


// more optimize
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
char  par[1000][1000], ans[1000000];
int sx, sy, ex, ey, dist[1000][1000];

void bfs(vector<string> &arr,int i,int j){
    int n=arr.size();
    int m=arr[0].size();
    queue<pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            auto aa=q.front();
            q.pop();
            int a=aa.fr;
            int b=aa.sc;
            for(int j=0;j<4;j++){
                if (a+dx[j] < 0 || a+dx[j] >= n || b+dy[j] < 0 || b+dy[j] >= m) continue;
                if(arr[a+dx[j]][b+dy[j]]=='#') continue;
                  par[a+dx[j]][b+dy[j]]=dir[j];
                  dist[a+dx[j]][b+dy[j]]=dist[a][b]+1;
                  if(arr[a+dx[j]][b+dy[j]]=='B'){
                      arr[a+dx[j]][b+dy[j]]='#';
                      return ;
                  }else{
                      arr[a+dx[j]][b+dy[j]]='#';
                      
                      q.push({a+dx[j],b+dy[j]});
                  }
                }
            }
        }
    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<string> arr(n);
    input(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                sx=i;
                sy=j;
            }
            if(arr[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    bfs(arr,sx,sy);
    if(arr[ex][ey]!='#'){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<dist[ex][ey]<<endl;
    pair<int,int> p={ex,ey};
    for(int i=dist[ex][ey];i>=0;i--){
        ans[i]=par[p.fr][p.sc];
        if(ans[i]=='D') p={p.fr-1,p.sc};
        else if(ans[i]=='U') p={p.fr+1,p.sc};
        else if(ans[i]=='L') p={p.fr,p.sc+1};
        else p={p.fr,p.sc-1};
    }
    for(int i=1;i<=dist[ex][ey];i++){
        cout<<ans[i];
    }
    cout<<endl;
   return 0;
}