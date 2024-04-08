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
struct Node{
    ll gmax,lmax,rmax,sum;
    friend Node operator+(Node a,Node b){
        return {max(max(a.gmax,b.gmax),a.rmax+b.lmax),max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax),a.sum+b.sum};
    }
};
class SegmentTree{
    public:
    vector<Node> root;
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
               root[node]={max(0,arr[start]),max(0,arr[start]),max(0,arr[start]),arr[start]};
               return;
           }
           int mid=start+(end-start)/2;
           buildTree(arr,2*node,start,mid);
           buildTree(arr,2*node+1,mid+1,end);
           root[node]=root[node*2]+root[node*2+1];
          
       }
    
    public:
    void update(int index,int val){
        update(1,0,n-1,index,val);
    }
    
    private:
    void update(int node,int start,int end,int index,int val){
        if(index>=start&&index<=end){
            if(index==start&&index==end){
               root[node]={max(0,val),max(0,val),max(0,val),val};
            }else{
                int mid=start+(end-start)/2;
                update(2*node,start,mid,index,val);
                update(2*node+1,mid+1,end,index,val);
                root[node]=root[node*2]+root[node*2+1];
            }
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
        int a,b;
        cin>>a>>b;
        a--;
        st.update(a,b);
        cout<<st.root[1].gmax<<endl;
    }
   return 0;
}