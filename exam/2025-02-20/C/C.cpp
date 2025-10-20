#include<bits/extc++.h>
using namespace std;
int n;
int gcd(int x,int y)
{
    if (y == 0)
        return x;
    else if (x < y)
        return gcd(y,x);
    else
        return gcd(y,x % y);
}
int lcm(int x,int y){return x * y / gcd(x,y);}
signed main()
{
    scanf("%d",&n);
    int cnt = 0;
    for (int k = 1; k < (1 << n); k++)
    {
        int _gcd = 0,_lcm = 0;
        bool fl = 0;
        for (int i = 1; i <= n; i++)
        {
            if (k & (1 << (i - 1)))
            {
                _gcd = gcd(_gcd,i);
                if (_lcm == 0)
                    _lcm = i;
                else
                    _lcm = lcm(_lcm,i);
                if (_lcm > n)
                {
                    fl = 1;
                    break;
                }
            }
        }
        if (!fl && _gcd == 1 && _lcm == n)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}