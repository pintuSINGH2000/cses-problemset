
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
    vector<pair<int,int>> arr(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr[i].first=b;
        arr[i].second=a;
    }
    sort(all(arr));
    int prev=0,count=0;
    for(int i=0;i<n;i++){
        if(arr[i].second>=prev){
            count++;
            prev=arr[i].first;
        }
    }
    cout<<count<<endl;
   return 0;
}