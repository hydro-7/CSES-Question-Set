// Problem : Counting Rooms

#include<bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &matrix)
{
    vis[i][j] = 1;
    int n = matrix.size(), m = matrix[0].size();
    queue<pair<int, int>> q;

    q.push({i, j});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // traversing neighbours

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dx[k], nc = c + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == '.' && !vis[nr][nc]) 
            {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
            
        }
        
    }
    return ;
    
}

void count_connected_components(vector<vector<char>> matrix)
{
    int ans = 0;
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && matrix[i][j] == '.') // found a new component
            {
                ans++;
                bfs(i, j, vis, matrix); // explore the component
            }
        }
    }

    cout<<ans<<endl;

}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<char>> matrix(n, vector<char>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
        }
    }

    count_connected_components(matrix);

    return 0;
}


// general idea :
//
// we have to count the number of connected components (i.e, rooms)
// in the given grid. i apply BFS over the matrix to look for room 
// elements.