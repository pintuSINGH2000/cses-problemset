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
    multiset<int> st;
    
    int a=INT_MAX,ans=0;
    for(int i=0;i<n;i++){
        auto aa=st.upper_bound(arr[i]);
        if(aa!=st.end()){
            st.erase(aa);
        }else{
            ans++;
        }
        st.insert(arr[i]);
    }
    cout<<ans<<endl;
   return 0;
}