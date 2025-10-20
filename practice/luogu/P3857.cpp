#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m,cnt;
int d[55];
char s[55];
void ins(int x)
{
    for (int i = 50; i >= 0; i--)
    {
        if (x & (1LL << i))
        {
            if (d[i])
                x ^= d[i];
            else
            {
                cnt++;
                d[i] = x;
                break;
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    while (m--)
    {
        scanf("%s",s);
        int tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += (1LL << n - i) * (s[i] == 'O');
        ins(tmp);
    }
    printf("%lld",(1LL << cnt) % 2008);
    return 0;
}