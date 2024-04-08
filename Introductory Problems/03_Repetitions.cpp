

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    char ch=s[0];
    int count=1;
    int ans=0;
    for(int i=1;i<s.size();i++){
        if(s[i]!=ch){
            ans=max(count,ans);
            ch=s[i];
            count=1;
        }else{
            count++;
        }
    }
     ans=max(count,ans);
    cout<<ans<<endl;

    return 0;
}