

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
ll mod=1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n,mkp(0,0));
    for(int i=0;i<n;i++){
        cin>>arr[i].fr;
        arr[i].sc=i;
    }
    sort(all(arr));
    int a=INT_MAX,ans=0;
    for(int i=0;i<n;i++){
        if(a>arr[i].sc){
            ans++;
        }
        a=arr[i].sc;
    }
    cout<<ans<<endl;
   return 0;
}