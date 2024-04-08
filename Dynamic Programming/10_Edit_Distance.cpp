


#include<bits/stdc++.h>
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

ll solve(string s,string t,int i,int j,vector<vector<ll>> &dp){
    if(i==s.length()&&j==t.length()) return 0;
    if(i==s.length()) return t.length()-j;
    if(j==t.length()) return s.length()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=solve(s,t,i+1,j+1,dp);
    }else{
        return dp[i][j]= min(1+solve(s,t,i+1,j,dp),min(1+solve(s,t,i,j+1,dp),1+solve(s,t,i+1,j+1,dp)));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    ll ans=solve(s,t,0,0,dp);
    cout<<ans<<endl;
   return 0;
}


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
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(i==n){
                dp[i][j]=m-j;
            }else if(j==m){
                dp[i][j]=n-i;
            }else if(s[i]==t[j]){
               dp[i][j]=dp[i+1][j+1];
            }else{
              dp[i][j]= 1+ min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
            }
        }
    }
    cout<<dp[0][0]<<endl;
   return 0;
}