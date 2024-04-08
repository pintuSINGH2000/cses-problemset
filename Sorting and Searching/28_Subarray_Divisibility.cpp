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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    input(arr);
    map<ll,ll> mp;
    ll sum=0;
    mp[0]=1;
    ll count=0;
    for(int i=0;i<n;i++){
       sum+=arr[i];
       int a=sum%n;
       if(a<0){
           a+=n;
       }
       if(mp.find(a)!=mp.end()){
           count+=mp[a];
       }
       mp[a]++;
    }
    cout<<count<<endl;
   return 0;
}