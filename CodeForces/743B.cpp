#include<iostream>
using namespace std;
int main()
{
    long long n,k;
    cin >> n >> k;
    int l = 1;
    while(!(k&1))
    {
        k>>=1;
        l++;
    }
    cout << l;
    return 0;
}
