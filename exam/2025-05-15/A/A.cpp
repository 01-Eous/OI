#include<bits/extc++.h>
using namespace std;
const int maxn = 1 << 15 | 5;
const char dict[] = "PRS";
const vector<int> base[] = {
    {0,1,0,2},
    {0,1,1,2},
    {0,2,1,2},
};
int n,m,tim;
int num[3];
vector<int> ans;
void append(vector<int> &src,const vector<int> &val)
{
    for (auto i : val)
        src.push_back(i);
}
void spawn(int id,int pos)
{
    if (!pos)
        return append(ans,base[id]);
    for (auto i : base[id])
        spawn(i,pos - 1);
}
void solve()
{
    cin >> num[1] >> num[0] >> num[2];
    n = __lg(m = num[0] + num[1] + num[2]);
    if (m <= 2)
    {
        if (*max_element(num,num + 3) == 2)
            return (void)(cout << "-1\n");
        for (int i = 0; i < 3; i++)
            if (num[i])
                cout << dict[i];
        cout << '\n';
        return;
    }
    tim = 0,ans.clear();
    while (n >= 2)
    {
        n -= 2,tim++;
        int tmp = 1 << n;
        num[0] -= tmp,num[1] -= tmp,num[2] -= tmp;
        if (*min_element(num,num + 3) < 0)
            return (void)(cout << "-1\n");
    }
    if (*max_element(num,num + 3) == 2)
        return (void)(cout << "-1\n");
    for (int i = 0; i < 3; i++)
        if (num[i])
            spawn(i,tim - 1);
    for (auto i : ans)
        cout << dict[i];
    cout << '\n';
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