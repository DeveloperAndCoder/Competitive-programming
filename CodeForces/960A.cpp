// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

using namespace std;

int main()
{
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    int i = 0, l = s.length();
    while(i < l && s[i++]=='a') a++;
    i--;
    while(i < l)
    {
        if(s[i] == 'b')
        {
            b++;
        }
        else if(s[i] == 'a')
        {
            cout << "No";
            return 0;
        }
        else break;
        i++;
    }
    while(i < l)
    {
        if(s[i] == 'c')
        {
            c++;
        }
        else if(s[i] == 'a' || s[i] == 'b')
        {
            cout << "No";
            return 0;
        }
        else break;
        i++;
    }
    if(a && b && (c == a || c == b))
    {
        cout << "Yes";
    }
    else
        cout << "No";
    return 0;
}
