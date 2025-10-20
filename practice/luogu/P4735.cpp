#include<bits/extc++.h>
#define int long long
#define son(rt,x) tree[rt].ch[x]
using namespace std;
const int maxn = 3e5 + 5;
int n,m,cnt,root[maxn << 1];
struct Nahida{int val,ch[2];}tree[maxn << 6];
void upd(int rt,int ori,int x)
{
    for (int i = 30; i >= 0; i--)
    {
        tree[rt].val = tree[ori].val + 1;
        if (x & (1 << i))
        {
            if (!son(rt,1))
                son(rt,1) = ++cnt;
            son(rt,0) = son(ori,0);
            rt = son(rt,1),ori = son(ori,1);
        }
        else
        {
            if (!son(rt,0))
                son(rt,0) = ++cnt;
            son(rt,1) = son(ori,1);
            rt = son(rt,0),ori = son(ori,0);
        }
    }
    tree[rt].val = tree[ori].val + 1;
}
int que(int ql,int qr,int x)
{
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int dig = (x & (1 << i)) ? 1 : 0;
        if (tree[son(qr,!dig)].val - tree[son(ql,!dig)].val)
        {
            res += (1 << i);
            ql = son(ql,!dig),qr = son(qr,!dig);
        }
        else
            ql = son(ql,dig),qr = son(qr,dig);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1,x; i <= n; i++)
    {
        cin >> x;
        sum ^= x;
        root[i] = ++cnt;
        upd(root[i],root[i - 1],sum);
    }
    char op;
    int ver = n,l,r,x;
    while (m--)
    {
        cin >> op;
        if (op == 'A')
        {
            cin >> x;
            root[++ver] = ++cnt;
            upd(root[ver],root[ver - 1],sum ^= x);
        }
        else
        {
            cin >> l >> r >> x;
            l--,r--;
            if (!l)
                cout << max(sum ^ x,que(root[0],root[r],sum ^ x)) << '\n';
            else
                cout << que(root[l - 1],root[r],sum ^ x) << '\n';
        }
    }
    return 0;
}