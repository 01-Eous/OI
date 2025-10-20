#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int cnt;
int a[5],b[5],tmp[5];
bool chk1()
{
    if (cnt >= 2)
        return 1;
    int add = inf,mul = inf;
    bool fla = 0,flm = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (a[i] == b[i])
            continue;
        if (add == inf && mul == inf)
        {
            add = b[i] - a[i];
            fla = 1;
            if (a[i] && b[i] % a[i] == 0)
            {
                mul = b[i] / a[i];
                flm = 1;                
            }
        }
        else
        {
            if (flm && a[i] && b[i] % a[i] == 0 && b[i] / a[i] == mul)
                flm = 1;
            else
                flm = 0;
            if (fla && b[i] - a[i] == add)
                fla = 1;
            else
                fla = 0;
        }
    }
    return fla || flm;
}
bool chk2()
{
    if (cnt >= 1)
        return 1;
    for (int k = 1; k <= 3; k++)
        tmp[k] = a[k];
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i & (1 << (j - 1)))
            {
                int add = b[j] - a[j],mul = inf;
                for (int k = 1; k <= 3; k++)
                    if (i & (1 << (k - 1)))
                        a[k] += add;
                if (chk1())
                    return 1;
                for (int k = 1; k <= 3; k++)
                    a[k] = tmp[k];
                if (a[j] && b[j] % a[j] == 0)
                {
                    mul = b[j] / a[j];
                    for (int k = 1; k <= 3; k++)
                        if (i & (1 << (k - 1)))
                            a[k] *= mul;
                    if (chk1())
                        return 1;
                }
                for (int k = 1; k <= 3; k++)
                    a[k] = tmp[k];
            }
        }
    }
    for (int k = 1; k <= 3; k++)
        tmp[k] = b[k];
    for (int i = 1; i < 8; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i & (1 << (j - 1)))
            {
                int add = b[j] - a[j],mul = inf;
                bool fl = 0;
                for (int k = 1; k <= 3; k++)
                    if ((i >> (j - 1)) & 1)
                        b[k] -= add;
                if (chk1())
                    return 1;
                for (int k = 1; k <= 3; k++)
                    b[k] = tmp[k];
                if (a[j] && b[j] % a[j] == 0)
                {
                    mul = b[j] / a[j];
                    for (int k = 1; k <= 3; k++)
                    {
                        if (i & (1 << (k - 1)))
                        {
                            if (mul && b[k] % mul)
                            {
                                fl = 1;
                                break;
                            }
                            if (mul)
                                b[k] /= mul;
                            else if (!mul && b[k])
                            {
                                fl = 1;
                                break;
                            }
                        }
                    }
                    if (!fl && chk1())
                        return 1;
                }
                for (int k = 1; k <= 3; k++)
                    b[k] = tmp[k];
            }
        }
    }
    int l = 0,r = 0;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (a[i] != a[j])
                l = i,r = j;
    if (!l || !r || (b[l] - b[r]) % (a[l] - a[r]))
        return 0;
    int x = (b[l] - b[r]) / (a[l] - a[r]),y = b[l] - x * a[l];
    return a[6 - l - r] * x + y == b[6 - l - r];
}
void solve()
{
    cnt = 0;
    for (int i = 1; i <= 3; i++)
        scanf("%lld",a + i);
    for (int i = 1; i <= 3; i++)
    {
        scanf("%lld",b + i);
        cnt += a[i] == b[i];
    }
    if (cnt == 3)
        puts("0");
    else if (chk1())
        puts("1");
    else if (chk2())
        puts("2");
    else
        puts("3");
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}