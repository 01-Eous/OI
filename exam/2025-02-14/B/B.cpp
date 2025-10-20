#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,p[maxn],pos[maxn];
struct Nahida{int pre,nxt,fa;bool flag;}a[maxn];
void add(int x)
{
    a[a[x].pre].nxt = x;
    a[a[x].nxt].pre = x;
}
void del(int x)
{
    a[a[x].pre].pre = a[x].pre;
    a[a[x].nxt].nxt = a[x].nxt;
}
int find(int x){return a[x].flag ? a[x].fa = find(a[x].fa) : x;}
signed main()
{
    scanf("%lld",&n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",p + i);
        pos[p[i]] = i,ans += (i - 1) * (n - i + 1);
        a[i].pre = i - 1,a[i].nxt = a[i].fa = i + 1;
    }
    for (int i = 1; i <= n; i++)
        del(pos[i]);
    for (int i = n; i >= 1; i--)
    {
        int x = pos[i];
    }
    return 0;
}