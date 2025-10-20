#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> iii;
const int maxn = 1e5 + 5;
char *p1,*p2,buf[1 << 23];
int n,m;
int a[maxn];
inline void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
struct Nahida
{
    int tag;
    iii ans;
    pii min1,max1;
    Nahida()
    {
        tag = 0;
        ans = {0,{0,0}};
        min1 = max1 = {0,0};
    }
    Nahida &operator+=(int x)
    {
        tag += x;
        min1.first += x;
        max1.first += x;
        return *this;
    }
    friend Nahida operator+(const Nahida &x,const Nahida &y)
    {
        Nahida res = Nahida();
        res.min1 = min(x.min1,y.min1);
        res.max1 = max(x.max1,y.max1);
        res.ans = max({x.ans,y.ans,{x.max1.first - y.min1.first,{x.max1.second,y.min1.second}}});
        return res;
    }
}tree[maxn << 2];
struct Klee
{
    int lx,rx,ly,ry;
    iii val;
    Klee(int lx,int rx,int ly,int ry):lx(lx),rx(rx),ly(ly),ry(ry){val = {0,{0,0}};};
    friend bool operator<(const Klee &x,const Klee &y){return x.val < y.val;}
};
priority_queue<Klee> q;
inline void push_up(int rt){tree[rt] = tree[ls] + tree[rs];}
inline void push_down(int rt)
{
    if (!tree[rt].tag)
        return;
    tree[ls] += tree[rt].tag;
    tree[rs] += tree[rt].tag;
    tree[rt].tag = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].tag = 0;
    if (l == r)
    {
        tree[rt].min1 = tree[rt].max1 = {a[l],l};
        tree[rt].ans = {0,{l,l}};
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt] += x,void();
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
Nahida que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql > mid)
        return que(ql,qr,mid + 1,r,rs);
    if (qr <= mid)
        return que(ql,qr,l,mid,ls);
    return que(ql,qr,l,mid,ls) + que(ql,qr,mid + 1,r,rs);
}
inline void push(int lx,int rx,int ly,int ry)
{
    Klee res(lx,rx,ly,ry);
    if (lx == ly && rx == ry)
        res.val = que(lx,rx).ans;
    else
    {
        Nahida l = que(lx,rx),r = que(ly,ry);
        res.val = {l.max1.first - r.min1.first,{l.max1.second,r.min1.second}};
    }
    q.push(res);
}
signed main()
{
    read(n),read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1,n,1);
    int op,l,r,x;
    while (m--)
    {
        read(op),read(l),read(r),read(x);
        if (op == 1)
            upd(l,r,x);
        else
        {
            while (!q.empty())
                q.pop();
            push(l,r,l,r);
            int ans = 0;
            while (x--)
            {
                Klee tmp = q.top();
                q.pop();
                auto [lx,rx,ly,ry,val] = tmp;
                ans += val.first;
                auto [tmpl,tmpr] = val.second;
                if (lx == ly && rx == ry)
                {
                    if (lx < tmpl)
                    {
                        push(lx,tmpl - 1,lx,tmpl - 1);
                        push(lx,tmpl - 1,tmpl,rx);
                    }
                    if (tmpl != tmpr)
                        push(tmpl,tmpl,tmpl,tmpl);
                    if (tmpl + 1 <= tmpr - 1)
                        push(tmpl,tmpl,tmpl + 1,tmpr - 1);
                    if (tmpr < rx)
                        push(tmpl,tmpl,tmpr + 1,rx);
                    if (tmpl < rx)
                        push(tmpl + 1,rx,tmpl + 1,rx);
                }
                else
                {
                    if (lx < tmpl)
                        push(lx,tmpl - 1,ly,ry);
                    if (tmpl < rx)
                        push(tmpl + 1,rx,ly,ry);
                    if (ly < tmpr)
                        push(tmpl,tmpl,ly,tmpr - 1);
                    if (tmpr < ry)
                        push(tmpl,tmpl,tmpr + 1,ry);
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}