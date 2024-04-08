

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> dp(1<<n);
    dp[0]=1;
    print(dp);
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            vector<ll> cur(1<<n);
            for(int mask=0;mask<(1<<n);mask++){
                cur[mask]=dp[mask^(1<<i)];
                if(i&&!(mask&(1<<i))&&!(mask&(1<<(i-1)))){
                    cur[mask] += dp[mask^(1<<(i-1))];
                }
                cur[mask]%=mod;
            }
            print(cur);
            dp=cur;
        }
        cout<<endl;
    }
    cout<<dp[0]<<endl;
   return 0;
}