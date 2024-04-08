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
    int n;
    cin>>n;
    vector<string> arr(n);
    input(arr);
    if(arr[0][0]=='*'){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0) continue;
            if(i==0&&arr[i][j]!='*'){
                dp[i][j]=dp[i][j-1];
            }else if(j==0&&arr[i][j]!='*'){
                dp[i][j]=dp[i-1][j];
            }else if(j>0&&i>0&&arr[i][j]!='*'){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
   return 0;
}
