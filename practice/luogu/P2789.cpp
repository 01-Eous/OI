#include<bits/extc++.h>
using namespace std;
int n;
unordered_set<int> st;
void dfs(int n,int cnt)
{
    if (!n)
        return (void)st.insert(cnt);
    for (int i = 1; i <= n; i++)
        dfs(n - i,cnt + i * (n - i));
}
signed main()
{
    cin >> n;
    dfs(n,0);
    cout << st.size();
    return 0;
}