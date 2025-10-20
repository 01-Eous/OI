#include<bits/extc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
using namespace std;
const int maxn = 2e4 + 5;
int n,m;
int a[maxn];
vector<int>b1,b2,tb1,tb2;
inline void upd(int &k)
{
    k++;
    b1[a[k]]++;
    b2[a[k]]--;
    b2[a[(k << 1) - 1]]++;
    b2[a[k << 1]]++;
}
inline void nxt(int &idx)
{
    while (!tb2[idx])
        idx++;
}
signed main()
{
    scanf("%d%d",&m,&n);
    b1.resize(m + 5),b2.resize(m + 5);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    int k = 1,ans = 0,idx;
    b1[a[1]]++;
    b2[a[2]]++;
    do
    {
        tb1 = b1,tb2 = b2;
        idx = 1;
        nxt(idx);
        for (int i = 1; i <= m; i++)
        {
            if (!tb1[i])
                continue;
            if (idx <= i)
                goto ed;
            while (idx <= m)
            {
                int tmp = min(tb1[i],tb2[idx]);
                tb1[i] -= tmp;
                tb2[idx] -= tmp;
                nxt(idx);
                if (!tb1[i])
                    break;
            }
            if (tb1[i])
                goto ed;
        }
        ans = max(ans,k);
        ed:upd(k);
    } while (k << 1 <= n);
    printf("%d",ans);
    return 0;
}
/*
好诶，是休息日
*/