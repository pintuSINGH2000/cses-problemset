

case1 when prev both column is open separately
      1 close first column and open second column    (single open)
      2 close second column and open first column     (single open)
      3 close both and start separately both open     (single open)
      4 dont close and make go as it is              (single open)
      5 close both and start both open as one        (both open)

case2 when prev both column open as one
      1 close and open as one  (both open)
      2 dont close and make go as it is  (both open)
      3 close and open separately   (single open)
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
ll dp[2][1000006];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=1;i<1000001;i++){
        dp[0][i]=((4*dp[0][i-1])%mod+dp[1][i-1])%mod;
        dp[1][i]=(dp[0][i-1]+(dp[1][i-1]*2)%mod)%mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[1][n-1]+dp[0][n-1])%mod<<endl;
    }
    
   return 0;
}
