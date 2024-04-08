

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
#define mkp make_pair
using namespace std;
ll mod=1000000007;

struct Node{
    int val;
    Node* next;
    
    Node(int v){
        val=v;
        next=nullptr;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Node* root=NULL;
    Node* temp=root;
    for(int i=1;i<=n;i++){
        if(!temp){
            temp=new Node(i);
            root=temp;
        }else{
            temp->next=new Node(i);
            temp=temp->next;
        }
    }
    temp->next=root;
    Node* cur=root;
    while(true){
        cout<<cur->next->val<<" ";
        if(cur->next==cur) break;
        cur->next=cur->next->next;
        cur=cur->next;
    }
   return 0;
}