#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    map<string, pair<string, map<string, vector<string>>>> catat_log;
    while (N--)
    {
        string IP, nama;
        cin >> IP >> nama;
        map<string, vector<string>> kotak_pesan; // kosongan dulu
        catat_log[IP] = make_pair(nama, kotak_pesan); // biar bisa akses namanya nanti
    }

    cin.ignore(); // Add this line to consume the newline character after the integer input

    while (Q--)
    {
        string pengirim, penerima, pesan;
        cin >> pengirim >> penerima;
        cin.ignore(); // buffer
        getline(cin, pesan);

        if (catat_log.find(pengirim) != catat_log.end() &&
            catat_log.find(penerima) != catat_log.end()) // cek pengirim dan penerima udh ada apa belum
        {
            catat_log[penerima].second[pengirim].push_back(pesan); // Fix this line to directly push the message into the vector
        }
    }

    for (const auto &i : catat_log) // Change auto to const auto to avoid unnecessary copying
    {
        if (i.second.second.empty()) // map nya kosong apa enggak
            continue;
        cout << "===========" << endl;
        cout << "Mail: " << i.second.first << endl;
        for (const auto &j : i.second.second) // akses map yang kotak_pesan
        {
            cout << "From: " << catat_log[j.first].first << endl; // nama pengirim;
            for (const auto &z : j.second)
            {
                cout << ">> " << z << endl; // Remove the dereference operator (*) since z is already a string
            }
        }
    }

    return 0;
}
