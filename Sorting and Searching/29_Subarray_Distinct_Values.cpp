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
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    input(arr);
    map<ll,ll> mp;
    int j=0;
    ll count=0;
    for(int i=0;i<n;i++){
       mp[arr[i]]++;
       if(mp.size()>m){
            count+=(i-j)*(i-j+1)/2;
            while(mp.size()>m){
               mp[arr[j]]--;
               if(mp[arr[j]]==0){
                  mp.erase(arr[j]);
               }
               j++;
           } 
           count-=(i-j)*(i-j+1)/2;
       }
       
    }
    count+=(n-j)*(n-j+1)/2;
    cout<<count<<endl;
   return 0;
}