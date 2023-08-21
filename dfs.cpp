#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> stk;
    stk.push(start);
    visited[start] = true;

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices + 1);
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cin >> startNode;

    vector<bool> visited(vertices + 1, false);
    dfs(startNode, graph, visited);

    return 0;
}
