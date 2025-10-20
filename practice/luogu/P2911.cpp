#include<bits/extc++.h>
using namespace std;
int a,b,c;
int cnt[85];
signed main()
{
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                cnt[i + j + k]++;
    cout << max_element(cnt + 1,cnt + 81) - cnt;
    return 0;
}