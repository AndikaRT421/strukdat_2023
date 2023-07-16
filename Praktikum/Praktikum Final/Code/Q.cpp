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
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                result.push_back(temp);
                visited[temp] = true;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
    }

    void bfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                {
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    void dijkstra(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        priority_queue<pair<long, long>,
                       vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq;
        result = vector<long>(vertexCount, LONG_MAX);

        pq.push(make_pair(0, start));
        result[start] = 0;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for (auto vertex : adjList[temp.second])
            {
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if (!visited[nextVertex])
                {
                    if (temp.first + weight < result[nextVertex])
                    {
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int main()
{
    int jumlah_resto;
    cin >> jumlah_resto;
    map <int, pair <string, int>> vertex_resto;

    graph g;
    g.init(jumlah_resto+1);

    for (int i = 1; i <= jumlah_resto; i++)
    {
        string nama_resto;
        int harga;
        cin >> nama_resto >> harga;
        vertex_resto[i] = make_pair(nama_resto, harga);
    }

    int E;
    cin >> E;
    while (E--)
    {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        g.add_edge(vertex1, vertex2, weight);
    }

    int energi;
    cin >> energi;

    vector<long> dijkstra_result;
    g.dijkstra(dijkstra_result, 0);

    int termurah = INT_MAX;
    int resto_termurah = -1;

    for (int i = 1; i < dijkstra_result.size(); i++)
    {
        if (dijkstra_result[i] <= energi) // test 1
        {
            if (vertex_resto[i].second < termurah)
            {
                termurah = vertex_resto[i].second;
                resto_termurah = i;
            }
        }
    }

    cout << "hari ini makan di " << vertex_resto[resto_termurah].first << endl;
    return 0;
}