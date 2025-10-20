#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,m,cnt;
int a[maxn],root[maxn];
struct Nahida{int lson,rson,val;}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].val += x;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
int que(int u,int v,int l,int r,int ql,int qr)
{
    if (ql <= l && r <= qr)
        return tree[v].val - tree[u].val;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(tree[u].lson,tree[v].lson,l,mid,ql,qr);
    if (qr > mid)
        res += que(tree[u].rson,tree[v].rson,mid + 1,r,ql,qr);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        root[i] = upd(a[i],1,1e9,root[i - 1]);
    }
    cin >> m;
    int l,r;
    while (m--)
    {
        cin >> l >> r;
        int _max = 0,ans = 0,sum;
        while (1)
        {
            sum = que(root[l - 1],root[r],1,1e9,_max + 1,ans + 1);
            if (!sum)
                break;
            _max = ans + 1;
            ans += sum;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}