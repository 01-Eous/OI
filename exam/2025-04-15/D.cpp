#include<bits/extc++.h>
#define str basic_string<node>
using namespace std;
int n;
struct node
{
    char ch;
    int cnt;
    friend bool operator<(const node &x,const node &y)
    {return x.ch != y.ch ? x.ch < y.ch : x.cnt < y.cnt;}
    friend bool operator==(const node &x,const node &y)
    {return x.ch == y.ch && x.cnt == y.cnt;}
};
str s,t;
map<str,bool> apr;
void merge(str &s)
{
    while (1)
    {
        bool fl = 1;
        for (int i = 0; i + 2 < s.size(); i++)
        {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
            {
                fl = 0;
                auto [ch,x] = s[i];
                s.erase(i,3);
                s.insert(i,1,{ch,x + 1});
                break;
            }
        }
        if (fl)
            break;
    }
}
void dfs(const str &s)
{
    if (s.empty())
        return;
    apr[s] = 1;
    for (int i = 0; i < s.size(); i++)
    {
        str tmp = s;
        tmp.erase(i,1);
        merge(tmp);
        dfs(tmp);
    }
}
signed main()
{
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> s[i].ch;
    dfs(s);
    cout << apr.size();
    return 0;
}