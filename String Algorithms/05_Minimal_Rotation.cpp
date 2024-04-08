
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
    string s;
    cin>>s;
    int n = s.length();
    s += s;
    
    int i = 0, j = 1, k = 0;
    while (i + k < 2 * n && j + k < 2 * n) {
        if (s[i + k] == s[j + k]) {
            k++;
            continue;
        }
        if (s[i + k] > s[j + k]) {
            i = max(i + k + 1, j + 1);
        } else {
            j = max(j + k + 1, i + 1);
        }
        k = 0;
    }
    
    cout<<s.substr(min(i, j), n)<<endl;
    
   return 0;
}


// without doubling string

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
    string s;
    cin>>s;
    int n = s.length();
    int i = 0, j = 1, k = 0;

    while (i < n && j < n && k < n) {
        int cmp = s[(i + k) % n] - s[(j + k) % n];
        if (cmp == 0) {
            k++;
        } else {
            if (cmp > 0)
                i += k + 1;
            else
                j += k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    
    cout<<s.substr(min(i, j), n)+s.substr(0,min(i,j))<<endl;
   return 0;
}