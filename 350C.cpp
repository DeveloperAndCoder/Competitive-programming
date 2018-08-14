#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<queue>
#include<math.h>
#include<utility>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define eb emplace_back
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push
#define fr first
#define sc second

using namespace std;

bool cmp(pair<ll, ll> c1, pair<ll, ll> c2)
{
    if(c1.fr >= 0 && c2.fr >= 0)
    {
        if(c1.fr == c2.fr)
            {
                ll a = abs(c1.sc); ll b = abs(c2.sc);
                return a < b;
            }
        return c1.fr<c2.fr;
    }
    else if(c1.fr <= 0 && c2.fr <= 0)
    {
        if(c1.fr == c2. fr)
        {
            ll a = abs(c1.sc); ll b = abs(c2.sc);
                return a > b;
        }
        return abs(c1.fr) > abs(c2.fr);
    }
    return (c1.fr < c2.fr);
}

string to_string(ll n)
{
    string s;
    while(n)
    {
        s.push_back(n%10+'0');
        n /= 10;
    }
    return s;
}

int main()
{
    boost;
    int n;
    cin >> n;
    pair<ll, ll> c[n];
    forn(i,0,n) cin >> c[i].fr >> c[i].sc;
    sort(c, c+n, cmp);
    int sz = 0;
    forn(i,0,n)
    {
        if(c[i].fr != 0) sz+=2;
        if(c[i].sc != 0) sz+=2;
        sz+=2;
    }
    cout << sz << endl;
    int i = 0;
    while(i < n && c[i].fr < 0) i++;
    int j = i;
    i--;
    while(i >= 0)
    {
        if(c[i].sc == 0)
        {
            cout << "1 " << -1LL*c[i].fr << " L\n2\n1 " << -1LL*c[i].fr << " R\n3\n";
        }
        i--;
    }
    i = j;
    while(i < n)
    {
        if(c[i].sc == 0)
        {
            cout << "1 " << c[i].fr << " R\n2\n1 " << c[i].fr << " L\n3\n";
        }
        i++;
    }
    i = j-1;
    while(i >= 0)
    {
        if(c[i].sc < 0)
        {
            if(c[i].fr)
            {
                cout << "1 " << -1LL*c[i].fr << " L\n1 " << -1LL*c[i].sc << " D\n2\n1 " << -1LL*c[i].sc << " U\n1 " << -1LL*c[i].fr << " R\n3\n";
            }
            else
            {
                cout << "1 " << -1LL*c[i].sc << " D\n2\n1 " << -1LL*c[i].sc << " U\n"<< "3\n";
            }
        }
        else if(c[i].sc > 0)
        {
            if(c[i].fr)
            {
                cout << "1 " << -1LL*c[i].fr << " L\n1 " << c[i].sc << " U\n2\n1 " << c[i].sc << " D\n1 " << -1LL*c[i].fr << " R\n3\n";
            }
            else
            {
                cout << "1 " << c[i].sc << " U\n2\n1 " << c[i].sc << " D\n"<< "3\n";
            }
        }
        i--;
    }
    i = j;
    while(i < n)
    {
        if(c[i].sc > 0)
        {
            if(c[i].fr)
            {
                cout << "1 " << abs(c[i].fr) << " R\n1 " << c[i].sc << " U\n2\n1 " << c[i].sc << " D\n1 " << abs(c[i].fr) << " L\n3\n";
            }
            else
            {
                cout << "1 " << c[i].sc << " U\n2\n1 " << c[i].sc << " D\n"<< "3\n";
            }
        }
        else if(c[i].sc < 0)
        {
            if(c[i].fr)
            {
                cout << "1 " << abs(c[i].fr) << " R\n1 " << -1LL*c[i].sc << " D\n2\n1 " << -1LL*c[i].sc << " U\n1 " << abs(c[i].fr) << " L\n3\n";
            }
            else
            {
                cout << "1 " << -1LL*c[i].sc << " D\n2\n1 " << -1LL*c[i].sc << " U\n"<< "3\n";
            }
        }
        i++;
    }
    return 0;
}
