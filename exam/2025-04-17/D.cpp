#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n,m,k,cnt;
int a[maxn],b[maxn];
int mp[maxn],vis[maxn];
bool chk(int x,int y){return a[x] + b[y] <= k;}
int toint(int x,int y){return (x - 1) * m + y;}
bool bound(int x,int y){return 1 <= x && x <= n && 1 <= y && y <= m;}
void dfs(int x,int y)
{
    vis[toint(x,y)] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (bound(tx,ty) && !vis[toint(tx,ty)] && chk(tx,ty))
            dfs(tx,ty);
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int j = 1; j <= m; j++)
        scanf("%d",b + j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[toint(i,j)] && chk(i,j))
                cnt++,dfs(i,j);
    printf("%d",cnt);
    return 0;
}
// g++ Klee.cpp -o Klee.exe -g -std=c++14 -fsanitize=address,undefined