
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr1(n,0);
    vector<int> arr2(m,0);
    input(arr1);
    input(arr2);
    sort(all(arr1));
    sort(all(arr2));
    int i=0,j=0,count=0;
    while(i<n&&j<m){
        if(arr1[i]>=arr2[j]-k&&arr1[i]<=arr2[j]+k){
            i++;
            j++;
            count++;
        }else if(arr1[i]<arr2[j]-k){
            i++;
        }else if(arr1[i]>arr2[j]+k){
            j++;
        }
    }
    cout<<count<<endl;
   return 0;
}