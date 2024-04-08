
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
const int n=7;
char s[n*n-1];
bool vis[n][n];
ll mod=1000000007;
class KMP{
    vector<int> lpsArray;
    public:
    KMP(){};
    void lps(string s){
        int len=0,i=1;
        int n=s.length();
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lpsArray[i]=len;
                i++;
            }else{
                if(len==0){
                    i++;
                }else{
                    len=lpsArray[len-1];
                }
            }
        }
    }
    
    int kmp(string s,string p){
        int n=s.length();
        int m=p.length();
        lpsArray.resize(m,0);
        lps(p);
        int j=0,i=0;
        int ans=0;
        while(i<n){
            if(s[i]==p[j]){
                j++;
                i++;
            }
            if(j==m){
                ans++;
                j=lpsArray[j-1];
            }
            if(i<n&&s[i]!=p[j]){
                if(j!=0){
                    j=lpsArray[j-1];
                }else{
                    i++;
                }
            }
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,p;
    cin>>s>>p;
    KMP kp;
    cout<<kp.kmp(s,p)<<endl;
    
   return 0;
}