
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
int dp[5005];
struct TrieNode{
    TrieNode* children[26];
    bool isLeaf=false;
};
class Trie{
    TrieNode* root;
    public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string s){
        TrieNode* cur=root;
        for(auto ch:s){
            if(cur->children[ch-'a']==NULL){
                cur->children[ch-'a']=new TrieNode();
            }
            cur=cur->children[ch-'a'];
        }
        cur->isLeaf=true;
    }
    
    ll search(string s,int i){
        TrieNode* cur=root;
        ll ans=0;
        for(auto ch:s){
           if(cur->children[ch-'a']==NULL){
               break;
           }
           cur=cur->children[ch-'a'];
           if(cur->isLeaf){
               ans=(ans+dp[i+1])%mod;
           }
           i++;
        }
        return ans;
    }
    
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n;
    cin>>s>>n;
    int m=s.length();
    Trie trie;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        trie.insert(x);
    }
    memset(dp,sizeof(dp),0);
    dp[s.length()]=1;
    for(int i=m-1;i>=0;i--){
        dp[i]=trie.search(s.substr(i,m-i),i);
    }
    cout<<dp[0]<<endl;
   return 0;
}