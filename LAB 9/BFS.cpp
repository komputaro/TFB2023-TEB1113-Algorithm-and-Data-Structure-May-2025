#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int V = 5;
char vertices[V] = { 'A', 'B', 'C', 'D', 'E' };

void bfs(int graph[V][V], int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from " << vertices[start] << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << vertices[current] << " ";

        for (int i = 0; i < V; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    // Adjacency matrix
    int graph[V][V] = {
        // A  B  C  D  E
        { 0, 1, 1, 1, 0 }, // A
        { 1, 0, 0, 1, 1 }, // B
        { 1, 0, 0, 1, 0 }, // C
        { 1, 1, 1, 0, 1 }, // D
        { 0, 1, 0, 1, 0 }  // E
    };

    bfs(graph, 0); // Start BFS from vertex A (index 0)

    return 0;
}
