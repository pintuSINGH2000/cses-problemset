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
    set<int> st={0,n};
    multiset<int> mst={n};
    int a=INT_MAX,ans=0;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        auto it1=st.upper_bound(a);
        auto it2=it1;
        --it2;
        mst.erase(mst.find(*it1-*it2));
        mst.insert(*it1-a);
        mst.insert(a-*it2);
        st.insert(a);
        auto ans=mst.end();
        --ans;
        cout<<*ans<<endl;
    }
   return 0;
}