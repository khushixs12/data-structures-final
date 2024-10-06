#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int> > adjList; // Adjacency list


    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Depth-First Search (DFS)
    void DFS(int s) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(s);
        visited[s] = true;

        while (!stack.empty()) {
            int u = stack.top();
            stack.pop();

            cout << u << " ";

            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                if (!visited[v]) {
                    stack.push(v); 
                    visited[v] = true;
                }
            }
        }
    }
};

int main() {
    int V, E, u, v, a;
    while (true) {
        cout << "Enter the number of vertices: ";
        cin >> V;

        Graph g(V);

        cout << "Enter the number of edges: ";
        cin >> E;

        cout << "Enter the edges (u v):\n";
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            g.addEdge(u, v);
        }

        cout << "Enter the starting vertex for DFS: ";
        cin >> u;
        cout << "DFS traversal: ";
        g.DFS(u);
        cout << endl;

        cout << "Enter 1 to continue or any other number to exit: ";
        cin >> a;
        if (a != 1) {
            break;
        }
    }
    return 0;
}

