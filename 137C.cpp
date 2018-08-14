// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back
#define pb push_back
#define fr first
#define sc second
#define sins insert

typedef long long ll;

#define M 1000000000
const int mod = 1000000007;

using namespace std;

bool cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.sc>p2.sc;
}

int main()
{
    boost;
   int n;
   cin >> n;
   pair<int, int> p[n];
   forn(i,0,n)
   {
       cin >> p[i].fr >> p[i].sc;
   }
   sort(p,p+n,cmp);
   int ans = 0, min = p[0].fr+1;
   forn(i,0,n)
   {
       if(min > p[i].fr)
        {
            min = p[i].fr;
            continue;
        }
       ans++;
   }
   cout << ans;
   return 0;
}
