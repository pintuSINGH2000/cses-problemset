
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
   string s;
   cin>>s;
   unordered_map<char,int> mp;
   for(int i=0;i<s.length();i++){
       mp[s[i]]++;
   }
   int a=0;
   for(auto aa:mp){
       if(aa.second&1) a++;
   }
   if(a>1){
       cout<<"NO SOLUTION";
   }else{
       int i=0,j=s.length()-1;
       char odd='0';
       for(auto aa:mp){
           if(aa.second&1){
               odd=aa.first;
           }
           for(int k=0;k<aa.second/2;k++){
               s[i]=aa.first;
               s[j]=aa.first;
               i++;
               j--;
           }
       }
       if(a==1){
           s[i]=odd;
       }
       cout<<s<<endl;
   }
   return 0;
}