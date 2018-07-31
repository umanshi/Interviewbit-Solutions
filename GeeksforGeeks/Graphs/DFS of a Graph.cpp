void dfsUtil(int s, vector<int> g[], bool vis[])
{   
    cout<<" "<<s;
    vis[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {   
        int n = g[s][i];
        if(!vis[n])
            dfsUtil(n, g, vis);
    }
}
void dfs(int s, vector<int> g[], bool vis[])
{   vis[s] = 1;
    cout<<s;
    for(int i=0; i<g[s].size(); i++)
        {  
            int n = g[s][i];
            if(!vis[n])
                dfsUtil(n, g, vis);
        }
}
