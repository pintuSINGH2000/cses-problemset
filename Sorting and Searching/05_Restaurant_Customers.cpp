

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
using namespace std;
ll mod=1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> en(n,0);
    vector<int> ex(n,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        en[i]=a;
        ex[i]=b;
    }
    sort(all(en));
    sort(all(ex));
    int mx=0;
    int i=0,j=0,count=0;
    while(i<n&&j<n){
       if(en[i]<ex[j]){
           count++;
           i++;
           mx=max(count,mx);
       }else{
           j++;
           count--;
       }
    }
    cout<<mx<<endl;
   return 0;
}