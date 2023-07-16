#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define modex 1000000009

long long poww(long long basis, long long perpangkatan)
{
    if (perpangkatan == 0) return 1;
    if (perpangkatan == 1) return basis;

    long long temp = poww(basis, perpangkatan / 2) % modex;
    if (perpangkatan % 2 == 0) return (temp * temp) % modex;
    else return (((basis * temp) % modex) * temp) % modex;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long angka;
        cin >> angka;
        printf("Zodiak found: %lld signs\n", poww(2ll, (angka* (angka - 1ll) / 2ll)));
    }
    return 0;
}