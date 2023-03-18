#include <bits/stdc++.h>
using namespace std;

int operation(int a, int b, string op)
{
    if (op == "+")
        return b + a;
    else if (op == "-")
        return b - a;
    else if (op == "*")
        return b * a;
    else if (op == "/")
        return b / a;
    else
        return INT_MIN; // return negative infinity
}

int main()
{
    string soal;
    getline(cin, soal);
    istringstream iss(soal);
    string token;
    stack<string> stk_cuy;
    int flag = 0;
    while (getline(iss, token, ' '))
    {
        if (token.compare("+") == 0 || token.compare("-") == 0 || token.compare("*") == 0 || token.compare("/") == 0)
        {
            int a, b;
            if (stk_cuy.empty())
            {
                flag = 1;
                break;
            }
            a = stod(stk_cuy.top());
            stk_cuy.pop();
            if (stk_cuy.empty())
            {
                flag = 1;
                break;
            }
            b = stod(stk_cuy.top());
            stk_cuy.pop();
            if (token.compare("/") == 0 && a == 0)
            {
                flag = 1;
                break;
            }
            stk_cuy.push(to_string(operation(a, b, token)));
        }
        else
        {
            stk_cuy.push(token);
        }
    }
    if (stk_cuy.size() == 1 && flag == 0)
    {
        double x = stod(stk_cuy.top());
        cout << int(x) << endl;
    }
    else
    {
        cout << "ERROR" << endl;
    }
    return 0;
}