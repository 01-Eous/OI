#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n;
int fa[maxn],pre[maxn],cnt[maxn],dep[maxn],nxt[maxn];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
signed main()
{
    scanf("%d",&n);
    iota(fa + 1,fa + n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",pre + i);
        dep[i] = dep[pre[i]] + 1;
        nxt[pre[i]] += i;
        cnt[pre[i]]++;
    }
    for (int i = 0; i <= n; i++)
        if (cnt[i] == 1)
            fa[nxt[i]] = i;
    int u;
    while (scanf("%d",&u) != EOF)
    {
        printf("%d\n",dep[find(u)]);
        while (u && !cnt[u])
        {
            cnt[pre[u]]--;
            nxt[pre[u]] -= u;
            u = pre[u];
        }
        if (cnt[u] == 1)
            fa[nxt[u]] = u; 
    }
    return 0;
}