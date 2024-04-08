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
    vector<int> root;
    int n;
    
    public:
       SegmentTree(int _n){
           n=_n;
           root.resize(n*4);
       }
    public:
    int query(int qstart,int qend){
        return query(1,0,n-1,qstart,qend);
    }
    
    private:
    int query(int node,int start,int end,int qstart,int qend){
        if(start>=qstart&&end<=qend){
            return root[node];
        }else if(start>qend || end< qstart){
            return INT_MAX;
        }else{
            int mid=start+(end-start)/2;
            return min(query(node*2,start,mid,qstart,qend),query(node*2+1,mid+1,end,qstart,qend));
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
                root[node]=val;
            }else{
                int mid=start+(end-start)/2;
                update(2*node,start,mid,index,val);
                update(2*node+1,mid+1,end,index,val);
                root[node]=min(root[2*node],root[2*node+1]);
            }
        }
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    SegmentTree up(n),down(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        up.update(i,a+i);
        down.update(i,a-i);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a==1){
            int b,c;
            cin>>b>>c;
            b--;
            up.update(b,c+b);
            down.update(b,c-b);
        }else{
            int b;
            cin>>b;
            b--;
            auto aa=up.query(b+1,n)-b;
            auto bb=down.query(1,b)+b;
            cout<<min(aa,bb)<<endl;
        }
    }
   return 0;
}