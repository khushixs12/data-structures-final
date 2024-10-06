#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <conio.h>
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
    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> queue;

        queue.push(s);
        visited[s] = true;

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();

            cout << u << " ";

            for (int i = 0; i < adjList[u].size(); i++) {
    int v = adjList[u][i];
    if (!visited[v]) {
        queue.push(v);
        visited[v] = true;
    }
}
            }
        }
};

int main() {
    int V, E, u, v,a;
	up:
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


    cout << "Enter the starting vertex for BFS: ";
    cin >> u;
    cout << "BFS traversal: ";
    g.BFS(u);
    cout << endl;
    cout<<"Enter 1 to continue:";
    cin>>a;
    if(a==1)
    {
    	goto up;
	}
	getch();
    return 0;
}
