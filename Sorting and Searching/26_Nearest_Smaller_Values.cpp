
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
    ll n;
    cin>>n;
    vector<int> arr(n);
    input(arr);
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans.pb(0);
        }else{
            ans.pb(st.top()+1);
        }
        st.push(i);
    }
    print(ans);
   return 0;
}