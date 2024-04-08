

#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main() {
    long long n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int a=computeXOR(n);
    
    for(int i=0;i<n;i++){
        a^=arr[i];
    }
    cout<<a<<endl;

    return 0;
}