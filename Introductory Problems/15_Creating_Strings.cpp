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

void solve(string s,string temp,set<string> &ans,vector<bool> &vis){
    if(temp.size()==s.size()){
        ans.insert(temp);
        return;
    }
    for(int i=0;i<s.length();i++){
        if(!vis[i]){
            vis[i]=true;
            solve(s,temp+s[i],ans,vis);
            vis[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    set<string> ans;
    sort(all(s));
    vector<bool> vis(s.length(),false);
    solve(s,"",ans,vis);
    cout<<ans.size()<<endl;
    println(ans);
   return 0;
}