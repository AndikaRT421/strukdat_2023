#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void dfs(int i, vector<vector<int>> &kosmik, vector<int> &visited)
{
    visited[i] = 1;
    for (int k : kosmik[i])
    {
        if (visited[k] == 0)
            dfs(k, kosmik, visited);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> visited(N, 0);
    vector<vector<int>> kosmik(N);

    for (int i = 0; i < M; i++)
    {
        int angka1, angka2;
        cin >> angka1 >> angka2;
        kosmik[angka1].push_back(angka2);
        kosmik[angka2].push_back(angka1);
    }

    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, kosmik, visited);
            flag++;
        }
    }

    if (flag == 1)
        cout << "Kompleksitas entitas terbentuk" << endl;
    else
        printf("Seluruh kosmik tidak berkaitan, butuh %d lagi\n", flag - 1);

    return 0;
}
