#include <iostream>
#include <vector>
using namespace std;

bool abc(vector<vector<char>> &G, int i, int j, int dimensi)
{
    if (i < 0 || j < 0 || i >= dimensi || j >= dimensi)
        return true;
    if (G[i][j] == '#')
        return true;
    G[i][j] = '#';
    bool p = abc(G, i + 1, j, dimensi), q = abc(G, i, j + 1, dimensi), r = abc(G, i - 1, j, dimensi), s = abc(G, i, j - 1, dimensi), t = abc(G, i+1, j+1, dimensi), u = abc(G, i+1, j - 1, dimensi), v = abc(G, i-1, j + 1, dimensi), w = abc(G, i-1, j - 1, dimensi);
    return p && q && r && s && t && u && v && w;
}

int numIslands(vector<vector<char>> &grid, int dimensi)
{
    int k = 0;
    for (int i = 0; i < dimensi; i++)
        for (int j = 0; j < dimensi; j++)
            if (grid[i][j] == '+')
            {
                if (abc(grid, i, j, dimensi))
                    k++;
            }
    return k;
}

int main()
{
    int dimensi;
    cin >> dimensi;
    vector<vector<char>> mat(dimensi, vector<char>(dimensi));

    for (int i = 0; i < dimensi; i++)
    {
        for (int j = 0; j < dimensi; j++)
        {
            char angka;
            cin >> angka;
            mat[i][j] = angka;
        }
    }

    cout << numIslands(mat, dimensi);

    return 0;
}
