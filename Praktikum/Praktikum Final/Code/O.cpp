#include <bits/stdc++.h>
using namespace std;

int N;

int cek_radius(int x, int y, int i, int k)
{
    if (x == i) // nilai 1
    {
        if (y == k)
            return 1;
        else if (y - 1 == k || y + 1 == k)
            return 2;
        else if (y - 2 == k || y + 2 == k)
            return 3;
        else if (y - 3 == k || y + 3 == k)
            return 4;
    }
    else if (x - 1 == i || x + 1 == i) // nilai 2
    {
        if (y == k)
            return 2;
        else if (y - 1 == k || y + 1 == k)
            return 3;
        else if (y - 2 == k || y + 2 == k)
            return 4;
    }
    else if (x - 2 == i || x + 2 == i) // nilai 3
    {
        if (y == k)
            return 3;
        else if (y - 1 == k || y + 1 == k)
            return 4;
    }
    else if (x - 3 == i || x + 3 == i) // nilai 4
    {
        if (y == k)
            return 4;
    }
}

int main()
{
    int M;
    cin >> N >> M;
    vector<vector<int>> peta(N + 2, vector<int>(N + 2, 0));
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;
        // peta[x + 1][y + 1] = 1;

        for (int i = 1; i <= N; i++)
        {
            for (int k = 1; k <= N; k++)
            {
                int jarak_x = abs(k - x);
                int jarak_y = abs(i - y);
                int jangkauan = 7 / 2;

                if (jangkauan >= jarak_x && jangkauan >= jarak_y && jangkauan >= jarak_x + jarak_y)
                {
                    int radius = cek_radius(x, y, k, i);
                    if (peta [i][k] == 0 || peta[i][k] > radius)
                    {
                        peta[i][k] = radius;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << peta[i][j] << " ";
        }
        cout << endl;
    }
}