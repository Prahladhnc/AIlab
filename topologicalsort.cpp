#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stk, vector<vector<int>>& adj) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stk, adj);
        }
    }

    stk.push(v);
}

void topologicalSort(int vertices, vector<vector<int>>& adj) {
    stack<int> stk;
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stk, adj);
        }
    }

    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Topological Sorting Order: ";
    topologicalSort(vertices, adj);

    return 0;
}
