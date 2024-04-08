

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
    vector<pair<int,int>> en(n);
    vector<pair<int,int>> ex(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        en[i].fr=a;
        en[i].sc=i;
        ex[i].fr=b;
        ex[i].sc=i;
    }
    sort(all(en));
    sort(all(ex));
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++){
        pq.push(i);
    }
    int mx=0;
    int i=0,j=0,count=0;
    vector<int> ans(n,0);
    while(i<n&&j<n){
       if(en[i].fr<=ex[j].fr){
           count++;
           ans[en[i].sc]= pq.top();
           pq.pop();
           i++;
           mx=max(count,mx);
       }else{
           pq.push(ans[ex[j].sc]);
           j++;
           count--;
       }
    }
    cout<<mx<<endl;
    print(ans);
   return 0;
}