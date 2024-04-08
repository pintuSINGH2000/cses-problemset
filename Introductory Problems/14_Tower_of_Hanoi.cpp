
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

void toh(int n,int a,int c,int b){
    if(n<=0) return;
    toh(n-1,a,b,c);
    cout<<a<<" "<<c<<endl;
    toh(n-1,b,c,a);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<pow(2,n)-1<<endl;
    toh(n,1,3,2);
   return 0;
}