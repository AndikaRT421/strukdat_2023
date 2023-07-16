#include <iostream>
#include <vector>
#include <map>
#include <climits>
// #include <queue>
#include <algorithm>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    map<long, vector<pair<long, long>>> adjList;
    vector<pair<long, pair<long, long>>> edgeList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        // adjList[vertex2].push_back(make_pair(vertex1, weight));

        edgeList.push_back(make_pair(weight, make_pair(vertex1, vertex2)));
        edgeCount++;
    }

    long find_parent(map<long, long> &parent, long v)
    {
        if (v == parent[v])
            return v;

        return find_parent(parent, parent[v]);
    }

    void union_set(map<long, long> &parent, map<long, long> &rank, long vertex1, long vertex2)
    {
        long parent1 = find_parent(parent, vertex1);
        long parent2 = find_parent(parent, vertex2);

        if (rank[parent1] < rank[parent2])
        {
            parent[parent1] = parent2;
        }
        else if (rank[parent1] > rank[parent2])
        {
            parent[parent2] = parent1;
        }
        else
        {
            parent[parent1] = parent2;
            rank[parent2]++;
        }
    }

    long weight_terkecil(int vertexx, map<long, long> parent)
    {
        long terkecil = INT_MAX;
        for (auto it : edgeList)
        {
            long ortu_vertexx = find_parent(parent, vertexx);
            long vertex1 = it.second.first;
            long vertex2 = it.second.second;
            if (find_parent(parent, vertex1) == ortu_vertexx || find_parent(parent, vertex2) == ortu_vertexx)
            {
                if (terkecil > it.first)
                    terkecil = it.first;
            }
        }
        return terkecil;
    }

    void find_max_confidence(map<long, long> &percaya_diri, map<long, long> &parent, long A, long B)
    {
        long rootA = find_parent(parent, A);
        long rootB = find_parent(parent, B);

        if (rootA == rootB)
        {
            cout << 0 << endl; // Vertex A dan B berada dalam satu kelompok
            return;
        }

        long maxConfidenceA = percaya_diri[rootA];
        long maxConfidenceB = percaya_diri[rootB];

        for (long i = 0; i < parent.size(); i++)
        {
            long root = find_parent(parent, i);
            if (root == rootA)
                maxConfidenceA = max(maxConfidenceA, percaya_diri[i]);
            else if (root == rootB)
                maxConfidenceB = max(maxConfidenceB, percaya_diri[i]);
        }

        cout << maxConfidenceA + maxConfidenceB << endl;
    }

    void update_weight(long vertex1, long vertex2, long newWeight)
    {
        // Cari indeks edge yang terhubung antara vertex1 dan vertex2
        int edgeIndex = -1;
        for (int i = 0; i < edgeList.size(); i++)
        {
            if ((edgeList[i].second.first == vertex1 && edgeList[i].second.second == vertex2) ||
                (edgeList[i].second.first == vertex2 && edgeList[i].second.second == vertex1))
            {
                edgeIndex = i;
                break;
            }
        }

        // Jika edge tidak ditemukan, keluar dari fungsi
        if (edgeIndex == -1)
            return;

        // Perbarui bobot pada edgeList
        edgeList[edgeIndex].first = newWeight;

        // Perbarui bobot pada adjList
        for (auto &vertex : adjList[vertex1])
        {
            if (vertex.first == vertex2)
            {
                vertex.second = newWeight;
                break;
            }
        }

        for (auto &vertex : adjList[vertex2])
        {
            if (vertex.first == vertex1)
            {
                vertex.second = newWeight;
                break;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graph g;
    long N, M;
    cin >> N >> M;
    g.init(N + 1);

    map<long, long> percaya_diri;
    for (long i = 1; i <= N; i++)
    {
        long PD;
        cin >> PD;
        percaya_diri[i] = PD;
    }

    map<long, long> parent;
    map<long, long> rank;
    for (long i = 1; i <= N; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    while (M--)
    {
        long U, V, W;
        cin >> U >> V >> W;
        g.add_edge(U, V, W);
        g.union_set(parent, rank, U, V);
    }

    sort(g.edgeList.begin(), g.edgeList.end());

    long perintah;
    cin >> perintah;
    while (perintah--)
    {
        char tanda;
        long kode;
        cin >> tanda >> kode;

        if (tanda == '?')
        {
            if (kode == 1)
            {
                long vertex;
                cin >> vertex;
                if (g.adjList[vertex].empty()) // AMAN
                    cout << 0 << endl;
                else
                {
                    long terkecil = g.weight_terkecil(vertex, parent);
                    if (terkecil == INT_MAX)
                        cout << 0 << endl;
                    else
                        cout << terkecil << endl;
                }
            }
            else if (kode == 2)
            {
                long A, B;
                cin >> A >> B;

                if (g.find_parent(parent, A) == g.find_parent(parent, B))
                    cout << 0 << endl;
                else
                {
                    g.find_max_confidence(percaya_diri, parent, A, B);
                }
            }
        }
        else if (tanda == '!')
        {
            if (kode == 1)
            {
                int node, optimis_baru;
                cin >> node >> optimis_baru;
                percaya_diri[node] = optimis_baru;
            }
            else if (kode == 2)
            {
                int A, B, weight_baru;
                cin >> A >> B >> weight_baru;
                g.update_weight(A, B, weight_baru);
            }
        }
    }
}
