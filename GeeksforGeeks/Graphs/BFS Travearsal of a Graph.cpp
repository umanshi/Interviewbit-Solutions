void bfs(int s,vector<int> adj[],bool vis[])
{   
    list<int> q;
    q.push_back(s);
    while(!q.empty())
    {   
        int top = q.front();
        q.pop_front();
        if(!vis[top])
        {
            cout<<top<<" ";
            vis[top] =1;
            for(int i=0; i<adj[top].size(); i++)
            {
                   q.push_back(adj[top][i]);
            }
        }
    }
}
