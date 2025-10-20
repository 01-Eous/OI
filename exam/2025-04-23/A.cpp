// 神金结论题
#include<bits/extc++.h>
#define int long long
using namespace std;
int x,n,cnt[10];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void solve()
{
    x = read(),n = read();
    if (!n)
        return puts("1"),void();
    memset(cnt,0,sizeof cnt);
    while (x)
    {
        cnt[x % 10]++;
        x /= 10;
    }
    int type = *max_element(cnt,cnt + 10);
    if (type == 3)
        puts("1");
    else if (type == 2)
    {
        if (n == 1)
            puts("7");
        else
            puts("8");
    }
    else
    {
        if (n == 1)
            puts("24");
        else
            puts("27");
    }
}
signed main()
{
    int t = read();
    while (t--)
        solve();
    fprintf(stderr,"%.3lf",1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}