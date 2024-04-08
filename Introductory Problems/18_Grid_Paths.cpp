
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
using namespace std;
const int n=7;
char s[n*n-1];
bool vis[n][n];
ll mod=1000000007;

bool inbounds(int x,int y){
    return (x>=0&&x<n&&y>=0&&y<n);
}
void solve(int x,int y,int i,ll &ans){
    if(i==n*n-1||(x==n-1&&y==0)){
        ans+=(i==n*n-1&&x==n-1&&y==0);
        return;
    }
    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;
    
    vis[x][y]=true;
    if(s[i]=='D'||s[i]=='?'){
        if(inbounds(x+1,y)&&!vis[x+1][y])
           solve(x+1,y,i+1,ans);
    }
    if(s[i]=='U'||s[i]=='?'){
        if(inbounds(x,y)&&!vis[x-1][y])
           solve(x-1,y,i+1,ans);
    }
    if(s[i]=='L'||s[i]=='?'){
        if(inbounds(x,y-1)&&!vis[x][y-1])
           solve(x,y-1,i+1,ans);
    }
    if(s[i]=='R'||s[i]=='?'){
        if(inbounds(x,y+1)&&!vis[x][y+1])
           solve(x,y+1,i+1,ans);
    }
    vis[x][y]=false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %s", s);
    ll ans=0;
    solve(0,0,0,ans);
    cout<<ans<<endl;
   return 0;
}




#include <bits/stdc++.h>

using namespace std;
const int N = 7;

int ans;
char c[N*N+1];
bool vis[N+1][N+1];

bool inbounds(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

void dfs(int x, int y, int i){
    if(i == N*N-1 || (x == N && y == 1)){
        ans += (i == N*N-1 && (x == N && y == 1));
        return;
    }

    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;

    vis[x][y] = true;
    if(c[i] == 'D' || c[i] == '?')
        if(inbounds(x+1, y) && !vis[x+1][y])
            dfs(x+1, y, i+1);
    if(c[i] == 'U' || c[i] == '?')
        if(inbounds(x-1, y) && !vis[x-1][y])
            dfs(x-1, y, i+1);
    if(c[i] == 'R' || c[i] == '?')
        if(inbounds(x, y+1) && !vis[x][y+1])
            dfs(x, y+1, i+1);
    if(c[i] == 'L' || c[i] == '?')
        if(inbounds(x, y-1) && !vis[x][y-1])
            dfs(x, y-1, i+1);
    vis[x][y] = false;
}

int main(){
    scanf(" %s", c);
    dfs(1, 1, 0);
    printf("%d\n", ans);
}