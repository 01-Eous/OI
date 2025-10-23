#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n;
bool vis[maxn];
int sum[maxn],pre[maxn];
int a[maxn],l[maxn],r[maxn];
void merge(int x,int y)
{
    l[x] = min(l[x],l[y]);
    r[x] = max(r[x],r[y]);
    sum[x] = pre[r[x]] - pre[l[x] - 1];
}
void calc(int x)
{
    if (vis[x])
        return;
    sum[x] = a[x],l[x] = r[x] = x;
    bool fl = vis[x] = 1;
    while (fl)
    {
        fl = 0;
        while (1 < l[x] && sum[x] > a[l[x] - 1])
            fl = 1,calc(l[x] - 1),merge(x,l[x] - 1);
        while (r[x] < n && sum[x] > a[r[x] + 1])
            fl = 1,calc(r[x] + 1),merge(x,r[x] + 1);
    }
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
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        calc(i);
    for (int i = 1; i <= n; i++)
        cout << sum[i] << " \n"[i == n];
    return 0;
}