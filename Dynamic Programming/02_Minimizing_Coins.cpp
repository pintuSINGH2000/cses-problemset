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
ll mod=1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    input(arr);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      for(int i=1;i<=m;i++){
        dp[0][i]=INT_MAX-1;
		}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(j-arr[i-1]>=0){
              dp[i][j]=min(1+dp[i][j-arr[i-1]],dp[i-1][j]); 
           }else{
              dp[i][j]=dp[i-1][j];
           }
        }
    }
    if(dp[n][m]==INT_MAX-1){
        cout<<-1<<endl;
    }else{
        cout<<dp[n][m]<<endl;
    }
   return 0;
}