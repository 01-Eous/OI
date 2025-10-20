#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,q;
int a[maxn];
struct linear_basis
{
    int d[35],pos[35];
    linear_basis()
    {
        memset(d,0,sizeof d);
        memset(pos,0,sizeof pos);
    }
    void ins(const linear_basis &base,int p,int x)
    {
        *this = base;
        for (int i = 30; i >= 0; i--)
        {
            if (x & (1 << i))
            {
                if (!d[i])
                {
                    d[i] = x;
                    pos[i] = p;
                    break;
                }
                else if (pos[i] < p)
                {
                    swap(x,d[i]);
                    swap(p,pos[i]);
                }
                x ^= d[i];
            }
        }
    }
    int que(int l)
    {
        int res = 0;
        for (int i = 30; i >= 0; i--)
            if (pos[i] >= l && (res ^ d[i]) > res)
                res ^= d[i];
        return res;
    }
}ba[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        ba[i].ins(ba[i - 1],i,a[i]);
    }
    scanf("%d",&q);
    int l,r;
    while (q--)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",ba[r].que(l));
    }
    return 0;
}