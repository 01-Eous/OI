#include<iostream>
using namespace std;
int n,a,b,i,j,x;int main(){cin>>n;for(i=1;i<=n;i++){for(j=1,a=1e9;j<=n;j++)cin>>x,a=min(a,x);b=max(b,a);}cout<<b;}