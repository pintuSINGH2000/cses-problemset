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
    vector<pair<ll,ll>> root;
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
               root[node].fr=arr[start];
               root[node].sc=max(0,arr[start]);
               return;
           }
           int mid=start+(end-start)/2;
           buildTree(arr,2*node,start,mid);
           buildTree(arr,2*node+1,mid+1,end);
           root[node].fr=root[2*node].fr+root[2*node+1].fr;
           root[node].sc=max(root[2*node].sc,root[2*node+1].sc+root[2*node].fr);
       }
    
    public:
    pair<ll,ll> query(int qstart,int qend){
        return query(1,0,n-1,qstart,qend);
    }
    
    private:
    pair<ll,ll> query(int node,int start,int end,int qstart,int qend){
        if(start>=qstart&&end<=qend){
            return root[node];
        }else if(start>qend || end< qstart){
            return {0ll,0ll};
        }else{
            int mid=start+(end-start)/2;
            auto a= query(node*2,start,mid,qstart,qend);
            auto b= query(node*2+1,mid+1,end,qstart,qend);
            return {a.fr+b.fr,max(a.sc,a.fr+b.sc)};
        }
    }
    
    public:
    void update(int index,int val){
        update(1,0,n-1,index,val);
    }
    
    private:
    void update(int node,int start,int end,int index,int val){
        if(index>=start&&index<=end){
            if(index==start&&index==end){
                root[node].fr=val;
                root[node].sc=max(0,val);
            }else{
                int mid=start+(end-start)/2;
                update(2*node,start,mid,index,val);
                update(2*node+1,mid+1,end,index,val);
                root[node].fr=root[node*2].fr+root[node*2+1].fr;
                root[node].sc=max(root[2*node].sc,root[2*node+1].sc+root[2*node].fr);
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
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            b--;
            st.update(b,c);
        }else{
            b--;
            c--;
            cout<<st.query(b,c).sc<<endl;
        }
    }
   return 0;
}