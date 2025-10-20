#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int maxn = 2.5e5 + 5;
int n,m;
int stk[maxn],top;
int a[maxn],l[maxn],r[maxn],ans[maxn];
vector<int> vec[maxn];
class Klee
{
    private:
    struct Nahida{int l,r,val,tag;}tree[maxn << 2];
    void push_up(int rt){tree[rt].val = min(tree[ls].val,tree[rs].val);}
    void push_down(int rt)
    {
        if (!tree[rt].tag)
            return;
        tree[ls].val += tree[rt].tag,tree[rs].val += tree[rt].tag;
        tree[ls].tag += tree[rt].tag,tree[rs].tag += tree[rt].tag;
        tree[rt].tag = 0;
    }
    public:
    void build(int l,int r,int rt)
    {
        tree[rt].l = l,tree[rt].r = r;
        tree[rt].tag = tree[rt].val = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l,mid,ls);
        build(mid + 1,r,rs);
    }
    void upd(int ql,int qr,int x,int rt = 1)
    {
        if (ql > qr)
            return;
        int l = tree[rt].l,r = tree[rt].r;
        if (ql <= l && r <= qr)
        {
            tree[rt].val += x;
            tree[rt].tag += x;
            return;
        }
        push_down(rt);
        int mid = (l + r) >> 1;
        if (ql <= mid)
            upd(ql,qr,x,ls);
        if (qr > mid)
            upd(ql,qr,x,rs);
        push_up(rt);
    }
    int que(int ql,int qr,int rt = 1)
    {
        if (ql > qr)
            return inf;
        int l = tree[rt].l,r = tree[rt].r;
        if (ql <= l && r <= qr)
            return tree[rt].val;
        push_down(rt);
        int mid = (l + r) >> 1,res = inf;
        if (ql <= mid)
            res = min(res,que(ql,qr,ls));
        if (qr > mid)
            res = min(res,que(ql,qr,rs));
        return res;
    }
}t1;
pii operator+(const pii &x,const pii &y)
{
    if (x.first > y.first)
        return x;
    else if (x.first < y.first)
        return y;
    return {x.first,min(x.second,y.second)};
}
class Klee
{
    private:
    struct Nahida{int l,r;pii val;}tree[maxn << 2];
    void push_up(int rt){tree[rt].val = tree[ls].val + tree[rs].val;}
    public:
    void build(int l,int r,int rt)
    {
        tree[rt].l = l,tree[rt].r = r;
        if (l == r)
        {
            tree[rt].val = {a[l],l};
            return;
        }
        int mid = (l + r) >> 1;
        build(l,mid,ls);
        build(mid + 1,r,rs);
        push_up(rt);
    }
    pii que(int ql,int qr,int rt = 1)
    {
        if (ql > qr)
            return {-inf,0};
        int l = tree[rt].l,r = tree[rt].r;
        if (ql <= l && r <= qr)
            return tree[rt].val;
        int mid = (l + r) >> 1;
        pii res = {-inf,0};
        if (ql <= mid)
            res = res + que(ql,qr,ls);
        if (qr > mid)
            res = res + que(ql,qr,rs);
        return res;
    }
}t2;
void calc1()
{
    t1.build(1,n,1);
    stk[top = 0] = 1;
    for (int i =  1; i <= n; i++)
        vec[i].clear();
    for (int i = 1; i <= m; i++)
        vec[r[i]].push_back(i);
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] < a[i])
        {
            t1.upd(stk[top - 1],stk[top] - 1,-a[stk[top]] + a[i]);
            top--;
        }
        stk[++top] = i;
        if (i > 1)
            t1.upd(i - 1,i - 1,a[i - 1] + a[i]);
        for (auto id : vec[i])
        {
            pii tmp = t2.que(l[id],r[id]);
            int ra = tmp.second;
            if (ra + 1 < i)
                ans[id] = min(ans[id],tmp.first + t1.que(ra + 1,i - 1));
        }
    }
}
void calc2()
{
    for (int i = 1; i <= m; i++)
        ans[i] = min(ans[i],a[l[i]] + a[r[i]] + t2.que(l[i] + 1,r[i] - 1).first);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];
    memset(ans,0x3f,sizeof ans);
    t2.build(1,n,1);
    calc1(),calc2();
    reverse(a + 1,a + n + 1);
    for (int i = 1; i <= m; i++)
    {
        int tl = l[i],tr = r[i];
        r[i] = n - tl + 1;
        l[i] = n - tr + 1;
    }
    t2.build(1,n,1);
    calc1();
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}