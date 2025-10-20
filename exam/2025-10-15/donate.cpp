#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int m,cntb,sumb;
struct{int cnt,sum;}tree[maxn << 3];
#define ls rt << 1
#define rs rt << 1 | 1
void upd(int pos,int x,int l = -1e6,int r = 1e6,int rt = 1)
{
    tree[rt].cnt += x;
    tree[rt].sum += pos * x;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
}
int que_kth(int k,int l = -1e6,int r = 1e6,int rt = 1)
{
    if (l == r)
        return k * l;
    int mid = (l + r) >> 1,tmp = tree[rs].cnt;
    if (k > tmp)
        return tree[rs].sum + que_kth(k - tmp,l,mid,ls);
    else
        return que_kth(k,mid + 1,r,rs);
}
#undef ls
#undef rs
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    int op,x,y;
    while (m--)
    {
        cin >> op;
        if (op == 3)
            cout << sumb + que_kth(cntb) << '\n';
        else
        {
            cin >> x >> y;
            if (op == 1)
                upd(x,y);
            else
            {
                cntb += y;
                sumb += x * y;
                upd(-x,y);
            }
        }
    }
    return 0;
}