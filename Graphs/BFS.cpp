#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>> graph,bool visited[],int start)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;
    cout<<start<<endl;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            if(!visited[i] && graph[x][i] == 1)
            {
                cout<<i<<endl;
                visited[i] = true;
                q.push(i);
            }
        }
    }

}

vector<vector<int>> Graph()
{
    vector<vector<int>> g =  {{0,1,0,0,0,1} ,
                              {1,0,1,1,1,0} ,
                              {0,1,0,0,1,0} ,
                              {0,1,0,0,1,0} ,
                              {0,1,1,1,0,1} ,
                              {1,0,0,0,1,0} };


    return g;                          
}

int main()
{
    vector<vector<int>> graph = Graph();

    bool visited[graph[0].size()];
    for(int i=0;i<graph[0].size();i++)
    {
        visited[i] = false;
    }
    BFS(graph,visited,0);
    return 0;
}
