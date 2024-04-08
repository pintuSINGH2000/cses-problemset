

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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(n,make_pair(0,0));
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(all(arr));
    int i=0,j=n-1;
    while(i<j){
        if(arr[i].first+arr[j].first==m){
            cout<<arr[i].second<<" "<<arr[j].second<<endl;
            return 0;
        }else if(arr[i].first+arr[j].first>m){
            j--;
        }else{
            i++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
   return 0;
}