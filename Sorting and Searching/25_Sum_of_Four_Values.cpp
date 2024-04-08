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
    vector<pair<int,int>> arr(n);
     for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i].fr=a;
        arr[i].sc=i;
    }
    sort(all(arr));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target=m-arr[i].fr-arr[j].fr;
            int l=j+1,k=n-1;
            while(l<k){
                if(arr[l].fr+arr[k].fr==target){
                    cout<<arr[i].sc+1<<" "<<arr[j].sc+1<<" "<<arr[k].sc+1<<" "<<arr[l].sc+1;
                    return 0;
                }else if(arr[l].fr+arr[k].fr>target){
                    k--;
                }else{
                    l++;
                }
            } 
        }
    }
    cout<<"IMPOSSIBLE";
   return 0;
}


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
    vector<int> arr(n);
     for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    map<int,pair<int,int>> mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target=m-arr[i]-arr[j];
            if(mp.find(target)!=mp.end()){
                cout<<i+1<<" "<<j+1<<" "<<mp[target].fr+1<<" "<<mp[target].sc+1;
                return 0;
            }
        }
        for(int j=i-1;j>=0;j--){
            mp[arr[i]+arr[j]]={i,j};
        }
    }
    cout<<"IMPOSSIBLE";
   return 0;
}