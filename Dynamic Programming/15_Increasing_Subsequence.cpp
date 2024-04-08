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
    input(arr);
   
    vector<int> dp(n+2);

    for(int i=n-1;i>=0;i--){
        vector<int> temp(n+2);
        for(int j=n-1;j>=0;j--){
            if(j==0||arr[j-1]<arr[i]){
                temp[j]=max(dp[j],1+dp[i+1]);
            }else{
                temp[j]=dp[j];
            }
        }
        dp=temp;
    }
    cout<<dp[0]<<endl;
   return 0;
}


// optimize tc(nlogn)
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
    input(arr);
   
    vector<int> dp;
    for(int i=0;i<n;i++){
        auto aa=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
        if(aa==dp.size()){
            dp.push_back(arr[i]);
        }else{
            dp[aa]=arr[i];
        }
    }
    cout<<dp.size()<<endl;
   return 0;
}