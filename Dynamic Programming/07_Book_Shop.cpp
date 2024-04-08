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
    vector<ll> price(n);
    vector<ll> page(n);
    input(price);
    input(page);
    vector<ll> dp(m+1,0);
    for(int i=1;i<=n;i++){
        vector<ll> cur(m+1,0);
        for(int j=1;j<=m;j++){
            if(j-price[i-1]>=0){
               cur[j]=max(page[i-1]+dp[j-price[i-1]],dp[j]);
            }else{
               cur[j]= dp[j];
            }
        }
        dp=cur;
    }
   
    cout<<dp[m]<<"\n";
   return 0;
}
