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
const int MAXN = 200001;

class SegmentTree{
    public:
    vector<ll> root;
    int n;
    
    public:
       SegmentTree(vector<int> &arr){
           n=arr.size();
           root.resize(n*4);
           buildTree(arr,1,0,n-1);
       }
    
    private:
       void buildTree(vector<int> &arr,int node,int start,int end){
           if(start==end){
               root[node]=arr[start];
               return;
           }
           int mid=start+(end-start)/2;
           buildTree(arr,2*node,start,mid);
           buildTree(arr,2*node+1,mid+1,end);
           root[node]=max(root[2*node],root[2*node+1]);
       }
    
    public:
    void update(int val){
        update(1,0,n-1,val);
    }
    
    private:
    void update(int node,int start,int end,int val){
        if(start==end){
            root[node]-=val;
            cout<<start+1<<" ";
        }else{
            int mid=start+(end-start)/2;
            if(root[node*2]>=val){
                update(node*2,start,mid,val);
            }else{
                update(node*2+1,mid+1,end,val);
            }
            root[node]=max(root[node*2],root[node*2+1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> arr(n);
    input(arr);
    SegmentTree st(arr);
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(st.root[1]<a){
            cout<<0<<" ";
            continue;
        }
        st.update(a);
    }
   return 0;
}