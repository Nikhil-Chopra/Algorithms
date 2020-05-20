#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(),v.end()
ll ver[10009]={0};
void init(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        ver[i]=i;
    }
}

ll root(ll x)
{
    while(ver[x]!=x)
    {
        ver[x]=ver[ver[x]];
        x=ver[x];
    }
    return x;
}

void unite(ll x,ll y)
{
    ll root_x=root(x);
    ll root_y=root(y);
    ver[root_x]=ver[root_y];
}

ll krus(vector<pair<ll,pair<ll,ll>>> p,ll edges)
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            unite(x, y);
        }    
    }
    return minimumCost;
    
}

int main()
{
    ll vec,ede;
    cin>>vec>>ede;
    ll k=ede;
    init(vec);
    vector<pair<ll,pair<ll,ll>>> v;
    ll a,b,we;
    while(ede--)
    {
        cin>>a>>b>>we;
        v.push_back({we,{a,b}});
    }
    sort(all(v));
    cout<<krus(v,k);
    return 0;
}
