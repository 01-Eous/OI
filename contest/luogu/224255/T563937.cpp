#include<bits/extc++.h>
using namespace std;
int n,x;
vector<int>a,b;
signed main()
{
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        if (x <= 15)
            a.push_back(x);
        else
            b.push_back(x);
    }
    for (auto i : a)
        cout << i << " ";
    for (auto i : b)
        cout << i << " ";
    return 0;
}