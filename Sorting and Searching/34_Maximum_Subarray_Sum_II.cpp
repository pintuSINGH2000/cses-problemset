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
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> arr(n);
    input(arr);
    multiset<ll> st;
    vector<ll> pre(n+1);
   for(int i=1;i<=n;i++){
       pre[i]=pre[i-1]+arr[i-1];
   }
   ll mx=-1e18;
   for(int i=a;i<=n;i++){
       if(i>b){
           st.erase(st.find(pre[i-b-1]));
       }
       st.insert(pre[i-a]);
       mx=max(mx,pre[i]-*st.begin());
   }
    cout<<mx<<endl;
   return 0;
}