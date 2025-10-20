#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,nn;
int a[maxn],num[maxn],b[maxn],pos[maxn];
vector<int> apr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[i] = a[i];
    }
    sort(num + 1,num + n + 1);
    nn = unique(num + 1,num + n + 1) - num - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(num + 1,num + nn + 1,a[i]) - num;
        apr[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        int tmp = lower_bound(num + 1,num + nn + 1,b[i]) - num;
        if (num[tmp] != b[i])
            return cout << "No",0;
        b[i] = tmp;
    }
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[p])
        {
            pos[p++] = i;
            if (p > m)
                break;
        }
    }
    if (p <= m)
        return cout << "No",0;
    pos[m + 1] = n + 1;
    for (int i = m; i >= 1; i--)
    {
        auto l = lower_bound(apr[b[i]].begin(),apr[b[i]].end(),pos[i]);
        auto r = lower_bound(apr[b[i]].begin(),apr[b[i]].end(),pos[i + 1]) - 1;
        if (r - l + 1 >= 2)
            return cout << "Yes",0;
        pos[i] = *r;
    }
    cout << "No";
    return 0;
}