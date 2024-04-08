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
const ll mod=1000000007;
const long long mod_inverse_2 = 500000004;

void dfs(vector<string> &arr,int i,int j){
    if(i>=arr.size()||i<0||j>=arr[0].size()||j<0) return;
    if(arr[i][j]=='#') return;
    arr[i][j]='#';
    dfs(arr,i+1,j);
    dfs(arr,i,j+1);
    dfs(arr,i-1,j);
    dfs(arr,i,j-1);
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<string> arr(n);
    input(arr);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                dfs(arr,i,j);
                count++;
            } 
        }
    }
    cout<<count<<endl;
   return 0;
}