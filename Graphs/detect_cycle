#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int dfs(vector<ll> v[],bool vis[],bool visr[],ll k)
{
    visr[k]=true;
    vis[k]=true;
    for(ll  i=0;i<v[k].size();i++)
    {
        if( (!vis[v[k][i]] && dfs(v,vis,visr,v[k][i]))|| visr[v[k][i]]) 
        {
            return 1;
        }
    }
    visr[k]=false;
    return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll  n,t;
	cin>>n>>t;
	vector<ll> v[n+9];
	ll x,y;
	for(int i=0;i<t;i++)
	{
	    cin>>x>>y;
	    v[x].push_back(y);
	}
	bool vis[n+9]={false} ,visr[n+9]={false},m=0;
	for(ll i=1;i<=n;i++)
	{
	    if(!vis[i] && !m) m=dfs(v,vis,visr,i);
	}
	cout<<(m?"1":"0");
	return 0;
}
