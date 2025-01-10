// Problem : Labytinth

#include<bits/stdc++.h>
using namespace std;

struct triple{
    int first;
    int second;
    string third;
};
 
void shortestPath(int i, int j, int n, int m, vector<string>&x, vector<vector<triple>>&parent, queue<pair<int,int>>&bfs){
    vector<int>dy = {-1, 0, 1, 0};
    vector<int>dx = {0, -1, 0, 1};
    vector<char>dir = {'U', 'L', 'D', 'R'};
 
    while(!bfs.empty()){
        pair<int,int>p = bfs.front(); bfs.pop();
 
        for (int k=0; k<4; k++){
            int ni = p.first + dy[k];
            int nj = p.second + dx[k];
 
            if (ni>=0 && ni<n && nj>=0 && nj<m && x[ni][nj]!='#' && !(ni==i && nj==j)){
                if (parent[ni][nj].third.empty()){
                    parent[ni][nj].first=p.first;
                    parent[ni][nj].second=p.second;
                    parent[ni][nj].third=dir[k];
                    bfs.emplace(ni,nj);
                }
            }
        }
    }
}
 
void solve(){
    int n,m; cin>>n>>m;
    vector<string>x(n);
    for (int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<triple>> parent(n, vector<triple>(m,{NULL,NULL,""}));
    queue<pair<int,int>>bfs;
    pair<int,int>end={};
    pair<int,int>start={};
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (x[i][j]=='A'){
                bfs.push({i,j});
                shortestPath(i,j,n,m,x,parent,bfs);
            }
            if (x[i][j]=='B') end={i,j};
        }
    }
    if (parent[end.first][end.second].third.size()!=0) {
        cout << "YES" << endl;
        string path = "";
        while (start!=end){
            path+=parent[end.first][end.second].third;
            end={parent[end.first][end.second].first,parent[end.first][end.second].second};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path;
    }
    else{
        cout << "NO";
    }
}

int main()
{
    solve();
    return 0;
}

// you are trying to move from A (start) to B(end) using a 
// trail of '.' characters. i will use a basic bfs traversal 
// starting from the point A trying to look for an ideal path
// at every step pass a current string of the path taken till
// the current step.
