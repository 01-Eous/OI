#include<bits/extc++.h>
#define bound(x,y) (x >= 1 && y >= 1 && x <= n && y <= m)
using namespace std;
const int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,-1,1,1,-1,-1,-1};
int n,m;
int f[1005][1005];
char mp[1005][1005];
int dfs(int x,int y)
{
    if (f[x][y])
        return f[x][y];
    f[x][y] = 1;
    int res = 0;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (bound(tx,ty) && mp[tx][ty] - mp[x][y] == 1)
            res = max(res,dfs(tx,ty));
    }
    return f[x][y] += res;
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%s",mp[i] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!f[i][j])
                ans = max(ans,dfs(i,j));
    printf("%d",ans);
    return 0;
}