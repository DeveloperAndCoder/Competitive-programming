#include<iostream>
using namespace std;

typedef long long ll;


int main()
{
    string n;
    cin >> n;
    ll sum = 0;
    for(int i = n.length()-1; i>=0; i--)
    {
        if(n[i] == '7')
        {
            sum += (1<<(n.length()-1-i));
        }
    }
    sum += (1<<n.length());
    sum-=2;
    cout << sum+1;
    return 0;
}
