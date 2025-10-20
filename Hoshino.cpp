#include<bits/extc++.h>
using namespace std;
int n,k;
int pos[15];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        pos[i] = i;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (pos[j] + 1 != pos[j + 1])
            {
                pos[j]++;
                break;
            }
            pos[j] = j;
        }
    }
    for (int i = pos[k]; i > 0; i--)
    {
        if (pos[k] == i)
            cout << '1',k--;
        else
            cout << '0';
    }
    return 0;
}