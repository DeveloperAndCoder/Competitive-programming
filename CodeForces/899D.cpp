#include<iostream>
#include<math.h>

using namespace std;
typedef long long ll;

inline int digits(ll n)
{
    int num = 0;
    while(n != 0)
    {
        num++;
        n/=10;
    }
    return num;
}

ll ans(ll n)
{
    register int k = digits(n);
   // cout << "k = " << k << endl;
    ll nine_ = 0;
    int i = 0;
    while(i != (k-1))
    {
        nine_ = nine_*10 + 9;
        ++i;
    }
    ll nine_k = nine_*10+9;
    ll j = 0LL;
    if(2*n-1 >= nine_k)
    {
        j += (n+1)-(nine_k+1)/2;
        if(n == nine_k)
            j--;
    }
    else
    {
        ll add=1;
        for(int i = 0; i < k-1; i++)
            add*=10;
        //cout << "add = " << add << endl;
        for( register ll i = nine_; i <= 2*n-1; i+=add)
        {
            //cout << "i = " << i << endl;
            if(2*n-1 >= i && n < i)
                {
                    j += (n+1)-(i+1)/2;
                    if(n == i && (i/add) == 9)
                        j--;
                }
            else
            {
                j += i-(i+1)/2;
                if(n == i && (i/add == 9))
                {
                    //cout << n << " = n : i = " << i << endl;
                    j--;
                }
            }
        }
    }
    return j;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    if(n < 5)
    {
        cout << (n*(n-1))/2;
        return 0;
    }
    ll result = ans(n);
    cout << result;
    return 0;
}
