#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e5 + 5;
int n;
int tree[maxn];
pii a[maxn],b[maxn],c[maxn];
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i; i -= lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    int res = 0;
    for (; i <= n; i += lowbit(i))
        res += tree[i];
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
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a + 1,a + n + 1);
    sort(b + 1,b + n + 1);
    for (int i = 1; i <= n; i++)
        c[i] = {a[i].second,b[i].second};
    sort(c + 1,c + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += que(c[i].second);
        upd(c[i].second,1);
    }
    cout << ans % 99999997;
    return 0;
}