#include <iostream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

bool compare(pair<string, int> p, pair<string, int> q)
{
    return p.second < q.second;
}

typedef std::pair<std::string, int> MyPairType;
struct CompareSecond
{
    bool operator()(const MyPairType &left, const MyPairType &right) const
    {
        return left.second < right.second;
    }
};

int main()
{
    map<string, int> material;
    string bahan;
    // cin.ignore();
    getline(cin, bahan);
    while (bahan != "#")
    {
        material[bahan] += 1;
        // cout << material[bahan] << endl;
        getline(cin, bahan);
    }
    int N, X, M, Y;
    int kondisi_X, kondisi_M;
    cin >> N;
    while (N--)
    {
        map<string, int> catat_pengurangan;
        cin >> X >> M;
        // flag = 0;
        kondisi_X = X;
        kondisi_M = M;
        stack <pair <string, int>> simpan_item;
        while (M--)
        {
            string item;
            string mboh;
            getline(cin, mboh);
            getline(cin, item);
            cin >> Y;
            int keperluan = Y * X;
            simpan_item.push({item, keperluan});
            // cout << material[item] << endl;
            if (material[item] - keperluan >= 0)
            {
                catat_pengurangan[item] = X;
                // material[item] -= keperluan;
                // cout << material[item] << endl;
            }
            else
            {
                // cek dia bisanya bikin berapa benda
                int bisanya_berapa = material[item] / Y;
                // material[item] -= bisanya_berapa; // meski insufficient, tetep dikurangi
                catat_pengurangan[item] = bisanya_berapa;
                // cout << catat_pengurangan[item] << endl;
            }
        }
        int flag = 0;
        for (auto i = catat_pengurangan.begin(); i != catat_pengurangan.end(); i++)
        {
            if (i->second == kondisi_X)
                flag++;
        }
        if (flag == kondisi_M) // apakah semua bahan sesuai permintaan
        {
            cout << "Material Fulfilled, Crafting " << kondisi_X << "!" << endl;
            while (!simpan_item.empty())
            {
                material[simpan_item.top().first] -= simpan_item.top().second;
                simpan_item.pop(); 
            }
        }
        else
        {
            pair<std::string, int> minn;
            minn = (*min_element(catat_pengurangan.begin(), catat_pengurangan.end(), CompareSecond()));
            cout << "Insufficient Material, Can only craft " << minn.second << "." << endl;
        }
    }
}