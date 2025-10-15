#include <bits/stdc++.h>
using namespace std;
long long maxEdges(int n, vector<pair<int, int>> edges)
{
    // Write your code here.

    // 采用临接表的方法构建图
    vector<vector<int>> graph(n + 1);
    for(const auto &edge:edges){
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 采用dfs对树的节点染色,将节点分成两组
    vector<int> color(n + 1, -1);
    long long black = 0, white = 0;

    // 从节点1开始染色
    queue<int> q;
    q.push(1);
    color[1] = 0; //0黑,1白
    ++black;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for (int neighbor:graph[node]){
            if(color[neighbor]  == -1){
                color[neighbor] = 1 - color[node];
                if(color[neighbor] == 0){
                    ++black;
                }else{
                    ++white;
                }
                q.push(neighbor);
            }
        }
    }

    // 计算最大可能边数
    long long maxPossibleEdges = black * white;

    // 减去已存在的边数

    long long existingEdges = edges.size();

    return maxPossibleEdges - existingEdges;
}