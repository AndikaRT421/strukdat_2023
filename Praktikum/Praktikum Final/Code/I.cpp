#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V amount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

    int bfs(int start)
    {
        queue<int> q;
        q.push(start);
        vector<int> dist(vertexCount, 0);
        vector<bool> visited(vertexCount, false);
        visited[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto vertex : adjList[curr])
            {
                if (!visited[vertex])
                {
                    visited[vertex] = true;
                    dist[vertex] = dist[curr] + 1;
                    q.push(vertex);
                }
                else if (vertex == start) return dist[curr] + 1;
            }
        }
        return -1;
    }
};

int main()
{
    int N, ruang1, ruang2;
    cin >> N >> ruang1 >> ruang2;
    graph g;
    g.init(N + 1);
    while (ruang1 != -1 && ruang2 != -1)
    {
        g.add_edge(ruang1, ruang2);
        cin >> ruang1 >> ruang2;
    }
    for (int i = 0; i < N; i++)
    {
        int langkah = g.bfs(i);
        if (langkah == -1) cout << "gak bisa pulang mamah" << endl;
        else cout << langkah << endl;
    }

    return 0;
}
