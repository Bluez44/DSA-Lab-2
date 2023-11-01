// Research queue which is implemented in C library at http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.

// Using queue, complete function bool isBipartite(vector<vector<int>> graph) to determine if a graph is bipartite or not (the graph can be disconnected). In caat https://en.wikipedia.org/wiki/Bipartite_graph.

// You can use below liberaries in this question.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;    

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> color(n, -1); 
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[curr]) {
                        return false; 
                    }
                }
            }
        }
    }

    return true; 
}
