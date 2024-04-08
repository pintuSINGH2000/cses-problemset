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

int solve(int n,vector<int> &arr,vector<int> &dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int count=0;
    for(int i=0;i<arr.size();i++){
        count=(count+solve(n-arr[i],arr,dp))%mod;
    }
    return dp[n]=count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr={1,2,3,4,5,6};
    vector<int> dp(n+1,-1);
    auto a=solve(n,arr,dp);
    cout<<a<<endl;
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
ll mod=1000000007;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr={1,2,3,4,5,6};
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        ll count=0;
        for(int j=0;j<arr.size();j++){
            if(i-arr[j]>=0){
                count=(count+dp[i-arr[j]])%mod;
            }
        }
       dp[i]=count;
    }
    cout<<dp[n]<<endl;
   return 0;
}
