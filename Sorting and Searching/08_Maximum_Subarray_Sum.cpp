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
    ll globalmax=INT_MIN;
    ll localmax=0;
    for(int i=0;i<n;i++){
        localmax=max(localmax+arr[i],(ll)arr[i]);
        globalmax=max(globalmax,localmax);
    }
    cout<<globalmax<<endl;
   return 0;
}