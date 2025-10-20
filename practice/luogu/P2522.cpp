#include<bits/extc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e4 + 5;
int idx,a,b,c,d,k;
bool ipr[maxn];
int pr[maxn],mo[maxn],sum[maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void init(int n = 5e4)
{
    mo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!ipr[i])
        {
            mo[i] = -1;
            pr[++idx] = i;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
            mo[i * pr[j]] = -mo[i];
        }
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + mo[i];
}
int calc(int x,int y)
{
    int n = min(x,y),res = 0;
    for (int l = 1,r; l <= n; l = r + 1)
    {
        r = min(x / (x / l),y / (y / l));
        res += (x / ((ll)l * k)) * (y / ((ll)l * k)) * (sum[r] - sum[l - 1]);
    }
    return res;
}
void solve()
{
    a = read(),b = read(),c = read(),d = read(),k = read();
    printf("%d\n",calc(b,d) - calc(b,c - 1) - calc(a - 1,d) + calc(a - 1,c - 1));
}
signed main()
{
    init();
    int t = read();
    while (t--)
        solve();
    return 0;
}