#include<bits/extc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n;
stack<int,vector<int>> stk;
struct circle
{
    int x,r;
    friend bool operator<(const circle &x,const circle &y)
    {
        if (x.x + x.r != y.x + y.r)
            return x.x + x.r < y.x + y.r;
        return x.x - x.r > y.x - y.r;
    }
}a[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].r;
    sort(a + 1,a + n + 1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int cur = a[i].x - a[i].r,sum = 0;
        while (!stk.empty() && a[stk.top()].x - a[stk.top()].r >= cur)
        {
            sum += a[stk.top()].r << 1;
            stk.pop();
        }
        stk.push(i),ans++;
        if (sum == a[i].r << 1)
            ans++;
    }
    cout << ans;
    return 0;
}