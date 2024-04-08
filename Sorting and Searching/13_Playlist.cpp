

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
    vector<int> arr(n,0);
    input(arr);
    unordered_map<int,int> mp;
    int j=0,count=0,mx=0;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        while(mp[arr[i]]>1){
            count--;
            mp[arr[j]]--;
            j++;
        }
        count++;
        mx=max(mx,count);
    }
    cout<<mx<<endl;
   return 0;
}