#include<iostream>
#include<stdlib.h>
using namespace std;
bool bs(int b[], int p, int r, double key)
{
    if(p > r)
        return false;
    int q = (p+r)/2;
    if(b[q] == key)
        return true;
    else if(b[q] > key)
        return bs(b, p, q-1, key);
    else
        return bs(b, q+1, r, key);
}
int main()
{
    int e_i,e_f,c_i,c_f;
    cin >> e_i >> e_f >> c_i >> c_f;
    double eff;
    cin >> eff;
    int b[c_f-c_i+1];
    for(int i = 0; i < c_f-c_i+1; i++)
        b[i] = c_i+i;
    for(int i = e_i-1; i < e_f; i++)
    {
        bool ans = bs(b, 0, c_f-c_i, (i+1)/eff);
        if(ans)
        {
            cout << "YES";
            exit(0);                                   //0 => Exit Success. !0 => Exit Failure.
        }
    }
    cout << "NO";
    return 0;
}
