


#include<bits/stdc++.h>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<nline
#define fr first
#define sc second 
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
         ll a=i*i;
         ll j=a*(a-1)/2;  //total number of moves in i*iC2
         ll m=4*(i-2)*(i-1);// total number of moves where knight attack i.e all 2*3 =2(i-2)*(i-1) rectangle and all 3*2 rectangle=2*(i-1)*(i-2)
         cout<<j-m<<endl;
    }
    return 0;
}