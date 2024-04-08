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

bool isPossible(vector<ll> &arr,ll mid,ll m){
    ll count=1,sum=0;
    for(int i=0;i<arr.size();i++){
       if(sum+arr[i]>mid){
           sum=arr[i];
           count++;
       }else{
           sum+=arr[i];
       }
    }
    return count<=m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    input(arr);
    ll right=accumulate(all(arr),0ll);
    ll left=*max_element(all(arr));
    ll ans=0;
    while(left<=right){
        ll mid=left+(right-left)/2;
        if(isPossible(arr,mid,m)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<ans<<endl;
   return 0;
}