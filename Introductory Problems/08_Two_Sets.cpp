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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a=n*(n+1)/2;
    if(a%2==0){
        vector<int> st1;
        vector<int> st2;
        if(n%2==0){
            int i=1,j=n;
            bool flag=true;
            while(i<j){
                if(flag){
                   st1.pb(i);
                   st1.pb(j);
                }else{
                   st2.pb(i);
                   st2.pb(j);
                }
                flag=!flag;
                 i++;j--;
            }
        }else{
            st1.pb(n);
            int i=1,j=n-1;
            bool flag=false;
            while(i<j){
                if(flag){
                   st1.pb(i);
                   st1.pb(j);
                }else{
                   st2.pb(i);
                   st2.pb(j); 
                }
                i++;j--;
                flag=!flag;
            }
        }
        cout<<"YES"<<endl;
        cout<<st1.size()<<endl;
        print(st1);
        cout<<st2.size()<<endl;
        print(st2);
    }else{
        cout<<"NO"<<endl;
    }
}