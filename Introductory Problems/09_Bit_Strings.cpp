#include<bits/stdc++.h>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<"\n";
#define fr first
#define sc second 
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
using namespace std;
ll mod=1000000007;

ll power(ll base,ll power){
    ll ans=1;
    while(power>0){
        if(power&1){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        power=power>>1;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    cout<<power(2,n)<<endl;
}