#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        if(x>y){
            long long high=x*x;
            long long low=((x-1)*(x-1));
            if(x&1){
                cout<<low+y<<"\n";
            }else{
                cout<<high-y+1<<"\n";
            }
        }else{
            long long high=y*y;
            long long low=((y-1)*(y-1));
            if(y&1){
                cout<<high-x+1<<"\n";
            }else{
                cout<<low+x<<"\n";
            }
        }
    }
 
    return 0;
}
