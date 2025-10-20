#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
using pii = pair<int,int>;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 3.5e4 + 5;
int n,m,q,len,cnt;
int p1[maxn],p2[maxn];
int pw2(int x)
{return (ll)p2[(x) / len] * p1[(x) % len] % mod;}
struct Nahida
{
    bool tag;
    int len,sum,hsh,lson,rson;
    void tag_down()
    {
        tag ^= 1;
        sum = len - sum;
        hsh = pw2(len) - 1 - hsh;
    }
}tree[(int)1.2e7];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void init()
{
    len = sqrt(mod) + 1;
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= len; i++)
        p1[i] = (ll)p1[i - 1] * 2 % mod;
    for (int i = 1; i <= len; i++)
        p2[i] = (ll)p2[i - 1] * p1[len] % mod;
}
void push_up(int rt)
{
    tree[rt].sum = tree[ls].sum + tree[rs].sum;
    tree[rt].hsh = ((ll)pw2(tree[rs].len) * tree[ls].hsh % mod + tree[rs].hsh) % mod;
}
void push_down(int rt)
{
    if (!tree[rt].tag)
        return;
    tree[ls].tag_down();
    tree[rs].tag_down();
    tree[rt].tag = 0;
}
void upd(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].tag_down();
    int mid = (l + r) >> 1;
    if (!ls)
        tree[ls = ++cnt].len = mid - l + 1;
    if (!rs)
        tree[rs = ++cnt].len = r - mid;
    push_down(rt);
    if (ql <= mid)
        upd(ql,qr,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,mid + 1,r,rs);
    push_up(rt);
}
int que_sum(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt].sum;
    if (!ls && !rs)
    {
        if (!tree[rt].sum)
            return 0;
        int mi = max(ql,l);
        int mx = min(qr,r);
        return mx - mi + 1;
    }
    int mid = (l + r) >> 1,res = 0;
    push_down(rt);
    if (ql <= mid)
        res += que_sum(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que_sum(ql,qr,mid + 1,r,rs);
    return res;
}
pii que_hsh(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return {tree[rt].len,tree[rt].hsh};
    if (!ls && !rs)
    {
        pii res;
        int mi = max(ql,l);
        int mx = min(qr,r);
        res.first = mx - mi + 1;
        if (!tree[rt].sum)
            res.second = 0;
        else
            res.second = pw2(res.first) - 1;
        return res;
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    bool fl = 0;
    pii res;
    if (ql <= mid)
    {
        fl = 1;
        res = que_hsh(ql,qr,l,mid,ls);
    }
    if (qr > mid)
    {
        pii tmp = que_hsh(ql,qr,mid + 1,r,rs);
        if (!fl)
            res = tmp;
        else
        {
            res.first += tmp.first;
            res.second = ((ll)res.second * pw2(tmp.first) % mod + (ll)tmp.second) % mod;
        }
    }
    return res;
}
signed main()
{
    init();
    n = read(),m = read(),q = read();
    tree[cnt = 1].len = n;
    int u,v,k;
    while (m--)
    {
        u = read(),v = read();
        upd(u,v);
    }
    while (q--)
    {
        u = read(),v = read(),k = read();
        if (que_sum(u,v) >= k)
        {
            printf("%d\n",pw2(k) - 1);
            continue;
        }
        int l = u,r = v,mid,res = 0,ans = 0;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (que_sum(u,mid) + (v - mid) >= k)
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        int tmp;
        if (res)
            tmp = que_sum(u,res);
        else
            tmp = 0;
        if (res)
            ans = (ll)(pw2(tmp) - 1) * pw2(k - tmp) % mod;
        else
            res = u - 1;
        ans = ((ll)ans + (ll)que_hsh(res + 1,v).second + mod) % mod;
        printf("%d\n",ans);
    }
    return 0;
}