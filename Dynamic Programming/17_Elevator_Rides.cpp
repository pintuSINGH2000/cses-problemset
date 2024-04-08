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
    vector<ll> arr(n);
    input(arr);
    vector<pair<ll,ll>> dp(1<<n,{1e9,1e9});
    dp[0]={1,0};
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                ll prev=((1<<j)^i);
                if(dp[prev].sc+arr[j]<=m){
                   dp[i]=min(dp[i],{dp[prev].fr,dp[prev].sc+arr[j]});
                }else{
                   dp[i]=min(dp[i],{dp[prev].fr+1,arr[j]});
                }
               
            }
        }
    }
    cout<<dp[(1<<n)-1].fr<<endl;
   return 0;
}