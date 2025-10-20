#include<bits/extc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,nn,q;
pii opt[maxn];
int tree[maxn << 2];
int a[maxn],num[maxn << 1];
void upd(int x,int l = 1,int r = nn,int rt = 1)
{
    tree[rt]++;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        upd(x,l,mid,ls);
    else
        upd(x,mid + 1,r,rs);
}
int que(int k,int l = 1,int r = nn,int rt = 1)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1,tmp = tree[rs];
    if (k <= tmp)
        return que(k,mid + 1,r,rs);
    else
        return que(k - tmp,l,mid,ls);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i],num[++nn] = a[i];
    for (int i = 1; i <= q; i++)
    {
        auto &[op,x] = opt[i];
        cin >> op >> x;
        if (op == 2)
            num[++nn] = x;
    }
    sort(num + 1,num + nn + 1);
    nn = unique(num + 1,num + nn + 1) - num - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(num + 1,num + nn + 1,a[i]) - num;
        upd(a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        auto [op,x] = opt[i];
        if (op == 2)
        {
            x = lower_bound(num + 1,num + nn + 1,x) - num;
            upd(x);
        }
        else
            cout << num[que(x)] << '\n';
    }
    return 0;
}