#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    stack<int> kondisi;
    while (test--)
    {
        int perintah;
        cin >> perintah;
        if (kondisi.empty())
        {
            if (perintah == 1)
            {
                kondisi.push(1);
                kondisi.push(0);
            }
            else
                kondisi.push(0);
        }
        else if (kondisi.size() == 1)
        {
            if (kondisi.top() == 1 && perintah == 1)
                kondisi.pop();
            else if (kondisi.top() == 1 && perintah == 0)
                kondisi.push(0);
            else if (kondisi.top() == 0 && perintah == 0)
                kondisi.pop();
        }
        else
        {
            if (kondisi.top() == 1 && perintah == 1)
                kondisi.pop();
            else if (kondisi.top() == 1 && perintah == 0)
                kondisi.push(0);
            else if (kondisi.top() == 0 && perintah == 1)
            {
                kondisi.pop();
                kondisi.push(1);
                kondisi.push(0);
                kondisi.push(1);
                kondisi.push(0);
            }
            else
                kondisi.pop();
        }
    }
    cout << kondisi.size() << endl;
}