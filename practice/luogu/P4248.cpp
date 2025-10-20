#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n;
char s[maxn];
int rht[maxn],lft[maxn];
int sa[maxn],rnk[maxn],arr[maxn],buc[maxn],hei[maxn];
void get_sa()
{
    int cnt = 30;
    for (int i = 1; i <= n; i++)
        buc[rnk[i] = s[i] - 'a' + 1]++;
    for (int i = 1; i <= cnt; i++)
        buc[i] += buc[i - 1];
    for (int i = n; i >= 1; i--)
        sa[buc[rnk[i]]--] = i;
    for (int w = 1; ; w <<= 1)
    {
        for (int i = 1; i <= w; i++)
            arr[i] = n - i + 1;
        for (int i = 1,idx = w; i <= n; i++)
            if (sa[i] > w)
                arr[++idx] = sa[i] - w;
        // 到这里相当于已经把第二关键字排好了
        memset(buc,0,sizeof(int) * (cnt + 5));
        for (int i = 1; i <= n; i++)
            buc[rnk[arr[i]]]++;
        for (int i = 1; i <= cnt; i++)
            buc[i] += buc[i - 1];
        for (int i = n; i >= 1; i--)
            sa[buc[rnk[arr[i]]]--] = arr[i];
        cnt = 0;
        for (int i = 1; i <= n; i++)
            arr[sa[i]] = rnk[sa[i]] == rnk[sa[i - 1]] && rnk[sa[i] + w] == rnk[sa[i - 1] + w] ? cnt : ++cnt;
        memcpy(rnk,arr,sizeof(int) * (n + 1));
        if (cnt == n)
            break;
    }
}
void get_hei()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (rnk[i] == 1)
        {
            k = 0;
            goto Nahida;
        }
        if (k)
            k--;
        while (s[i + k] == s[sa[rnk[i] - 1] + k])
            k++;
        Nahida:
        hei[rnk[i]] = k;
    }
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    get_sa(),get_hei();
    stack<int,vector<int>> stk;
    stk.push(1);
    for (int i = 2; i <= n; i++)
    {
        rht[i] = n + 1;
        while (hei[stk.top()] > hei[i])
        {
            rht[stk.top()] = i;
            stk.pop();
        }
        lft[i] = stk.top();
        stk.push(i);
    }
    int ans = n * (n - 1) * (n + 1) / 2;
    for (int i = 2; i <= n; i++)
        ans -= (i - lft[i]) * (rht[i] - i) * hei[i] * 2;
    printf("%lld",ans);
    return 0;
}