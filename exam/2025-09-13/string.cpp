#include<bits/extc++.h>
using namespace std;
string a,b;
int buc[26];
set<char> st;
void solve()
{
    cin >> a >> b;
    st.clear();
    memset(buc,0,sizeof(buc));
    for (auto ch : a)
    {
        buc[ch - 'a']++;
        st.insert(ch);
    }
    for (auto ch : b)
        st.erase(ch);
    if (st.size() < 2)
    {
        cout << "-1\n";
        return;
    }
    char x = 0,y;
    for (auto ch : st)
    {
        if (buc[ch - 'a'] & 1)
        {
            x = ch;
            break;
        }
    }
    if (x)
    {
        set<char>::iterator it = st.upper_bound(x);
        if (it == st.end())
            x = 0;
        else
            y = *it;
    }
    if (!x)
    {
        y = *--st.end();
        st.erase(--st.end());
        x = *--st.end();
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == x)
        {
            if (!(buc[ch - 'a'] & 1))
                buc[ch - 'a']--;
        }
        else if (ch == y)
            break;
        while (buc[ch - 'a']--)
            cout << ch;
    }
    cout << y << '\n';
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}