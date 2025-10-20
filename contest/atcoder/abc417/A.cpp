#include<bits/extc++.h>
using namespace std;
int n,a,b;
string s;
signed main()
{
    cin >> n >> a >> b >> s;
    for (int i = a; i < n - b; i++)
        cout << s[i];
    return 0;
}