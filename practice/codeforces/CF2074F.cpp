#include<bits/extc++.h>
using namespace std;
int l1,r1,l2,r2;
int que(int l1,int r1,int l2,int r2)
{
    if (l1 == r1 || l2 == r2)
        return 0;
    int res = 0;
    if (l1 & 1)
        l1++,res += r2 - l2;
    if (r1 & 1)
        r1--,res += r2 - l2;
    if (l2 & 1)
        l2++,res += r1 - l1;
    if (r2 & 1)
        r2--,res += r1 - l1;
    return res + que(l1 >> 1,r1 >> 1,l2 >> 1,r2 >> 1);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        cout << que(l1,r1,l2,r2) << '\n';
    }
    return 0;
}