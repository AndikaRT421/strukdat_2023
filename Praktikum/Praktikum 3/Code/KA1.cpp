#include <iostream>
#include <map>
using namespace std;

int main()
{
    int banyak;
    cin >> banyak;
    map<string, int> kamus;
    int satu = 0, dua = 0;
    while (banyak--)
    {
        string kata;
        cin >> kata;
        kamus[kata] += 1;
        if (kamus[kata] > 2)
        {
            cout << kata << " tidak bisa masuk Kamus!" << endl;
        }
        else
        {
            cout << kata << " masuk Kamus " << kamus[kata] << "!" << endl;
        }

        if (kamus[kata] == 1) satu++;
        else if (kamus[kata] == 2) dua++;
    }
    // for (auto i = kamus.begin(); i != kamus.end(); i++)
    // {
    //     if (i->second == 1)
    //         satu++;
    //     else if (i->second == 2)
    //         dua++;
    // }
    cout << "Kamus 1 berisi " << satu << " kata" << endl;
    cout << "Kamus 2 berisi " << dua << " kata" << endl;
}