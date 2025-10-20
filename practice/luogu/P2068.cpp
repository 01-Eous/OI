#include<bits/extc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int tree[maxn];
void upd(int i,int x)
{
    for (; i <= n; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret += tree[i];
    return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    char op;
    int a,b;
    while (q--)
    {
        cin >> op >> a >> b;
        if (op == 'x')
            upd(a,b);
        else
            cout << que(b) - que(a - 1) << '\n';
    }
    return 0;
}