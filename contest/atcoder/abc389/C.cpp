#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int q;
int head[maxn],len[maxn];
int leave,llen,tot;
signed main()
{
    scanf("%lld",&q);
    int op,l;
    while (q--)
    {
        scanf("%lld",&op);
        if (op == 1)
        {
            scanf("%lld",&l);
            head[tot + 1] = head[tot] + len[tot];
            len[tot + 1] = l;
            tot++;
        }
        else if (op == 3)
        {
            scanf("%lld",&l);
            l += leave;
            printf("%lld\n",head[l] - llen);
        }
        else
        {
            leave++;
            llen += len[leave];
        }
    }
    return 0;
}