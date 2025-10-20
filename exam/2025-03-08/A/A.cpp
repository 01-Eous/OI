// 沟槽的数数题
#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;
int n,m;
int a[maxn],suf[maxn],fa[maxn << 1];
void read(int &x)
{
    int f = 1; x = 0;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    if (x == y)
        return;
    else if (x > y)
        swap(x,y);
    fa[y] = x;
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        m = max(m,a[i]);
    }
    suf[n + 1] = inf;
    for (int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1],a[i]);
    iota(fa + 1,fa + m + 1,1);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (suf[i + 1] < a[i])
            ans = ans * min(a[i] - find(a[i]) + 1,a[i] - suf[i + 1]) % mod;
        else
            ans = ans * (a[i] - find(a[i]) + 1) % mod;
        merge(a[i],a[i] + 1);
    }
    printf("%lld\n",ans);
    return 0;
}