#include<bits/extc++.h>
#define int long long
using namespace std;
int n;
char op1[35],op2[35];
int val1[35],val2[35];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> op1[i] >> val1[i] >> op2[i] >> val2[i];
    int lft = 1,rht = 1,dlt = 0,i = 1;
    while (i <= n)
    {
        if (op1[i] != op2[i])
            break;
        else if (op1[i] == 'x' && val1[i] != val2[i])
            break;
        if (op1[i] == '+')
            dlt += val1[i] + val2[i];
        else
            dlt += (lft + rht + dlt) * (val1[i] - 1);
        i++;
    }
    for (; i <= n; i++)
    {
        if (op1[i] != op2[i])
        {
            if (op1[i] == 'x')
                lft += dlt;
            else
                rht += dlt;
        }
        else if (val1[i] > val2[i])
            lft += dlt;
        else
            rht += dlt;
        dlt = 0;
        if (op1[i] == '+')
            dlt += val1[i];
        else
            dlt += lft * (val1[i] - 1);
        if (op2[i] == '+')
            dlt += val2[i];
        else
            dlt += rht * (val2[i] - 1);
        while (++i <= n)
        {
            if (op1[i] != op2[i])
                break;
            else if (op1[i] == 'x' && val1[i] != val2[i])
                break;
            if (op1[i] == '+')
                dlt += val1[i] + val2[i];
            else
                dlt += (lft + rht + dlt) * (val1[i] - 1);
        }
        i--;
    }
    cout << lft + rht + dlt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}