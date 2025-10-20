#include<bits/extc++.h>
#define int long long
#define lowbit(x) (x & -x)
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],num[maxn],cnt;
int tree[maxn],ans1[maxn],ans2[maxn];
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[++cnt] = a[i];
    }
    sort(num + 1,num + cnt + 1);
    m = unique(num + 1,num + cnt + 1) - num - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(num + 1,num + m + 1,a[i]) - num;
    for (int i = 1; i <= n; i++)
    {
        upd(a[i],1);
        ans1[i] = i - que(a[i]);
    }
    fill(tree + 1,tree + n + 1,0);
    for (int i = n; i >= 1; i--)
    {
        upd(a[i],1);
        ans2[i] = n - i - que(a[i]) + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += min(ans1[i],ans2[i]);
    cout << ans;
    return 0;
}