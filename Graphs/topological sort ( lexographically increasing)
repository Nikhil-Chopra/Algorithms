//lexographically increasing
#include <iostream>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>>q;
    vector<int>adj[n+1];
    bool vis[n+1]={false};
    int indeg[n+1]={0};
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0&&vis[i]==false)
        q.push(i);


        while(!q.empty())
        {
            int t=q.top();
            cout<<t<<" ";
            vis[t]=true;
            q.pop();

            for(int i=0;i<adj[t].size();i++)
            {
                indeg[adj[t][i]]--;
                if(indeg[adj[t][i]]==0)
                q.push(adj[t][i]);
            }
        }
    } 
return 0;
}
