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
const ll mod=1000000007;

ll solve(ll n,ll m,vector<vector<ll>> &dp){
    if(n==m) return 0;
    
    if(dp[n][m]!=-1) return dp[n][m];
    ll horizontal=INT_MAX,vertical=INT_MAX;
    for(int i=1;i<n;i++){
        horizontal=min(1+solve(n-i,m,dp)+solve(i,m,dp),horizontal);
    }
     for(int i=1;i<m;i++){
        vertical=min(1+solve(n,m-i,dp)+solve(n,i,dp),vertical);
    }
    return dp[n][m]=min(vertical,horizontal);
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    ll ans=solve(n,m,dp);
    cout<<ans<<endl;
   return 0;
}



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
const ll mod=1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            } 
            ll horizontal=INT_MAX,vertical=INT_MAX;
            for(int k=1;k<i;k++){
                horizontal=min(1+dp[i-k][j]+dp[k][j],horizontal);
            }
             for(int k=1;k<j;k++){
                vertical=min(1+dp[i][j-k]+dp[i][k],vertical);
            }
            dp[i][j]=min(vertical,horizontal);
        }
    }
    cout<<dp[n][m]<<endl;
   return 0;
}