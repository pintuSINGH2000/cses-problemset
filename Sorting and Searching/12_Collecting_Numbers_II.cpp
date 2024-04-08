Collecting Numbers II
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
    int n,m;
    cin>>n>>m;
    vector<int> arr(n,0);
    vector<int> ind(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
        ind[arr[i]]=i;
    }
    set<pair<int,int>> st;
    auto changeEffect = [&](int i){
        //due to change effect occur at neighbour element
        if(arr[i]>0){
            st.insert(mkp(arr[i]-1,arr[i]));
        }
        if(arr[i]<n-1){
            st.insert(mkp(arr[i],arr[i]+1));
        }
    };
    int ans=1;
    for(int i=1;i<n;i++){
        ans+=(ind[i]<ind[i-1]);
    }
    for(int i=0;i<m;i++){
       int k,l;
       cin>>k>>l;
       changeEffect(k-1);
       changeEffect(l-1);
       for(auto aa:st){
            ans-=(ind[aa.fr]>ind[aa.sc]);
       }
       swap(arr[k-1],arr[l-1]);
       swap(ind[arr[k-1]],ind[arr[l-1]]);
       for(auto aa:st){
          ans+=(ind[aa.fr]>ind[aa.sc]);
       }
       cout<<ans<<"\n";
       st.clear();
    }
    
   return 0;
}