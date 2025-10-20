#include<bits/extc++.h>
using namespace std;
int n,m;
bool vis[55];
signed main()
{
    scanf("%d%d",&n,&m);
    printf("YES\n%d\n",m << 1);
    int x,y;
    while (m--)
    {
        scanf("%d%d",&x,&y);
        vis[x] = vis[y] = 1;
        printf("%d %d ",x,y);
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                printf("%d ",i);
        putchar('\n');
        for (int i = n; i >= 1; i--)
            if (!vis[i])
                printf("%d ",i);
        printf("%d %d\n",x,y);
        vis[x] = vis[y] = 0;
    }
    return 0;
}