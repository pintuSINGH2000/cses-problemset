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
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    input(arr);
    multiset<int> mx;
    multiset<int> mn;
    vector<int> ans;
    auto balance = [&](){
         if(mn.size()>mx.size()){
              mx.insert(*mn.begin());
              mn.erase(mn.find(*mn.begin()));
         }else if(mx.size()>mn.size()+1){
              mn.insert(*mx.rbegin());
              mx.erase(mx.find(*mx.rbegin()));
        }#include<bits/stdc++.h>
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
    int n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    input(arr);
    multiset<int> mx;
    multiset<int> mn;
    vector<int> ans;
    auto balance = [&](){
         if(mn.size()>mx.size()){
              mx.insert(*mn.begin());
              mn.erase(mn.find(*mn.begin()));
         }else if(mx.size()>mn.size()+1){
              mn.insert(*mx.rbegin());
              mx.erase(mx.find(*mx.rbegin()));
        }
    };
    auto add= [&](int a){
        if(mx.empty()||*mx.rbegin()>=a){
            mx.insert(a);
        }else{
            mn.insert(a);
        }
        balance();
    };
    auto erase = [&](int a){
        if(*mx.rbegin()>=a){
             mx.erase(mx.find(a));
        }else{
             mn.erase(mn.find(a));
        }
        balance();
    };
    auto median =[&]() -> int {
        return *mx.rbegin();
    };
    ll count=0;
    for(int i=0;i<m;i++){
        add(arr[i]);
    }
    ll prev= median();
    for(int i=0;i<m;i++){
        count+=abs(arr[i]-prev);
    }
    cout<<count<<" ";
    int j=0;
    for(int i=m;i<n;i++){
             add(arr[i]);
             erase(arr[j]);
             count-=abs(arr[j]-prev);
             ll curr=median();
             count+=abs(arr[i]-curr);
             if(!(m&1)) count-=(curr-prev);
             prev=curr;
             cout<<count<<" ";
             j++;
    }
    cout<<endl;
   return 0;
}
    };
    auto add= [&](int a){
        if(mx.empty()||*mx.rbegin()>=a){
            mx.insert(a);
        }else{
            mn.insert(a);
        }
        balance();
    };
    auto erase = [&](int a){
        if(*mx.rbegin()>=a){
             mx.erase(mx.find(a));
        }else{
             mn.erase(mn.find(a));
        }
        balance();
    };
    auto median =[&]() -> int {
        if(mn.size()>mx.size()){
            return *mn.begin();
        }else{
            return *mx.rbegin();
        }
    };
    int j=0;
    for(int i=0;i<n;i++){
        if(i<m-1){
            add(arr[i]);
        }else{
            add(arr[i]);
             cout<<median()<<" ";
             erase(arr[j]);
            j++;
        }
    }
    cout<<endl;
   return 0;
}