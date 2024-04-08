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
ll solve(vector<int> &arr,int i,int j,vector<vector<ll>> &dp){
    if(i>j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j]=max(arr[i]+min(solve(arr,i+2,j,dp),solve(arr,i+1,j-1,dp)),arr[j]+min(solve(arr,i,j-2,dp),solve(arr,i+1,j-1,dp)));
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<int> arr(n);
    input(arr);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    auto aa=solve(arr,0,n-1,dp);
    cout<<aa<<endl;
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
    ll n;
    cin>>n;
    vector<int> arr(n);
    input(arr);
    vector<vector<ll>> dp(n+2,vector<ll>(n+2,0));
     for(int i=n-1;i>=0;i--){
        for(int j=i;j<=n-1;j++){
            if(i==j){
                dp[i][j]=arr[i];
                continue;
            }
        dp[i][j]=max(arr[i]+ min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2]));
       }
    }
    cout<<dp[0][n-1]<<endl;
   return 0;
}