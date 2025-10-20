#include<bits/extc++.h>
using namespace std;
const int maxn = 1.0001e7 + 5;
int idx;
int pr[maxn];
bool ipr[maxn];
bool chk(int x)
{
    while (x)
    {
        if (x % 10 == 7)
            return 0;
        x /= 10;
    }
    return 1;
}
void init(int n = 1.0001e7)
{
    for (int i = 1; i <= n; i++)
    {
        if (ipr[i])
            continue;
        if (!chk(i))
            for (int j = i; j <= n; j += i)
                ipr[j] = 1;
        else
            pr[++idx] = i;
    }
    fprintf(stderr,"%d\n%.3lf",pr[idx],clock() / (double)CLOCKS_PER_SEC);
}
signed main()
{
    init();
    int t,x;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        if (ipr[x])
            puts("-1");
        else
            printf("%d\n",*upper_bound(pr + 1,pr + idx + 1,x));
    }
    return 0;
}