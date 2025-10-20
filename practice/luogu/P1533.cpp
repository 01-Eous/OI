#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 3e5 + 5;
int n,m,cnt;
int a[maxn],num[maxn],root[maxn];
struct Nahida{int val,lson,rson;}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    tree[cnt].val++;
    return cnt;
}
int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
int que(int ql,int qr,int l,int r,int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int tmp = tree[tree[qr].lson].val - tree[tree[ql].lson].val;
    if (k <= tmp)
        return que(tree[ql].lson,tree[qr].lson,l,mid,k);
    else
        return que(tree[ql].rson,tree[qr].rson,mid + 1,r,k - tmp);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num + 1,num + n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(num + 1,num + n + 1,a[i]) - num;
        root[i] = upd(a[i],1,n,root[i - 1]);
    }
    int l,r,k;
    while (m--)
    {
        cin >> l >> r >> k;
        cout << num[que(root[l - 1],root[r],1,n,k)] << '\n';
    }
    return 0;
}