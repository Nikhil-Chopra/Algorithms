// SCC using kosarajus algorithm

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs_stack(vector<ll> v[],stack<ll> &s,bool vis[],ll x)
{
    vis[x]=true;
    for(ll i=0;i<v[x].size();i++)
    {
        if(!vis[v[x][i]])
        {
            dfs_stack(v,s,vis,v[x][i]);
        }
    }
    s.push(x);
}

void dfs(vector<ll> vr[],bool visr[],ll k)
{
    visr[k]=true;
    for(ll  i=0;i<vr[k].size();i++)
    {
        if(!visr[vr[k][i]])
        {
            dfs(vr,visr,vr[k][i]);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll  n,t;
	cin>>n>>t;
	vector<ll> v[n+9],vr[n+9];
	ll x,y;
	for(int i=0;i<t;i++)
	{
	    cin>>x>>y;
	    v[x].push_back(y);
	    vr[y].push_back(x);
	}
	stack<ll> s;
	ll ans=0;
	bool vis[n+9]={false},visr[n+9]={false};
	for(ll i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        dfs_stack(v,s,vis,i);
	    }
	}
	while(s.size())
	{
	    ll q=s.top();
	    s.pop();
	    //cout<<q<<"\n";
	    if(!visr[q])
	    {
	        dfs(vr,visr,q);
	        ans++;
	    }
	}
	cout<<ans;
	return 0;
}
