
// using binary search
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
int binarySearch(vector<pair<int,int>> &arr,int i,int j,int target){
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid].fr==target) return mid;
        if(arr[mid].fr<target){
            i=mid+1;
        }else{
            j=mid-1;
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(n);
     for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i].fr=a;
        arr[i].sc=i;
    }
    sort(all(arr));
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int target=m-arr[i].fr-arr[j].fr;
            int res=binarySearch(arr,j+1,n-1,target);
            if(res!=-1){
            cout<<arr[i].sc+1<<" "<<arr[j].sc+1<<" "<<arr[res].sc+1<<endl;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag){
        cout<<"IMPOSSIBLE";
    }
   return 0;
}


// using two pointer
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
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(n);
     for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i].fr=a;
        arr[i].sc=i;
    }
    sort(all(arr));
    for(int i=0;i<n;i++){
        int target=m-arr[i].fr;
        int j=i+1,k=n-1;
        while(j<k){
            if(arr[j].fr+arr[k].fr==target){
                cout<<arr[i].sc+1<<" "<<arr[j].sc+1<<" "<<arr[k].sc+1;
                return 0;
            }else if(arr[j].fr+arr[k].fr>target){
                k--;
            }else{
                j++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
   return 0;
}