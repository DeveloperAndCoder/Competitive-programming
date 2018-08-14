#include<iostream>
#include<cmath>
#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)

using namespace std;

ll pow(ll a, ll b)
{
    while(--b)
        a *= 10;
    return a;
}

ll get(ll j, ll p)
{
    ll num = 0LL;
    ll rev = 0LL;
    ll h = j;
    int ten = 0LL;
    bool b = true;
    while(h)
    {
        if(h%10 == 0 && b)
            {
                ten++;
            }
        else
        {
            b = false;
        }
        rev *= 10;
        rev += h%10;
        h /= 10;
        num++;
    }
    //cout << j << " " << rev << " " << ten << " " << pow(10,num+ten-1)<<"\n";
    if(ten > 0)
    {
        ll power = pow(10LL,num);
      //  cout << "Power = " << power << endl;
        j = j*power;
    }
    else
        j *= pow(10LL,num);
    //cout << j << " " << rev << " " << ten << " " << pow(10,num+ten)<<"\n";
    j += rev;
    //cout << j << " " << rev << " " << ten << " " /*<< pow(10,num+ten)*/<<"\n";
    //j %= p;
    //cout << "j = " << j << endl << endl;
    return j;
}


int main()
{
    ll k, p;
    cin >> k >> p;
    ll sum = 0;
    ll j = 1;
    forn(i,0,k)
    {
        sum += get(j,p);
        j++;
        //sum %= p;
       // cout << sum << " ";
    }
    sum %= p;
    cout << sum;
    return 0;
}
