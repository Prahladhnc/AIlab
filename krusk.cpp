#include <iostream>

#define V 5 // Number of vertices in the graph

int parent[V];
int rank[V];

void makeSet(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find(int v) {
    if (v != parent[v])
        parent[v] = find(parent[v]);
    return parent[v];
}

void Union(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

void kruskalMST(int graph[V][V]) {
    for (int i = 0; i < V; i++)
        makeSet(i);

    int mstEdgeCount = 0;
    int mstWeight = 0;
    int mstEdges[V - 1][3];

    int edgeCount = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                mstEdges[edgeCount][0] = i;
                mstEdges[edgeCount][1] = j;
                mstEdges[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount; i++) {
        int src = mstEdges[i][0];
        int dest = mstEdges[i][1];
        int weight = mstEdges[i][2];

        int srcRoot = find(src);
        int destRoot = find(dest);

        if (srcRoot != destRoot) {
            mstWeight += weight;
            Union(srcRoot, destRoot);
        }
    }

    std::cout << "Edge   Weight" << std::endl;
    for (int i = 0; i < edgeCount; i++) {
        std::cout << mstEdges[i][0] << " - " << mstEdges[i][1] << "    " << mstEdges[i][2] << std::endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    kruskalMST(graph);

    return 0;
}
