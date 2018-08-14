#include<iostream>

#define forn(i,a,b) for(int i =a; i < b; i++)
#define ll long long

using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll max_bit = 1,bit = 1;
    ll min_bit = 1;
    while(max_bit <= n)
    {
        max_bit <<= 1;
    }
    while(!(min_bit&n)) min_bit<<=1;
    max_bit >>= 1;
    int x = 1,y = 1;
    int c = 1,c2=1;
    while(k > x)
    {
        max_bit>>=1;
        c++;
        k -= x;
        x>>=1;
    }
    while(y > 0)
    {
        c2++;
    }
}
