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
ll mod=1000000007;

class FenwickTree{
    int n;
    vector<ll> BIT;
    public:
    FenwickTree(int d){
        n=d;
        BIT.assign(d + 1, 0);
    }
    void update(int i,ll val){
        while(i<=n){
           BIT[i]+=val;
           i+=(i&-i); 
        }
    }
    ll query(int i){
        ll ans=0;
        while(i>0){
            ans+=BIT[i];
            i-=(i&-i);
        }
        return ans;
    }
    int rangeQuery(int i, int j) {
        return query(j) - query(i - 1);
    }
    void printBIT() {
        for (int i = 1; i <= n; ++i) {
            cout << BIT[i] << " ";
        }
        cout << endl;
    }
    void resetBIT() {
        BIT.assign(n + 1, 0);
    }
};
bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.fr.fr==b.fr.fr){
        return a.fr.sc>b.fr.sc;
    }
    return a.fr.fr<b.fr.fr;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> arr(n);
    set<int> st;
    FenwickTree ft(n);
    
    for(int i=0;i<n;i++){
       int a,b;
       cin>>a>>b;
       arr[i].sc=i;
       arr[i].fr={a,b};
       st.insert(b);
    }
    unordered_map<int,int> mp;
    int count=0;
    for(auto aa:st){
        mp[aa]= ++count;
    }
    sort(all(arr),comp);
    ft.update(mp[arr[n-1].fr.sc],1);
    vector<int> ans(n,0);
    for(int i=n-2;i>=0;i--){
        ans[arr[i].sc]+=ft.query(mp[arr[i].fr.sc]);
        ft.update(mp[arr[i].fr.sc],1);
    }
    for(int i=0;i<n;i++){
        if(ans[i]>0){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
    ans.assign(n, 0);
    ft.resetBIT();
    ft.update(1,1);
    ft.update(mp[arr[0].fr.sc]+1,-1);
    for(int i=1;i<n;i++){
        ans[arr[i].sc]+=ft.query(mp[arr[i].fr.sc]);
        ft.update(1,1);
        ft.update(mp[arr[i].fr.sc]+1,-1);
    }
    for(int i=0;i<n;i++){
        if(ans[i]>0){
            cout<<1<<" ";
        }else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
   return 0;
}