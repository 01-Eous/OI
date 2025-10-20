#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n,m;
int x[maxn],y[maxn];
int tx[maxn],ty[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld",x + i,y + i);
    scanf("%lld",&m);
    int u,v;
    while (m--)
    {
        scanf("%lld%lld",&u,&v);
        memcpy(tx,x,sizeof(int) * (n + 5));
        memcpy(ty,y,sizeof(int) * (n + 5));
        if (!u && !v)
        {
            puts("NO");
            continue;
        }
        else if (!u)
        {
            for (int i = 1; i <= n; i++)
                swap(tx[i],ty[i]);
            swap(u,v);
        }
        if (u < 0)
        {
            for (int i = 1; i <= n; i++)
                tx[i] = -tx[i];
            u = -u;
        }
        map<pii,int> cnt;
        for (int i = 1; i <= n; i++)
        {
            int val = (tx[i] % u + u) % u;
            int tmp = (tx[i] - val) / u;
            tx[i] -= tmp * u,ty[i] -= tmp * v;
            cnt[{tx[i],ty[i]}]++;
        }
        bool fl = 0;
        for (auto [x,y] : cnt)
        {
            if (y & 1)
            {
                fl = 1;
                break;
            }
        }
        if (fl)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
