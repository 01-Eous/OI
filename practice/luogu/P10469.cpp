#include<bits/extc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n,cnt;
char str[maxn];
int sa[maxn],rnk[maxn],arr[maxn],buc[maxn],hei[maxn];
int id(char ch){return ch - 'a' + 1;}
void get_sa()
{
    cnt = n != 30 ? 30 : 29;
    for (int i = 1; i <= n; i++)
        buc[rnk[i] = id(str[i])]++;
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
        memset(buc,0,sizeof(int) * (cnt + 1));
        for (int i = 1; i <= n; i++)
            buc[rnk[arr[i]]]++;
        for (int i = 1; i <= cnt; i++)
            buc[i] += buc[i - 1];
        for (int i = n; i >= 1; i--)
            sa[buc[rnk[arr[i]]]--] = arr[i];
        cnt = 0;
        for (int i = 1; i <= n; i++)
            arr[sa[i]] = rnk[sa[i]] == rnk[sa[i - 1]] && rnk[sa[i] + w] == rnk[sa[i - 1] + w] ? cnt : ++cnt;
        memcpy(rnk,arr,sizeof(int) * (n + 5));
        if (cnt == n)
            break;
    }
}
void get_hei()
{
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (k)
            k--;
        while (str[i + k] == str[sa[rnk[i] - 1] + k])
            k++;
        hei[rnk[i]] = k;
    }
}
signed main()
{
    scanf("%s",str + 1);
    n = strlen(str + 1);
    get_sa();
    for (int i = 1; i <= n; i++)
        printf("%d%c",sa[i] - 1," \n"[i == n]);
    get_hei();
    for (int i = 1; i <= n; i++)
        printf("%d%c",hei[i]," \n"[i == n]);
    return 0;
}