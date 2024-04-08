
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
const int n=7;
char s[n*n-1];
bool vis[n][n];
ll mod=1000000007;

void lps(string s,vector<int> &lpsArray){
    int len=0,i=1;
    int n=s.length();
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lpsArray[i]=len;
            i++;
        }else{
            if(len==0){
                i++;
            }else{
                len=lpsArray[len-1];
            }
        }
    }
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    vector<int> lpsArray(s.length(),0);
    lps(s,lpsArray);
    int j=lpsArray[s.size()-1];
    vector<int> ans;
    while(j>0){
        ans.pb(j);
        j=lpsArray[j-1];
    }
    sort(all(ans));
    print(ans);
    
   return 0;
}