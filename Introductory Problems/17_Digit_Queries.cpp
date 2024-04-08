
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

void solve(){
    ll n;
    cin>>n;
    ll dig=1,c=1;
    while(n>dig*9*c){
        n-=dig*9*c;
        dig++;
        c*=10;
    }
    
    ll num=n/dig;
    num+=(c-1);
    ll rem=n%dig;
    if(rem>0){
         rem=dig-rem+1; 
         num++;
    }
    while(rem>1){
        num/=10;
        rem--;
    }
    cout<<num%10<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   return 0;
}