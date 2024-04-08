

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a=arr[0];
    long long ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]<=a){
            ans+=(a-arr[i]);
        }else{
            a=arr[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}