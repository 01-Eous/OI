#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n,k,cnt;
bool can[10],vis[maxn];
struct Klee{int dig,pre,val;}pool[maxn];
queue<int> q;
void out(int x)
{
    if (!x)
        return;
    out(pool[x].pre);
    printf("%d",pool[x].dig);
}
signed main()
{
    scanf("%d%d",&n,&k);
    memset(can,1,sizeof(can));
    for (int x; k--;)
    {
        scanf("%d",&x);
        can[x] = 0;
    }
    pool[0] = {0,-1,0};
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = !pool[u].val; i < 10; i++)
        {
            if (!can[i])
                continue;
            int cur = (pool[u].val * 10 + i) % n;
            if (!vis[cur])
            {
                vis[cur] = 1;
                pool[++cnt] = {i,u,cur};
                if (!cur)
                    return out(cnt),0;
                q.push(cnt);
            }
        }
    }
    puts("-1");
    return 0;
}