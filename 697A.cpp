/*
   Accepted
*/

#include<iostream>
using namespace std;
int main()
{
    long long int t,s,x;
    cin >> t >> s >> x;
    long long int a,b;
    a = ( x - t )/ s;
    b = (x-1-t)/ s;
    if(x < t+s)
    {
        if(x == t)
            cout << "YES";
        else
            cout << "NO";
    }
    else if(x >= t+a*s && x <= t+a*s+1)
    {
        cout << "YES";
    }
    else
        cout << "NO";
     //     cout <<"\n"<< t+a*s-x << " "<< a << "\n";
    return 0;
}
