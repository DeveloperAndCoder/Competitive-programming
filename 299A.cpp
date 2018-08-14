/*
  Accepted.
*/

#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x == 0)
    {
        cout << "zero";
        return 0;
    }
    string ones[9] = {"one","two","three","four","five","six","seven","eight","nine"};
    string tens[9] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    string exc[10] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    if(x/10 != 0)
    {
        int ten = x/10;
        if (ten != 1)
        {
            cout << tens[ten-2];
        }
        else if(x == 10)
        {
            cout << "ten";
            return 0;
        }
        else
        {
            cout << exc[x%10 - 1];
            return 0;
        }
        if(x%10 != 0)
        {
            cout << "-" << ones[x%10-1];
        }
    }
    else
    {
        cout << ones[x - 1];
    }
    return 0;
}
