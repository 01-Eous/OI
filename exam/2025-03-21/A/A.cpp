// 我的努力，不如天才的 1%
#include<bits/extc++.h>
using namespace std;
int n,w;
int a[3005],pos[3005];
vector<vector<int>> ans;
bool check()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i)
            return 0;
    return 1;
}
void upd()
{
    for (int i = 1; i <= n; i++)
        pos[a[i]] = i;
}
void spwn(vector<int> &vec)
{
    for (int i = 1; i <= n; i++)
    {
        int j = i + 1;
        while (j <= n && a[j] == a[j - 1] + 1)
            j++;
        vec.push_back(j - i);
        if (j > n)
            break;
        else if (pos[a[i] - 1] < i)
        {
            i = j - 1;
            continue;
        }
        vec.push_back(pos[a[i] - 1] - j + 1);
        i = pos[a[i] - 1];
    }
    ans.push_back(vec);
}
void swp(vector<int> &vec)
{
    vector<vector<int>> tmp;
    int idx = 0;
    for (auto len : vec)
    {
        tmp.push_back(vector<int>());
        while (idx < n && len--)
            tmp.back().push_back(a[++idx]);
    }
    idx = 0;
    for (int i = tmp.size() - 1; i >= 0; i--)
        for (auto j : tmp[i])
            a[++idx] = j;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (!check())
    {
        vector<int> tmp;
        upd();
        spwn(tmp);
        swp(tmp);
    }
    cout << ans.size();
    for (auto &vec : ans)
    {
        cout << '\n' << vec.size();
        for (auto i : vec)
            cout << ' ' << i;
    }
    return 0;
}