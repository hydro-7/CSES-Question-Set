#include <bits/stdc++.h>
using namespace std;

vector<int> isBipartite(int V, vector<int> adj[]) {

    vector<int> color(V, -1);
    
    queue<int> q;
    
    for(int i = 0; i < V; i++) {

        if(color[i] == -1) {

            color[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                for(auto v : adj[u]) {

                    if(color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        return {};
                    }
                }
            }
        }
    }
    
    return color;
}

int main() {

    int n, m;
    cin>>n>>m;
    vector<int> adj[n + 1];
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> v = isBipartite(n + 1, adj);
    if(v.size() == 0) cout<<"IMPOSSIBLE";
    else for(int i = 1; i < v.size(); i++) cout<<v[i] + 1<<" ";
    cout<<endl;
    
    return 0;
}