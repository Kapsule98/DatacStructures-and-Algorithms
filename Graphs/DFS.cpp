#include <bits/stdc++.h>

using namespace std;

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

void DFS(vector<vector<int>> graph,int start,bool visited[])
{
    visited[start] = true;
    cout<<start<<endl;

    for(int i=0;i<graph[start].size();i++)
    {
        if(visited[i] == false && graph[start][i] == 1)
        {
            DFS(graph,i,visited);
        }
    }
}


int main()
{
    vector<vector<int>> graph = Graph();

    bool visited[graph[0].size()];
    for(int i=0;i<graph[0].size();i++)
    {
        visited[i] = false;
    }
    DFS(graph,0,visited);
    return 0;
}
