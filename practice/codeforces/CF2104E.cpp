#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n,k,q;
char t[maxn],s[maxn];
int son[maxn][26],ans[maxn];
signed main()
{
    scanf("%d%d%s",&n,&k,t + 1);
    fill(son[0],son[0] + k,n + 1);
    fill(ans + 1,ans + n + 1,inf);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < k; j++)
            ans[i] = min(ans[i],ans[son[i][j] = son[0][j]] + 1);
        son[0][t[i] - 'a'] = i;
    }
    scanf("%d",&q);
    while (q--)
    {
        scanf("%s",s + 1);
        int rt = 0,len = strlen(s + 1);
        for (int i = 1; i <= len && rt <= n; i++)
            rt = son[rt][s[i] - 'a'];
        printf("%d\n",ans[rt]);
    }
    return 0;
}