#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n;
char s[maxn];
vector<int> pos[26];
signed main()
{
    scanf("%d%s",&n,s + 1);
    for (int i = 1; i <= n; i++)
        pos[s[i] - 'a'].push_back(i);
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (pos[i].empty())
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (i == j || pos[j].empty())
                continue;
            int sum = -1;
            bool fl = 0;
            auto p1 = pos[i].begin(),p2 = pos[j].begin();
            while (p1 != pos[i].end() || p2 != pos[j].end())
            {
                int tmp1 = p1 != pos[i].end() ? *p1 : inf;
                int tmp2 = p2 != pos[j].end() ? *p2 : inf;
                if (tmp1 < tmp2)
                    sum++,p1++;
                else
                {
                    if (fl)
                        sum--;
                    p2++,fl = 1;
                }
                if (sum < 0)
                    sum = -1,fl = 0;
                ans = max(sum,ans);
            }
        }
    }
    printf("%d",ans);
    return 0;
}