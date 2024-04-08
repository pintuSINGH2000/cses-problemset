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
ll dp[20][10][2][2];
ll solve(string num,int n,int leadingzero,int tight,int prev){
    if(n==0){
         return 1;
    }
    if(dp[n][prev][tight][leadingzero]!=-1&&tight!=1) return dp[n][prev][tight][leadingzero];
    int ub = (tight?num[num.length()-n]-'0':9);
    ll ans=0;
    for(int i=0;i<=ub;i++){
        if(!leadingzero&&prev==i) continue;
        int newTight = ((num[num.length()-n]-'0') == i)? tight : 0;
        ans+=solve(num,n-1,leadingzero && i==0,newTight,i);
    }
    return dp[n][prev][tight][leadingzero]=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    n--;
    string l=to_string(n);
    string r=to_string(m);
    memset(dp, -1, sizeof(dp));
    ll ans1=solve(r,r.length(),1,1,0);
    ll ans2=solve(l,l.length(),1,1,0);
    cout<<ans1-ans2<<"\n";
   return 0;
}