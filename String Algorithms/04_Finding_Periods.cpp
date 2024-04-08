
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

vector<int> Z(string s){
     int n=s.length(); 
     vector<int> ZArray(n);
     int left=0,right=0;
     for(int i=1;i<n;i++){
         if(i<=right){
             ZArray[i]=min(right-i+1,ZArray[i-left]);
         }
         while(i+ZArray[i]<n&&s[ZArray[i]]==s[i+ZArray[i]]){
             ZArray[i]++;
         }
         if(i+ZArray[i]-1>right){
             left=i;
             right=i+ZArray[i]-1;
         }
     }
     return ZArray;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    vector<int> ZArray=Z(s);
    for(int i=0;i<n;i++){
        if(ZArray[i]+i==n) cout<<i<<" ";
    }
    cout<<n<<endl;
    
   return 0;
}