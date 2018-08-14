#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

typedef long long ll;

int fact(int n)
{
    if(n==0) return 1;

    return n*fact(n-1);
}

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int s = 0;
    double prob = 0.00;
    forn(i,0,s1.length())
    {
        if(s1[i] == '+') s++;
        else
            s--;
    }
    int n = 0;
    for(int i=0;i<s2.length();i++) {
        if(s2[i] == '?') n++;
        else if(s2[i] == '+') s--;
        else
            s++;
    }
    if(((n+s) & 1) || abs(s) > n)
    {
        cout << prob;
        return 0;
    }
    if(n == 0)
    {
        if(s == 0) cout << 1;
        else cout << 0;
        return 0;
    }
    int x = (n+s)/2;
    int y = n-x;

    prob = fact(n)/(fact(x)*fact(y));
    prob /= (1<<n);
    cout << setprecision(20) << prob << endl;
    return 0;
}
