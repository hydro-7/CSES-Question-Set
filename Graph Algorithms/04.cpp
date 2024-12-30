// Problem : Message Route

#include<bits/stdc++.h>
using namespace std;

void shortest_path(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0);
    string route = "";
    

    queue<pair<int, string>> q;
    q.push({1, ""});
    bool flag = true;

    while(!q.empty() && flag)
    {
        int currnode = q.front().first;
        string currstr = q.front().second;
        q.pop();

        for(auto next_node : adj[currnode])
        {
            if(next_node == n)
            {
                flag = false;
                route = currstr + to_string(next_node) + " ";
                break;
            }
            else if(!vis[next_node])
            {
                vis[next_node] = 1;
                q.push({next_node, currstr + to_string(next_node) + " "});
            }
        }
    }

    if(route == "") cout<<"IMPOSSIBLE\n";
    else{
        int ans = 0;
        for(auto c : route) if(c == ' ') ans++;
        cout<<ans + 1<<endl;
        cout<<"1 ";
        cout<<route<<endl;
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

    shortest_path(n, adj);

    return 0;
}

// Explanation :

// Find the shortest path (if it exists),  
// from a given starting point to an ending point
// also print the number of nodes in that path 

// the first time you encounter the destination
// node in a BFS traversal would be the shortest path
// possible from source to destination. 

