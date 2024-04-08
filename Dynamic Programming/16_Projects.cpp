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
    ll n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    const auto comp = [&](const vector<int> a,const vector<int> b){
          if(a[1]==b[1]) return a[0]<b[0];
          else return a[1]<b[1];
    }; 
    sort(all(arr),comp);
    vector<pair<int,ll>> dp;
    dp.pb({0,0ll});
    for(int i=0;i<n;i++){
        auto it=lower_bound(all(dp),mkp(arr[i][0],-1ll));
        auto next=mkp(arr[i][1],arr[i][2]*1ll);
        if(it!=dp.begin()){
            next.second+=prev(it)->second;
        }
        next.second=max(next.second,dp.back().second);
        dp.pb(next);
    }
    cout<<dp.back().second<<endl;
   return 0;
}