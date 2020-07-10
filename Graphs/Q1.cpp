/*
Author : Kapil  July 2020
-------------------------------------------------------------
    print all nodes at k level away from a node in graph
-------------------------------------------------------------

*/


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

void BFS(vector<vector<int>> graph,bool visited[],int start,int distance)
{
    queue<pair<int,int>> q;
    pair<int,int> p;
    p.first = start;
    p.second =0;
    q.push(p);
    visited[start] = true;
    while(!q.empty())
    {
        pair<int,int> x = q.front();
        q.pop();
        if(x.second == distance )
        {
            cout<<x.first<<endl;
        }
        for(int i=0;i<graph[x.first].size();i++)
        {
            if(!visited[i] && graph[x.first][i] == 1)
            {
                pair<int,int> k;
                k.first = i;
                k.second = x.second+1;
                visited[i] = true;
                q.push(k);
            }
        }
    }

}

int main()
{
    vector<vector<int>> graph = Graph();
    int start =0 ;
    int distance = 1;
    int count =0;
    bool visited[graph[0].size()];
    for(int i=0;i<graph[0].size();i++)
    {
        visited[i] = false;
    }
    BFS(graph,visited,start,1);
    
    return 0;
}