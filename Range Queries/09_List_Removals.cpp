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
class SegmentTree{
    public:
    vector<ll> root;
    int n;
    
    public:
       SegmentTree(vector<int> &arr,int m){
          n=m;
          root.resize(n*2);
          for(int i=0;i<arr.size();i++){
              root[i+n]=arr[i];
          }
          for(int i=n-1;i>=1;i--){
              root[i]=root[2*i]+root[2*i+1];
          }
       }
    
    public:
    ll query(int index){
        int node=1;
       while(node<n){
           if(root[node*2]>=index){
               node<<=1;
           }else{
               index-=root[node*2];
               node<<=1;
               node++;
           }
       }
       return node-n;
    }
    
    public:
    void update(int index,int val){
        index+=n;
        root[index]=val;
        index>>=1;
        while(index>=1){
            root[index]=root[index*2]+root[index*2+1];
            index>>=1;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int m = ceil(log2(n));
    m = pow(2,m);
    vector<int> arr(n,1);
    SegmentTree st(arr,m);
    input(arr);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int k=st.query(a);
        st.update(k,0);
        cout<<arr[k]<<" ";
    }
   return 0;
}