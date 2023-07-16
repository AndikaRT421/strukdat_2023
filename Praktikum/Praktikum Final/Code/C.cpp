#include <bits/stdc++.h>
using namespace std;

void cek_sisa(priority_queue<pair<int, int>> &urutan_barang)
{
    while (1)
    {
        if (urutan_barang.size() == 0)
        {
            cout << 0 << endl;
            break;
        }
        else if (urutan_barang.size() == 1)
        {
            cout << urutan_barang.top().first << endl;
            break;
        }

        int jumlah_barang1 = urutan_barang.top().first;
        int harga_barang1 = urutan_barang.top().second;
        jumlah_barang1--;
        urutan_barang.pop();

        int jumlah_barang2 = urutan_barang.top().first;
        int harga_barang2 = urutan_barang.top().second;
        jumlah_barang2--;
        urutan_barang.pop();

        if (jumlah_barang1 != 0)
            urutan_barang.push(make_pair(jumlah_barang1, harga_barang1));
        if (jumlah_barang2 != 0)
            urutan_barang.push(make_pair(jumlah_barang2, harga_barang2));
    }
}

int main()
{
    int test;
    cin >> test;
    map<int, int> kondisi_barang;
    while (test--)
    {
        int banyak_barang;
        cin >> banyak_barang;
        while (banyak_barang--)
        {
            int harga;
            cin >> harga;
            kondisi_barang[harga]++;
        }
        priority_queue<pair<int, int>> urutan_barang;
        for (auto i : kondisi_barang)
            urutan_barang.push(make_pair(i.second, i.first));

        cek_sisa(urutan_barang);
        kondisi_barang.clear();
    }
}