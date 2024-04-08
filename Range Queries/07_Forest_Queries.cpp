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
const ll mod=1000000007;
const long long mod_inverse_2 = 500000004;
const int mxn=200005;
int st[mxn][30];
class FenwickTree2D {
private:
    vector<vector<int>> tree;
    int n, m;

public:
    FenwickTree2D(int rows, int cols) {
        n = rows;
        m = cols;
        tree.assign(n + 1, vector<int>(m + 1, 0));
    }

    void update(int row, int col, int val) {
        for (int i = row; i <= n; i += (i & -i)) {
            for (int j = col; j <= m; j += (j & -j)) {
                tree[i][j] += val;
            }
        }
    }

    int query(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= (i & -i)) {
            for (int j = col; j > 0; j -= (j & -j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int rangeQuery(int row1, int col1, int row2, int col2) {
        return query(row2, col2) - query(row1 - 1, col2) - query(row2, col1 - 1) + query(row1 - 1, col1 - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<string> arr(n);
    input(arr);
    FenwickTree2D ft(n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='*'){
                ft.update(i+1,j+1,1);
            }
        }
    }
    for(int i=0;i<m;i++){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        cout<<ft.rangeQuery(a,b,x,y)<<endl;
    }
   return 0;
}