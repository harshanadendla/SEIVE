#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e8;

vector<bool> prime(N,true);
vector<int> ans(N);

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
    for(int i=4;i<=N;i+=2)
    {
        prime[i]=false;
    }
	for(int i=3;i*i<=N;i+=2)
	{
		if(prime[i])
		{
			for(int j=i*i;j<=N;j+=i)
			{
				prime[j]=false;
			}
		}
	}
    int k=2;
    ans[1]=2;
	for(int i=3;i<=N;i+=2)
	{
		if(prime[i])
		{
			ans[k++]=i;
		}
	}
    for(int i=1;i<k;i+=100)
    {
        cout<<ans[i]<<"\n";
    }
	return 0;
}