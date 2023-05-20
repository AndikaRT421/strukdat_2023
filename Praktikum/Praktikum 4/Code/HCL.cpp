#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<bool> visit(10, false);
vector<int> vertex[10];

void map_init(map<string, int> &papan)
{
    papan["A1"] = 1;
    papan["B1"] = 2;
    papan["C1"] = 3;
    papan["A2"] = 4;
    papan["B2"] = 5;
    papan["C2"] = 6;
    papan["A3"] = 7;
    papan["B3"] = 8;
    papan["C3"] = 9;
}

void dfs(int angka, int &count)
{
    count++;
    visit[angka] = true;
    for (int i = 0; i < vertex[angka].size(); i++)
    {
        int k = vertex[angka][i];
        if (!visit[k])
        {
            dfs(k, count);
        }
    }
}

int main()
{
    map<string, int> papan;
    map_init(papan);

    int test;
    cin >> test;
    while (test--)
    {
        string a, panah, b;
        cin >> a >> panah >> b;
        vertex[papan[a]].push_back(papan[b]);
        vertex[papan[b]].push_back(papan[a]);
    }

    int indeks = 1;
    map<int, int> v_papan;
    for (int j = 1; j <= 9; j++)
    {
        if (!visit[j])
        {
            int count = 0;
            dfs(j, count);
            v_papan[indeks++] = count;
        }
    }

    int nolep = 0;
    for (int j = 1; j < indeks - 1; j++)
    {
        for (int q = j + 1; q < indeks; q++)
        {
            nolep += v_papan[j] * v_papan[q];
        }
    }
    cout << nolep << endl;
}