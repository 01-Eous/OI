#include<bits/extc++.h>
using namespace std;
int x,y;
signed main()
{
    cin >> x >> y;
    int cnt = 0;
    if (x == y)
        cnt++;
    y *= x;
    for (int i = 1; i * i < y; i++)
    {
        if (y % i)
            continue;
        int j = y / i;
        if (__gcd(i,j) == x)
            cnt += 2;
    }
    cout << cnt;
    return 0;
}