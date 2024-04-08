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

ll solve(int n,vector<ll> &dp){
    if(n==0) return 0;
    if(n<0) return INT_MAX;
    ll mx=INT_MAX;
    int a=n;
    if(dp[n]!=-1) return dp[n];
    while(a>0){
        int rem=a%10;
        a/=10;
        if(rem==0) continue;
        mx=min(mx,1+solve(n-rem,dp));
    }
    return dp[n]=mx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    auto aa= solve(n,dp);
    cout<<aa<<"\n";
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
    int n;
    cin>>n;
    vector<ll> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int a=i;
        while(a>0){
            int rem=a%10;
            a/=10;
            if(rem==0) continue;
            dp[i]=min(dp[i],1+dp[i-rem]);
        }
    }
    cout<<dp[n]<<"\n";
   return 0;
}

