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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        arr[i]=sum;
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if(a==0){
            cout<<arr[b]<<endl;
        }else{
            cout<<arr[b]-arr[a-1]<<endl;
        }
    }
   return 0;
}