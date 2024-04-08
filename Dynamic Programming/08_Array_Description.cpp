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

ll solve(vector<ll> &arr,int m,int i,int prev,vector<vector<ll>> &dp){
    if(i==arr.size()) return 1;
    if(dp[i][prev]!=-1){
         return dp[i][prev];
    }
    if(arr[i]==0){
        ll count=0;
        for(int j=1;j<=m;j++){
            if(prev==0||abs(j-prev)<=1){
                count=(count+solve(arr,m,i+1,j,dp))%mod;
            }
        }
        return dp[i][prev]=count;
    }else{
      if(prev==0||abs(arr[i]-prev)<=1){
          return dp[i][prev] = solve(arr,m,i+1,arr[i],dp);
      }  
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    input(arr);
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    auto a=solve(arr,m,0,0,dp);
    cout<<a<<endl;
   return 0;
}

// optimize code

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
    int n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    input(arr);
    vector<vector<ll>> dp(n,vector<ll>(m+1,0));
    if(arr[0]==0){
      for(int i=1;i<=m;i++){
          dp[0][i]=1;
      }
    }else{
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(arr[i]==0){
           for(int j=1;j<=m;j++){
               dp[i][j]+=dp[i-1][j];
               dp[i][j]+= dp[i-1][j-1];
               if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
               dp[i][j]%=mod;
           }
        }else{
            dp[i][arr[i]]+=dp[i-1][arr[i]];
            if(arr[i]-1>0) dp[i][arr[i]]+=dp[i-1][arr[i]-1];
            if(arr[i]+1<=m) dp[i][arr[i]]+=dp[i-1][arr[i]+1];
            dp[i][arr[i]]%=mod; 
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans<<endl;
   return 0;
}
