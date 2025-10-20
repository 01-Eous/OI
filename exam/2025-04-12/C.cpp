#include<bits/extc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
using namespace std;
const int maxn = 3e5 + 5;
char buf[1 << 23],*p1,*p2;
int n,idx,tim,k,cnt;
int w[maxn],head[maxn],root[maxn];
int dfn[maxn],rnk[maxn],fa[maxn],en[maxn];
struct edge{int v,nxt;}e[maxn << 1];
struct Nahida{int val,lson,rson;}tree[maxn * 50];
inline void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline void adde(int u,int v)
{
    e[++idx] = {v,head[u]};
    head[u] = idx;
}
inline void dfs(int u,int pre)
{
    fa[u] = pre;
    dfn[u] = ++tim,rnk[tim] = u;
    for (int i = head[u]; i; i = e[i].nxt)
        if (int v = e[i].v; v != pre)
            dfs(v,u);
    en[u] = tim;
}
inline int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
inline int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].val++;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
inline int que(int ql,int qr,int l,int r,int L,int R)
{
    if (ql <= l && r <= qr)
        return tree[R].val - tree[L].val;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(ql,qr,l,mid,tree[L].lson,tree[R].lson);
    if (qr > mid)
        res += que(ql,qr,mid + 1,r,tree[L].rson,tree[R].rson);
    return res;
}
inline bool chk(int P)
{
    vector<int> vec;
    int sum,tmp,res = 0;
    for (int u = 1; u <= n; u++)
    {
        if (P + w[u] < 0)
            continue;
        vec.clear(),sum = 0;
        tmp = que(0,P + w[u],0,1e6,root[0],root[dfn[u] - 1]) + que(0,P + w[u],0,1e6,root[en[u]],root[n]);
        vec.push_back(tmp),sum += tmp;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (v == fa[u])
                continue;
            tmp = que(0,P + w[u],0,1e6,root[dfn[v] - 1],root[en[v]]);
            vec.push_back(tmp),sum += tmp;
        }
        tmp = P >= 0 ? sum : 0;
        for (auto i : vec)
            tmp += i * (sum -= i);
        if ((res = max(res,tmp)) >= k)
            return 0;
    }
    return 1;
}
signed main()
{
    read(n),read(k);
    for (int i = 1; i <= n; i++)
        read(w[i]);
    for (int i = 1,u,v; i < n; i++)
    {
        read(u),read(v);
        adde(u,v),adde(v,u);
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++)
        root[i] = upd(w[rnk[i]],0,1e6,root[i - 1]);
    int l = -1e6,r = 0,mid,ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (chk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%lld\n",ans);
    fprintf(stderr,"%.4lf",(double)clock() / CLOCKS_PER_SEC);
    return 0;
}