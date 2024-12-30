// Problem : Building Roads

#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty())
    {
        int currnode = q.front(); 
        q.pop();
        for(auto next_node : adj[currnode])
        {
            if(!vis[next_node])
            {
                vis[next_node] = 1;
                q.push(next_node);
            }
        }
    }
}

void count_connected_components(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    vector<int> new_component_nodes;

    int cnt = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == 0)
        {
            cnt++;
            new_component_nodes.push_back(i);
            bfs(i, adj, vis);
        }
    }

    cout<<cnt - 1<<endl;
    for(int i = 0; i < new_component_nodes.size() - 1; i++)
    {
        cout<<new_component_nodes[i]<<" "<<new_component_nodes[i + 1]<<endl;
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    count_connected_components(n, adj);

    return 0;
}

// Explanation :

// we need to find the number of additional connections required
// to connect all the individual connected components such that
// it forms one large fully connected component
// to do this count the numebr of connected components
// return this as the final answer