#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
int f(int n)
{
    n++;
    int cir,cnt,tmp,res = 0;
    for (int i = 0; i < 60; i++)
    {
        cir = 1LL << (i + 1);
        tmp = n / cir;
        cnt = tmp * (cir >> 1);
        tmp = n - tmp * cir;
        cnt += max(0LL,tmp - (cir >> 1));
        res |= (cnt & 1) << i;
    }
    return res;
}
signed main()
{
    scanf("%lld",&n);
    if (n == 1 || n == 2)
        return printf("2"),0;
    else if (n == 3)
        return printf("0"),0;
    int ans;
    if (n & 1)
    {
        n = (n - 1) >> 1;
        ans = f(n) << 2;
        if (n & 1)
            ans |= 0b10;
        ans ^= 0b110;
    }
    else
    {
        n = n >> 1;
        ans = f(n) << 2;
        ans ^= 0b110;
    }
    printf("%lld",ans);
    return 0;
}