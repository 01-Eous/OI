#include<bits/extc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
using namespace std;
const int maxn = 2e5 + 5;
int n;
int p[maxn],tree[maxn];
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
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",p + i);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = que(n) - que(p[i] - 1);
        ans += tmp * (2 * i - tmp - 1) / 2;
        upd(p[i],1);
    }
    cout << ans;
    return 0;
}