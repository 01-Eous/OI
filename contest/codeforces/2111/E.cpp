#include<bits/extc++.h>
using namespace std;
int n,q;
string s;
set<int> st[6];
/*
b a = 1
b c = 2
c a = 3
c b = 4
*/
int id(char x,char y)
{
    if (x == 'b')
    {
        if (y == 'a')
            return 1;
        else
            return 2;
    }
    else
    {
        if (y == 'a')
            return 3;
        else
            return 4;
    }
}
void solve()
{
    st[1].clear(),st[2].clear();
    st[3].clear(),st[4].clear();
    cin >> n >> q >> s;
    char x,y;
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (x == 'a' || x == y)
            continue;
        st[id(x,y)].insert(i);
    }
    for (auto &i : s)
    {
        if (i == 'a')
            continue;
        else if (i == 'b')
        {
            if (!st[1].empty())
            {
                i = 'a';
                st[1].erase(st[1].begin());
            }
            else if (!st[2].empty())
            {
                int tmp = *st[2].begin();
                auto it = st[3].upper_bound(tmp);
                if (it != st[3].end())
                {
                    i = 'a';
                    st[2].erase(st[2].begin());
                    st[3].erase(it);
                }
            }
        }
        else
        {
            if (!st[3].empty())
            {
                i = 'a';
                st[3].erase(st[3].begin());
            }
            else if (!st[4].empty())
            {
                int tmp = *st[4].begin();
                auto it = st[1].upper_bound(tmp);
                if (it != st[1].end())
                {
                    i = 'a';
                    st[4].erase(st[4].begin());
                    st[1].erase(it);
                }
                else
                {
                    i = 'b';
                    st[4].erase(st[4].begin());
                }
            }
        }
    }
    cout << s << '\n';
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