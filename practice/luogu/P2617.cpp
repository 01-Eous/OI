#include<cstdio>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int len = 450,blo;
int a[maxn],id[maxn];
vector<int>blk[maxn];
void init()
{
    for (int i = 1; i <= n; i++)
    {
        id[i] = (i - 1) / len + 1;
        blk[id[i]].push_back(a[i]);
    }
    blo = id[n];
    for (int i = 1; i <= blo; i++)
        sort(blk[i].begin(),blk[i].end());
}
void upd(int pos,int x)//sqrt(n)
{
    a[pos] = x;
    blk[id[pos]].clear();
    int st = (id[pos] - 1) * len + 1;
    int en = id[pos] * len;
    for (int i = st; i <= en; i++)
        blk[id[pos]].push_back(a[i]);
    sort(blk[id[pos]].begin(),blk[id[pos]].end());
}
int check(int ql,int qr,int x)
{
    int lid = id[ql],rid = id[qr],ret = 0;
    if (lid == rid)
    {
        for (int i = ql; i <= qr; i++)
            ret += (a[i] <= x);
        return ret;
    }
    for (int i = ql; id[i] == lid; i++)
        ret += (a[i] <= x);
    for (int i = qr; id[i] == rid; i--)
        ret += (a[i] <= x);
    for (int i = lid + 1; i <= rid - 1; i++)
    {
        if (blk[i].front() > x)
            continue;
        if (blk[i].back() <= x)
        {
            ret += len;
            continue;
        }
        ret += upper_bound(blk[i].begin(),blk[i].end(),x) - blk[i].begin();
    }
    return ret;
}
int que_min(int ql,int qr)
{
    int lid = id[ql],rid = id[qr],ret = inf;
    if (lid == rid)
    {
        for (int i = ql; i <= qr; i++)
            ret = min(ret,a[i]);
        return ret;
    }
    for (int i = ql; id[i] == lid; i++)
        ret = min(ret,a[i]);
    for (int i = qr; id[i] == rid; i--)
        ret = min(ret,a[i]);
    for (int i = lid + 1; i <= rid - 1; i++)
        ret = min(ret,blk[i].front());
    return ret;
}
int que_max(int ql,int qr)
{
    int lid = id[ql],rid = id[qr],ret = -inf;
    if (lid == rid)
    {
        for (int i = ql; i <= qr; i++)
            ret = max(ret,a[i]);
        return ret;
    }
    for (int i = ql; id[i] == lid; i++)
        ret = max(ret,a[i]);
    for (int i = qr; id[i] == rid; i--)
        ret = max(ret,a[i]);
    for (int i = lid + 1; i <= rid - 1; i++)
        ret = max(ret,blk[i].back());
    return ret;
}
int que(int ql,int qr,int k)
{
    int l = que_min(ql,qr);
    int r = que_max(ql,qr);
    int mid,ret = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(ql,qr,mid) >= k)
        {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}
signed main()
{
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    init();
    char op[5];
    int l,r,k;
    while (q--)
    {
        scanf("%s%d%d",op,&l,&r);
        if (op[0] == 'Q')
        {
            scanf("%d",&k);
            printf("%d\n",que(l,r,k));
        }
        else
            upd(l,r);
    }
    return 0;
}