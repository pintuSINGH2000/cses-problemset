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
const int mxn=200005;
int st[mxn][30];
void preProcessor(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        st[i][0]=arr[i];
    }
    
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;(i+(1<<j)-1)<n;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r){
    int a=log2(r-l+1);
    return min(st[l][a],st[r-(1<<a)+1][a]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> arr(n);
    input(arr);
    preProcessor(arr,n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
       cout<<query(a,b)<<endl;
    }
   return 0;
}