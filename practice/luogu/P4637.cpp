#include<bits/extc++.h>
using namespace std;
int n;
int lb[4005],rb[4005];
struct Klee{int id,x,d;}a[4005];
bool operator<(const Klee &x,const Klee &y){return x.x < y.x;}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].d;
        a[i].id = i;
    }
    sort(a + 1,a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        lb[i] = a[i].x - a[i].d;
        rb[i] = a[i].x + a[i].d;
        int lp = i,rp = i;
        while (1)
        {
            bool fl = 0;
            if (lp > 1 && a[lp - 1].x > lb[i])
            {
                fl = 1,lp--;
                lb[i] = min(lb[i],a[lp].x - a[lp].d);
            }
            if (rp < n && a[rp + 1].x < rb[i])
            {
                fl = 1,rp++;
                rb[i] = max(rb[i],a[rp].x + a[rp].d);
            }
            if (!fl)
                break;
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (lb[j] <= a[i].x && a[i].x <= rb[j])
                cnt++;
        ans += 1.0 / cnt;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}