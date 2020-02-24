#include <bits/stdc++.h>
using namespace std;
vector<int > x;
bool vis[100009]={false};

void dfs(vector<int> adj[],int s)
{
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
        {
            dfs(adj,adj[s][i]);
        }
    }
    x.push_back(s);
}

int main() {
	int n,q;
	cin>>n>>q;
	int z,y;
	vector<int> adj[n+9];
	for(int i=0;i<q;i++)
	{
	    cin>>z>>y;
	    adj[z].push_back(y);
	}
	/*for(int i=0;i<=n;i++)
	{cout<<i<<" ";
	    for(int j=0;j<adj[i].size();j++)
	    cout<<adj[i][j]<<" ";
	    cout<<"\n";
	}*/
	for(int i=1;i<=n;i++)
	{
	    if(!vis[i])
	    {
	        dfs(adj,i);
	        //cout<<i<<"\t";
	    }
	}
	//cout<<"\n";
	for(int i=x.size()-1;i>=0;i--)
	{
	    cout<<x[i]<<" ";
	}
	return 0;
}



