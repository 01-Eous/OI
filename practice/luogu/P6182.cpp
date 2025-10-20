#include<bits/extc++.h>
using namespace std;
const int maxn = 8e4 + 5;
int n;
int stk[maxn],top;
int root[maxn],pre[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char op;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 'a')
        {
            cin >> x;
            stk[++top] = x;
            root[i] = top;
            pre[root[i]] = root[i - 1];
        }
        else if (op == 's')
            root[i] = pre[root[i - 1]];
        else
        {
            cin >> x;
            root[i] = root[x - 1];
        }
        cout << (root[i] ? stk[root[i]] : -1) << '\n';
    }
    return 0;
}