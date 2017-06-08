#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,c;
ll a[100001];
ll fun(ll x)
{
  ll cowsplaced=1,lastpos=a[0];
  for(ll i=1;i<n;i++)
  {
    if(a[i]-lastpos>=x)
    {
      if(++cowsplaced==c)return 1;
      lastpos=a[i];
    }
  }
  return 0;
}
ll BS(ll a[],ll low,ll high)
{
    ll dstart=0;
    ll dist=a[high]-a[low]+1;
    while(dist>dstart)
    {
        ll mid=(dist+dstart+1)/2;
        if(fun(mid))
        {
            dstart=mid;
        }else{
            dist=mid-1;
        }
    }
    return dstart;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j=0;
        cin>>n>>c;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<BS(a,0,n-1)<<endl;
    }
}
