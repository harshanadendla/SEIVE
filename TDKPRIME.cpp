#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e8;

vector<bool> prime(N,true);
vector<int> query(N);

void pre()
{
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
    query[1]=2;
	for(int i=3;i<=N;i+=2)
	{
		if(prime[i])
		{
			query[k++]=i;
		}
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);
	pre();
	int q,k;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		cout<<query[k]<<"\n";
	}
	return 0;
}