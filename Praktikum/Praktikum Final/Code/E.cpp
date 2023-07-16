#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V amount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        priority_queue<pair<long, long>> pq;
        result = vector<long>(vertexCount, 0);

        pq.push(make_pair(0, start));

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            long currentVertex = temp.second;
            long currentWeight = -temp.first;

            if (visited[currentVertex])
                continue;

            visited[currentVertex] = true;
            result[currentVertex] = currentWeight;

            for (auto vertex : adjList[currentVertex])
            {
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if (!visited[nextVertex])
                {
                    long newWeight = max(currentWeight, weight);
                    pq.push(make_pair(-newWeight, nextVertex));
                }
            }
        }
    }
};

int main()
{
    graph g;
    int n, m;
    cin >> n >> m;
    g.init(n + 1);

    while (m--)
    {
        int desa1, desa2, bahaya;
        cin >> desa1 >> desa2 >> bahaya;
        g.add_edge(desa1, desa2, bahaya);
    }

    vector<long> perjalanan;
    g.dijkstra(perjalanan, 1);

    cout << perjalanan[n] << endl;

    return 0;
}
