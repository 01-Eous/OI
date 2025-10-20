#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,m,nn;
int sum[maxn],num[maxn],tree[maxn];
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i <= nn; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    if (i < 1)
        return 0;
    int res = 0;
    for (; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> sum[i],sum[i] -= m;
    num[++nn] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1],num[++nn] = sum[i];
    sort(num + 1,num + nn + 1);
    nn = unique(num + 1,num + nn + 1) - num - 1;
    upd(lower_bound(num + 1,num + nn + 1,0) - num,1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = lower_bound(num + 1,num + nn + 1,sum[i]) - num;
        ans = (ans + que(sum[i] - 1)) % 92084931,upd(sum[i],1);
    }
    cout << ans;
    return 0;
}