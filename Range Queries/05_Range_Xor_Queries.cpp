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
    vector<int> root;
    int n;
    
    public:
       SegmentTree(vector<int> arr){
          n=arr.size();
          root.resize(n*2);
          for(int i=0;i<n;i++){
              root[i+n]=arr[i];
          }
          for(int i=n-1;i>=0;i--){
              root[i]=root[2*i]^root[2*i+1];
          }
       }
    
    public:
    ll query(int qstart,int qend){
        qstart+=n;
        qend+=n;
        ll Xor=0;
        while(qstart<=qend){
            if(qstart&1){
                Xor^=root[qstart];
                qstart++;
            }
            if(!(qend&1)){
                Xor^=root[qend];
                qend--;
            }
            qstart>>=1;
            qend>>=1;
        }
        return Xor;
    }
    
    public:
    void update(int index,int val){
        index+=n;
        root[index]=val;
        while(index>=1){
            index>>=1;
            root[index]=root[index*2]^root[index*2+1];
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
        b--;
        cout<<st.query(a,b)<<endl;
    }
   return 0;
}