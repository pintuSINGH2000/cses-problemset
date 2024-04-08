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
       SegmentTree(vector<int> arr){
          n=arr.size();
          root.resize(n*2);
          for(int i=0;i<n;i++){
              root[i+n]=arr[i];
          }
       }
    
    public:
    ll query(int index){
        index+=n;
        ll sum=0;
        sum+=root[index];
        while(index>=1){
            index>>=1;
            sum+=root[index];
            if(index&1) index--;
        }
        return sum;
    }
    public:
    void update(int qstart,int qend,int val){
        qstart+=n;
        qend+=n;
        while(qstart<=qend){
            if(qstart&1){
                root[qstart]+=val;
                qstart++;
            }
            if(~qend&1){
               root[qend]+=val;
                qend--;
            }
            qstart>>=1;
            qend>>=1;
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
        if(a==1){
            int b,c,d;
            cin>>b>>c>>d;
            b--;
            c--;
            st.update(b,c,d);
        }else{
            int b;
            cin>>b;
            b--;
            cout<<st.query(b)<<endl;
        }
    }
   return 0;
}