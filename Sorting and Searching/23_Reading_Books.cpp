

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
    vector<int> arr(n);
    input(arr);
    ll sum=accumulate(all(arr),0);
    ll mx=*max_element(all(arr));
    if(mx>sum-mx){
        cout<<mx*2<<endl;
    }else{
        cout<<sum<<endl;
    }
   return 0;
}