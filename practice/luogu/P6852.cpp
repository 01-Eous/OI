#include<bits/extc++.h>
using namespace std;
const int maxn =  5e5 + 5;
int n,m;
bool vis[maxn];
int sum[maxn],ans[maxn];
int lmu[maxn],rmu[maxn];
int lban[maxn],rban[maxn];
stack<int,vector<int>> stk;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        lmu[i] = rban[i] = 0;
        rmu[i] = lban[i] = n;
    }
    int l,r,x;
    while (m--)
    {
        cin >> l >> r >> x;
        if (x)
        {
            lmu[x - 1] = max(lmu[x - 1],l);
            rmu[x - 1] = min(rmu[x - 1],r);
        }
        else
            sum[l]++,sum[r + 1]--;
        lban[x] = min(lban[x],l);
        rban[x] = max(rban[x],r);
    }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    for (int i = n - 1; ~i; i--)
    {
        lmu[i] = max(lmu[i],lmu[i + 1]);
        rmu[i] = min(rmu[i],rmu[i + 1]);
        if (lmu[i] > rmu[i])
            return cout << "-1",0;
    }
    for (int i = lmu[0]; i <= rmu[0]; i++)
        if (!sum[i])
            stk.push(i),vis[i] = 1;
    if (stk.empty())
        return cout << "-1",0;
    ans[stk.top()] = 0,stk.pop();
    for (int i = lmu[0]; i <= rmu[0]; i++)
        if (!vis[i])
            stk.push(i),vis[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (lban[i] <= rban[i])
        {
            for (int j = lmu[i]; j < lban[i] && j <= rmu[i] && !vis[j]; j++)
                stk.push(j),vis[j] = 1;
            for (int j = rmu[i]; j > rban[i] && j >= lmu[i] && !vis[j]; j--)
                stk.push(j),vis[j] = 1;
        }
        if (stk.empty() || (lban[i] <= stk.top() && stk.top() <= rban[i]))
            return cout << "-1",0;
        ans[stk.top()] = i,stk.pop();
        for (int j = max(lmu[i],lban[i]); j <= rmu[i] && !vis[j]; j++)
            stk.push(j),vis[j] = 1;
        for (int j = min(rmu[i],rban[i]); j >= lmu[i] && !vis[j]; j--)
            stk.push(j),vis[j] = 1;
    }
    for (int i = 0; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}