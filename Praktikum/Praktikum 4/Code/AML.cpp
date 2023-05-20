#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int mulai)
{
    stack<int> st;

    st.push(mulai);
    visited[mulai] = true;

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        if (!visited[temp])
            visited[temp] = true;

        for (auto it : graph[temp])
        {
            if (!visited[it])
                st.push(it);
        }
    }
}

int main()
{
    vector<vector<int>> graph;
    int vertex, N;
    cin >> N;
    vertex = N;
    vector<bool> visited(vertex, false);
    graph.resize(vertex);
    for (int i = 0; i < N; i++)
    {
        int banyak_kunci;
        cin >> banyak_kunci;
        while (banyak_kunci--)
        {
            int kunci_ruang;
            cin >> kunci_ruang;
            graph[i].push_back(kunci_ruang);
        }
    }
    dfs(graph, visited, 0);
    int flag = 0;
    for (int i = 0; i < visited.size(); ++i)
    {
        if (!visited[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Para peserta LBH terjebak selamanya." << endl;
    else
        cout << "Para peserta LBH berhasil keluar!" << endl;
}