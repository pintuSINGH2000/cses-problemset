
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

bool isSafe(vector<string> &s,int row,int col){
    for(int i=0;i<8;i++)
       if(s[i][col]=='Q') return false;
    
    for(int i=row-1,j=col-1;i>=0&&j>=0;j--,i--){
        if(s[i][j]=='Q') return false;
    }
     for(int i=row-1,j=col+1;i>=0&&j<8;j++,i--){
        if(s[i][j]=='Q') return false;
    }
    return true;
}
void solve(vector<string> &s,int row,ll &count){
   if(row==8) {
       count++;
       return;
   }
   
   for(int i=0;i<8;i++){
       if(s[row][i]=='.'){
           if(isSafe(s,row,i)){
               s[row][i]='Q';
               solve(s,row+1,count);
               s[row][i]='.';
           }
       }
   }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> s(8);
    input(s);
    ll count=0;
    solve(s,0,count);
    cout<<count<<endl;
   return 0;
}