#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Graph {
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int V) {
        vertices = V;
        adjacencyList.resize(V);
    }

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    vector<int> rute_terpendek(int start, int end) {
        vector<bool> visited(vertices, false);

        queue<vector<int>> q;
        q.push({start});
        visited[start] = true;

        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();

            int lastVertex = path.back();

            if (lastVertex == end)
                return path;

            for (int neighbor : adjacencyList[lastVertex]) {
                if (!visited[neighbor]) {
                    vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                    visited[neighbor] = true;
                }
            }
        }

        return {};
    }
};

int main() {
    int N, E;
    cin >> N >> E;

    Graph graph(N);

    while (E--) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u - 1, v - 1);
    }

    int start = 0; 
    int end = N - 1; 

    vector<int> rute = graph.rute_terpendek(start, end);

    if (rute.empty()) {
        cout << "RIP LAPET 2023" << endl;
    } else {
        cout << rute.size() << endl;
        for (int vertex : rute) {
            cout << vertex + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
