// Research queue which is implemented in C library at: http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.

// Using queue, complete function void bfs(vector<vector<int>> graph, int start) to traverse all the nodes of the graph from given start node using Breadth First Search algorithm and data structure queue, and print the order of visited nodes. 

// You can use below liberaries in this question.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}