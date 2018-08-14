#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>

#define ll long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX 1000001

using namespace std;



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        map<int,int> mp;
        int a[n];
        forn(i,0,n){
         cin >> a[i];
        mp[a[i]]++;
        }
        ll pizza = 0;
        /*
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
        */
        forn(i,0,n)
        {
            if(mp.find(m-a[i]) != mp.end())
            {
                if(mp.find(m-a[i])->second)
                    {
                        pizza++;
                        mp.find(m-a[i])->second--;
                    }
            }
        }
        cout << pizza/2 << endl;
    }
}
