

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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    input(arr);
    sort(all(arr));
    int i=0,j=n-1,count=0;
    while(i<=j){
        count++;
        if(i==j){
            break;
        }
        if(arr[i]+arr[j]<=k){
            i++;
            j--;
        }else{
            j--;
        }
    }
    cout<<count<<endl;
   return 0;
}