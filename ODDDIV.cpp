// ok

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
const int N=1e5;
const int lim=1e4;

int t,k,l,h,start,endp;
vector<int> fact[lim];

int factors(int n)
{
    int f=1;
    int cnt=0;
    while(n%2==0)
    {
        n>>=1;
        cnt++;
    }
    f*=((cnt<<1)+1);
    if(f>=lim) return -1;

    for(int i=3;i*i<=n;i+=2)
    {
        cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        f*=((cnt<<1)+1);
        if(f>=lim) return -1;
    }

    if(n!=1) f*=3;
    if(f>=lim) return -1;
    return f;
}

void pre()
{
    for(int i=1;i<=N;i++)
    {
        int f=factors(i);
        if(f!=-1)
        {
            fact[f].pb(i*i);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();
    for(cin>>t;t--;cout<<"\n")
    {
        cin>>k>>l>>h;
        start=lower_bound(fact[k].begin(),fact[k].end(),l)-fact[k].begin();
        if(start==fact[k].size())
        {
            cout<<"0";
            continue;
        }
        start--;
        endp=upper_bound(fact[k].begin(),fact[k].end(),h)-fact[k].begin();
        if(endp==0)
        {
            cout<<"0";
            continue;
        }
        endp--;
        if(start>endp)
        {
            cout<<"0";
            continue;
        }
        cout<<(endp-start);
    }

    return 0;
}
