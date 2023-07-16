#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B;
    cin >> A >> B;
    int angka1 = 0, angka2 = 0;
    while (A--)
    {
        int num;
        cin >> num;
        angka1 += num * pow(10, A);
    }
    while (B--)
    {
        int num;
        cin >> num;
        angka2 += num * pow(10, B);
    }
    angka1 += angka2;
    cout << angka1;
}