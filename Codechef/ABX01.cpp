#include<iostream>

#define ll long long
using namespace std;

bool issingle(ll n)
{
    n /= 10;
    if(n == 0)
        return true;
    return false;
}

ll pow(ll a, ll b)
{
    while(--b)
    {
        a*=a;
    }
    return a;
}

ll f(ll a, ll n)
{
    //cout << a << " " << n << endl;
    if(a == 0)
        return 0;
    if(n == 0)
        return 1;
    if(n == 1 && issingle(a))
        return a;
    if(n == 1 && !issingle(a))
    {
        ll sum = 0;
        while(a != 0)
        {
            sum += a%10;
            a /= 10;
        }
        return f(sum,1);
    }
    ll sum = 0;
    if(!(n&1))
    sum = f(pow(f(a,n/2),2),1);
    else
    sum = f(pow(f(a,n/2),2)*a,1);
   // cout << "sum = " << sum << endl;
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);

    int test;
    cin >> test;
    while(test--)
    {
        ll n,a;
        cin >> a >> n;
        ll sum = f(a,n);
        /*if(sum == 0) cout << 9 << endl;
        else */cout << sum << endl;
    }
}
