
#include<bits/stdc++.h>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<"\n";
#define fr first
#define sc second 
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
using namespace std;
ll mod=1000000007;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        int ans=(i^(i>>1));
        for(int j=n-1;j>=0;j--){
            if((ans>>j)&1){
                cout<<1;
            }else{
                cout<<0;
            }
        }
        cout<<endl;
    }
   return 0;
}