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
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].sc>>arr[i].fr;
    }
    sort(all(arr));
   multiset<int> st;
   for(int i=0;i<m;i++){
       st.insert(0);
   }
   int count=0;
   for(int i=0;i<n;i++){
       auto aa=st.upper_bound(arr[i].sc);
       if(aa!=st.begin()){
          st.erase(--aa);
           st.insert(arr[i].fr);
           count++;
       }
   }
    cout<<count<<endl;
   return 0;
}