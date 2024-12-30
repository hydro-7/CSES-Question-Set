// Problem : Labytinth

#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void find_path(vector<vector<char>> &matrix, int si, int sj)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    vis[si][sj] = 1;
    queue<pair<pair<int, int>, string>> q;
    q.push({{si, sj}, ""});

    string answer = "";
    bool flag = true;

    while(!q.empty() && flag)
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        string s = q.front().second;
        q.pop();

        // traversing neighbours

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<char> dir = {'R', 'L', 'D', 'U'};

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dx[k], nc = c + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == '.' && !vis[nr][nc]) 
            {
                vis[nr][nc] = 1;
                q.push({{nr, nc}, s + dir[k]});
            }
            else if(nr >= 0 && nr < n && nc >= 0 && nc < m && matrix[nr][nc] == 'B')
            {
                answer = s + dir[k];
                flag = false;
                break;
            }
            
        }
    }

    if(answer != "")
    {
        cout<<"YES\n";
        cout<<answer.size()<<endl;
        cout<<answer<<endl;
    }
    else cout<<"NO\n";
    
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<vector<char>> matrix(n, vector<char>(m));

    int starti, startj;

    for(int i = 0;  i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j] == 'A')
            {
                starti = i;
                startj = j;
            }
        }
    }

    

    find_path(matrix, starti, startj);

    return 0;
}

// general idea :

// you are trying to move from A (start) to B(end) using a 
// trail of '.' characters. i will use a basic bfs traversal 
// starting from the point A trying to look for an ideal path
// at every step pass a current string of the path taken till
// the current step.