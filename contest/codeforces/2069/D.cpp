#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,s,t;
char a[maxn];
void solve()
{
    scanf("%s",a + 1);
    n = strlen(a + 1);
    s = 1,t = n;
    while (s < t && a[s] == a[t])
        s++,t--;
    if (s >= t)
    {
        puts("0");
        return;
    }
    basic_string<int>apr1,apr2;
    apr1.resize(26,0),apr2.resize(26,0);
    int mid = (s + t) >> 1,ans = 0;
    for (int i = mid,j = mid + 1; i >= s && j <= t; i--,j++)
    {
        apr1[a[i] - 'a']++;
        apr2[a[j] - 'a']++;
    }
    if (apr1 == apr2)
    {
        for (int i = mid,j = mid + 1; i >= s; i--,j++)
        {
            if (a[i] != a[j])
            {
                ans = i - s + 1;
                break;
            }
        }
    }
    else
    {
        vector<int>d1,d2;
        for (int i = 0; i < 26; i++)
        {
            if (apr1[i] > apr2[i])
            {
                int tmp = (apr1[i] - apr2[i]) >> 1;
                for (int j = mid; j >= s; j--)
                {
                    if (a[j] == i + 'a')
                    {
                        tmp--;
                        if (!tmp)
                        {
                            d1.push_back(mid - j + 1);
                            break;
                        }
                    }
                }
            }
            else if (apr1[i] < apr2[i])
            {
                int tmp = (apr2[i] - apr1[i]) >> 1;
                for (int j = mid + 1; j <= t; j++)
                {
                    if (a[j] == i + 'a')
                    {
                        tmp--;
                        if (!tmp)
                        {
                            d2.push_back(j - mid);
                            break;
                        }
                    }
                }
            }
        }
        int x = *max_element(d1.begin(),d1.end());
        int y = *max_element(d2.begin(),d2.end());
        ans = mid - s + 1 + min(x,y);
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}