

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
    multiset<int> st;//stroe duplicate key
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.insert(a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        auto aa=st.upper_bound(a);
        if(aa!=st.begin()){
            cout<<*(--aa)<<endl;
            st.erase(aa);
        }else{
            cout<<-1<<endl;
        }
    }
   return 0;
}