// Author : Anurag Shah
// @Copyright : 2018
// IIT Jodhpur

#include<iostream>
#include<string>
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

#define M 2000000000
const int mod = 1000000007;

using namespace std;

int main()
{
    set< pair<ll, int> > ele;
    int n;
    cin >> n;
    forn(i,0,n)
    {
        int a;
        cin >> a;
        ele.insert(make_pair(a, i));
    }
    set< pair<int, ll> > ans;
    while(!ele.empty())
    {
        set< pair<ll,int> >::iterator it = ele.begin();
        pair<ll, int> p1 = *it;
        ele.erase(it);
        it = ele.begin();
        if(!ele.empty())
        {
            if((*it).fr == p1.fr)
            {
                p1.sc = (*it).sc;
                ele.erase(it);
                ele.insert(make_pair(p1.fr*2, p1.sc));
            }
            else
            {
                ans.insert(make_pair(p1.sc, p1.fr));
            }
        }
        else
        {
            ans.insert(make_pair(p1.sc, p1.fr));
        }
    }
    cout << ans.size() << endl;
    for(auto it: ans)
    {
        cout << it.sc << " ";
    }
}
