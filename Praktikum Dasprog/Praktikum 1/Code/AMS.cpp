#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<long long, long long> peta;
    long long jumlah_pemain;
    cin >> jumlah_pemain;
    long long ID_terbesar = INT_MIN, poin_terbesar = INT_MIN;
    for (int i = 0; i < jumlah_pemain; i++)
    {
        long long ID, dikalahkan, lolos;
        cin >> ID >> dikalahkan >> lolos;
        long long poin = (dikalahkan*500) + (lolos*-200);
        peta[ID] += poin;
        if (peta[ID] > poin_terbesar)
        {
            poin_terbesar = peta[ID];
            ID_terbesar = ID;
        }
        else if(peta[ID] == poin_terbesar && ID > ID_terbesar)
        {
            ID_terbesar = ID;
        }
        cout << ID_terbesar << " " << poin_terbesar << endl;
    }

}