#include <bits/stdc++.h>
#define input(x)      \
    for (auto &a : x) \
    cin >> a
#define print(x)          \
    for (auto &a : x)     \
    {                     \
        cout << a << ' '; \
    }                     \
    cout << "\n";
#define println(x)         \
    for (auto &a : x)      \
    {                      \
        cout << a << '\n'; \
    }
#define fr first
#define sc second
#define ll long long
#define all(v) v.begin(), v.end()
#define ld long double
#define pb push_back
#define mkp make_pair
using namespace std;
const ll mod = 1000000007;
const long long mod_inverse_2 = 500000004;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dir[4] = {'U', 'R', 'D', 'L'};
char  par[1000][1000], ans[1000000];
int  dist[1000][1000];

void printAns(int ex,int ey){
    cout<<"YES"<<endl;
    cout<<dist[ex][ey]<<endl;
    pair<int,int> p={ex,ey};
    for(int i=dist[ex][ey];i>=0;i--){
        ans[i]=par[p.fr][p.sc];
        if(ans[i]=='D') p={p.fr-1,p.sc};
        else if(ans[i]=='U') p={p.fr+1,p.sc};
        else if(ans[i]=='L') p={p.fr,p.sc+1};
        else p={p.fr,p.sc-1};
    }
    for(int i=1;i<=dist[ex][ey];i++){
        cout<<ans[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    input(arr);
    queue<pair<int,int>> monster;
    queue<pair<int,int>> user;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='M'){
                monster.push({i,j});
            }else if(arr[i][j]=='A'){
                user.push({i,j});
            }
        }
    }
    if(user.front().fr==0||user.front().sc==m-1||user.front().fr==n-1||user.front().sc==0){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    while(!user.empty()){
        int size=monster.size();
        for(int i=0;i<size;i++){
            auto aa = monster.front();
            monster.pop();
            int a = aa.fr;
            int b = aa.sc;
              for (int j = 0; j < 4; j++){
                if (a + dx[j] < 0 || a + dx[j] >= n || b + dy[j] < 0 || b + dy[j] >= m||arr[a + dx[j]][b + dy[j]] == '#'||arr[a + dx[j]][b + dy[j]] == 'M') continue;
                    arr[a + dx[j]][b + dy[j]] = 'M';
                    monster.push({a+dx[j],b+dy[j]});
                }
        }
        size=user.size();
        for(int i=0;i<size;i++){
            auto aa = user.front();
            user.pop();
            int a = aa.fr;
            int b = aa.sc;
              for (int j = 0; j < 4; j++){
                   if(arr[a+dx[j]][b+dy[j]]=='#'||arr[a+dx[j]][b+dy[j]]=='M') continue;
                   par[a+dx[j]][b+dy[j]]=dir[j];
                   dist[a+dx[j]][b+dy[j]]=dist[a][b]+1;
                   arr[a+dx[j]][b+dy[j]]='#';
                if (a + dx[j] == 0 || a + dx[j] == n-1 || b + dy[j] == 0 || b + dy[j] == m-1){
                    printAns(a + dx[j],b + dy[j]);
                    return 0;
                  }
                    user.push({a+dx[j],b+dy[j]});
                }
        }
    }
    cout<<"NO"<<endl;
        return 0;
}
