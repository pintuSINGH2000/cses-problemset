

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
    int n;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    sort(all(arr));
    ll sum=1;
    for(int i=0;i<n;i++){
       if(sum<arr[i]){
           break;
       }
       sum+=arr[i];
    }
    cout<<sum<<endl;
   return 0;
}