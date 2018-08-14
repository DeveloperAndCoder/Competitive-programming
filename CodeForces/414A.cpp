/*
ANURAG SHAH
IIT JODHPUR
*/
#include<iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;
    if(n == 1)
    {
        if(k == 0)
            cout << 1;
        else
            cout << -1;
        return 0;
    }
    if(n == 2)
    {
        if(k != 0)
            cout << k << " " << 2*k;
        else
            cout << -1;
        return 0;
    }
    if(k < n/2)
    {
        cout << -1;
        return 0;
    }
    int sum = 0;
    bool bb = 1;
    if(n%2 != 0) bb = 0;
    int n1 = n-3+bb;
    forn(i,0,n1)
    {
        cout << i+1 << " ";
    }
    sum = n1/2;
    sum = k-sum;
    int xx = n1/sum;
    int k1 = xx*sum;
    while(k1 <= n1) k1+=sum;
    cout << k1 << " " << k1+sum<<" ";
    if(!bb) cout << k1+sum+1;
    return 0;
}
