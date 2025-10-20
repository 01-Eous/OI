#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
void solve()
{
    scanf("%lld",&n);
    queue<int> q;
    q.push(0),q.push(0),q.push(0);
    int cnt = 0;
    while (q.front() < n)
    {
        int x = q.front();
        q.pop();
        x = min(n,q.front() << 1 | 1);
        q.push(x);
        cnt++;
    }
    printf("%lld\n",cnt);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}