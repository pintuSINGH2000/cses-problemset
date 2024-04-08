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
ll dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n,0);
    input(arr);
    dp[0]=1;
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i-arr[j-1]>=0){
                dp[i]+=dp[i-arr[j-1]];
                dp[i]%=mod;
            }
        }
    }
   cout<<dp[m]<<"\n";
   return 0;
}
