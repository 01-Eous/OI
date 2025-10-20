#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],b[maxn];
int pos[maxn],nxt[maxn],st[maxn],top;
vector<pair<int,int>> ans;
struct Nahida{int l,r,val;}tree[maxn << 2];
void push_up(int rt){tree[rt].val = tree[ls].val + tree[rs].val;}
void build(int l,int r,int rt = 1)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].val = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int pos,int x,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
    {
        tree[rt].val += x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,ls);
    else
        upd(pos,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(ql,qr,ls);
    if (qr > mid)
        res += que(ql,qr,rs);
    return res;
}
void solve()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        b[i] = a[i];
    }
    build(1,n);
    ans.clear(),top = 0;
    sort(b + 1,b + n + 1);
    memset(nxt,0,sizeof nxt);
    memset(pos,0,sizeof pos);
    int idxa = n,k = 1;
    for (int idxb = 1; idxb <= n; idxb++)
    {
        if (pos[b[idxb]])
        {
            if (pos[b[idxb]] == top)
                ans.push_back({2,1});
            else
            {
                int tmp = que(pos[b[idxb]] + 1,top);
                if (!tmp)
                    ans.push_back({2,1});
                else
                {
                    k = 2;
                    ans.push_back({3,tmp});
                    ans.push_back({2,1});
                    ans.push_back({4,tmp});
                }
            }
            upd(pos[b[idxb]],-1);
            pos[b[idxb]] = nxt[pos[b[idxb]]];
        }
        else
        {
            int tmp = 1;
            while (idxa && a[idxa] != b[idxb])
            {
                st[++top] = idxa;
                nxt[top] = pos[a[idxa]];
                pos[a[idxa--]] = top;
                upd(top,1),tmp++;
            }
            ans.push_back({1,tmp});
            ans.push_back({2,1});
            idxa--;
        }
    }
    printf("%lld\n%llu\n",k,ans.size());
    for (auto &[op,val] : ans)
    {
        if (op == 1)
            printf("1 1 %lld\n",val);
        else if (op == 2)
            printf("2 1\n");
        else if (op == 3)
            printf("3 1 2 %lld\n",val);
        else
            printf("3 2 1 %lld\n",val);
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}