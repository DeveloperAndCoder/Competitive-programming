#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define mod 1000000007

using namespace std;

int main()
{
    ll n;
    cin >> n;
    int k;
    cin >> k;
    while(k--)
    {
        if(n%10)
            n--;
        else
            n/=10;
    }
    cout << n;
    return 0;
}
