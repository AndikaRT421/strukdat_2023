#include <bits/stdc++.h>
using namespace std;

int M, N;

void BFS(int x_letak, int y_letak, bool &flag, int visited[103][103], map<int, string> &peta)
{
    if (x_letak < 0 || y_letak < 0 || x_letak >= M || y_letak >= N)
    {
        flag = true;
        return;
    }

    if (!visited[x_letak][y_letak])
    {
        visited[x_letak][y_letak] = 1;

        if (peta[x_letak][y_letak] == 'X')
        {
            return;
        }
        if (peta[x_letak][y_letak] == '^')
        {
            flag = true;
            return;
        }

        BFS(x_letak - 1, y_letak, flag, visited, peta);
        BFS(x_letak + 1, y_letak, flag, visited, peta);
        BFS(x_letak, y_letak - 1, flag, visited, peta);
        BFS(x_letak, y_letak + 1, flag, visited, peta);
    }
}

int main()
{
    cin >> M >> N;
    map<int, string> peta;
    for (int i = 0; i < M; i++) // mulai
        cin >> peta[i];
    vector<pair<int, int>> catat;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (peta[i][j] == 'O')
                catat.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < catat.size(); i++)
    {
        int x_letak = catat[i].first;
        int y_letak = catat[i].second;

        int visited[103][103] = {0};
        bool flag = false;

        BFS(x_letak, y_letak, flag, visited, peta);

        if (!flag)
            peta[x_letak][y_letak] = 'X';
    }

    for (auto it : peta)
        cout << it.second << endl;
}