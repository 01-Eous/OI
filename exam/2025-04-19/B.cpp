// 信自己一回
#include<bits/extc++.h>
using namespace std;
int n;
bool vis[1005];
int a[1005][1005],b[1005][1005];
deque<int> q;
signed main()
{
    scanf("%d",&n);
    if (n & 1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c",(i - j - 1 + n) % n + 1," \n"[j == n - 1]);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < n; j++)
                printf("%d%c",(i - j - 1 + n) % n + 1," \n"[j == n - 1]);
        return 0;
    }
    for (int i = 1; i <= n; i++)
        a[1][i] = i;
    a[2][n] = n;
    for (int i = 2; i <= n; i++)
    {
        while (!q.empty())
            q.pop_back();
        for (int j = 1; j <= n; j++)
            if (!a[i][j])
                q.push_back(a[i - 1][j]);
        int tmp = q.back();
        q.pop_back();
        q.push_front(tmp);
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j])
            {
                a[i][j] = q.front();
                q.pop_front();
            }
        }
        a[i + 1][n - i + 1] = a[i][n - i + 1];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c",a[i][j]," \n"[j == n]);
    memcpy(b,a,sizeof a);
    for (int j = 1; j <= n; j++)
    {
        memset(vis,0,sizeof(bool) * (n + 5));
        for (int i = 1; i <= n; i++)
            vis[b[i][j]] = 1;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                b[n - j + 1][j] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            printf("%d%c",b[i][j]," \n"[j == n]);
    return 0;
}