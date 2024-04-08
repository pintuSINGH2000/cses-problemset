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
const long long mod_inverse_2 = 500000004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(int i=1;i<=n;i++){
        arr[i-1]=i;
    }
    ll sum=accumulate(all(arr),0);
    if(sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    sum/=2;
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j-arr[i-1]>=0){
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<(dp[n][sum]*mod_inverse_2)%mod<<endl;
   return 0;
}