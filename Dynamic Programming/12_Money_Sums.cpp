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
    auto sum=accumulate(all(arr),0);
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;
    for(int i = 1; i <= n; i++){
        int val = arr[i - 1];
        for(int j = 0; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - val >= 0){
                dp[i][j] = dp[i][j] || dp[i - 1][j - val];
            }
        }
    }
    vector<int> ans;
    for(int i=1;i<=sum;i++){
        if(dp[n][i]){
            ans.pb(i);
        }
    }
    cout<<ans.size()<<endl;
    print(ans);
   return 0;
}