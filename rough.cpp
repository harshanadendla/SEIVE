#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
const int N=1e6+1;
const int mod=1e9+7;

int t,n,q,type,l,r;
int seg[4*N],a[N],lpf[N];
bool vis[N];


void pre()
{
    for(int i=0;i<N;i++)
    {
        lpf[i]=i;
        vis[i]=false;
    }

    for(int i=2;i<N;i+=2)
    {
        lpf[i]=2;
        vis[i]=true;
    }

    for(int i=3;i*i<N;i+=2)
    {
        if(!vis[i])
        {
            lpf[i]=i;
            vis[i]=true;
            for(int j=i*i;j<N;j+=i)
            {
                if(!vis[j])
                {
                    lpf[j]=i;
                    vis[j]=true;
                }
            }
        }
    }
}

void build(int node,int start,int end)
{
    if(start>end) return ;
    if(start==end)
    {
        seg[node]=lpf[a[start]];
        return ;
    }

    int mid=start+(end-start)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    seg[node]=max(seg[2*node],seg[2*node+1]);
}

int query(int node,int treeStart,int treeEnd,int queryStart,int queryEnd)
{
    if(queryEnd<treeStart || queryStart>treeEnd || treeEnd<treeStart) return 1;
    
    if(treeStart>=queryStart && treeEnd<=queryEnd)
    {
        return seg[node];
    }

    int q1=1,q2=1;
    int mid=treeStart+(treeEnd-treeStart)/2;
    if(seg[2*node] != 1) q1=query(2*node,treeStart,mid,queryStart,queryEnd);
    if(seg[2*node+1] != 1) q2=query(2*node+1,mid+1,treeEnd,queryStart,queryEnd);
    return max(q1,q2);
}

void update(int node,int treeStart,int treeEnd,int updateStart,int updateEnd)
{
    if(treeStart>treeEnd || treeStart>updateEnd || treeEnd<updateStart) return;
    if(treeStart==treeEnd)
    {
        a[treeStart]=a[treeStart]/lpf[a[treeStart]];
        seg[node]=lpf[a[treeStart]];
        return ;
    }

    int mid=treeStart+(treeEnd-treeStart)/2;
    if(seg[2*node] != 1) update(2*node,treeStart,mid,updateStart,updateEnd);
    if(seg[2*node+1] != 1) update(2*node+1,mid+1,treeEnd,updateStart,updateEnd);
    seg[node]=max(seg[2*node],seg[2*node+1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //o0badboy0o

    pre();
    for(int i=1;i<=30;i++) cout<<lpf[i]<<" ";

    // cin>>t;
    // while(t--)
    // {
    //     cin>>n>>q;
    //     for(int i=1;i<=n;i++)
    //     {
    //         cin>>a[i];
    //     }
    //     build(1,1,n);

    //     while(q--)
    //     {
    //         cin>>type>>l>>r;
    //         if(type)
    //         {
    //             cout<<query(1,1,n,l,r)<<" ";
    //         }
    //         else
    //         {
    //             update(1,1,n,l,r);
    //         }
    //     }
    //     cout<<"\n";
    // }

    return 0;
}