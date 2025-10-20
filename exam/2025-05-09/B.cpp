#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
struct Klee
{
    int c,w,f;
    friend bool operator<(const Klee &x,const Klee &y){return x.f > y.f;}
}a[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].c >> a[i].w >> a[i].f;
    sort(a + 1,a + n + 1);
    if (m > 60)
        return cout << a[1].f,0;
    m = 1 << m;
    int p = 1,ans = 0;
    while (p <= n)
    {
        ans += a[p].f;
        for (int i = p,tmp = m; i <= n; i++)
        {
            if (tmp >= a[i].c)
            {
                tmp -= a[i].c;
                a[i].c = 0;
            }
            else
            {
                a[i].c -= tmp;
                tmp = 0;
                break;
            }
        }
        while (!a[p].c)
            p++;
    }
    cout << ans;
    return 0;
}