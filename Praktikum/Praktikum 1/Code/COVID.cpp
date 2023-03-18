#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> peta, ppeta;
    // pair <string,int> pair1;
    string rumah;
    cin >> rumah;
    while (rumah != "#")
    {
        peta.push_back(rumah);
        cin >> rumah;
    }
    string telah_vaksin;
    // ilmu baru
    while (cin >> telah_vaksin)
    {

    }
    while (getline(cin, telah_vaksin))
    {
        istringstream iss(telah_vaksin);
        string token;
        while (iss >> token)
        {
            ppeta.push_back(token);
        }
    }
    int kondisi = 0;
    while (!peta.empty())
    {
        if (peta.front() == ppeta.front())
        {
            if (kondisi == 1)
            {
                kondisi = 7;
            }
            peta.pop_front();
            ppeta.pop_front();
        }
        else
        {
            if (kondisi == 7)
            {
                cout << "Gabisa sumpah, game ini red flag banget sih" << endl;
                return 0;
            }
            else
            {
                kondisi = 1;
                peta.pop_front();
            }
        }
    }
    cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    return 0;
}