#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <climits>

#define ll long long
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001

int BIT[MAX], n;

using namespace std;

int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
    {
        sum += BIT[x];
    }
    return sum;
}

void update(int x, int val = 1)
{
    for(; x < MAX; x += x&-x)
    {
        BIT[x] += val;
    }
    return;
}

int main()
{
    boost;
    cin >> n;
    vector< pair< pair<int,int>, int> > rating(n+1);
    forn(i,1,n+1)
    {
        int x,y;
        cin >> x >> y;
        rating[i] = {{x,y},i};
    }
    sort(rating.begin()+1, rating.end());
    /*
    cout << endl;
    for(auto it : rating)
    {
        cout << it.fr.fr << " " << it.fr.sc << endl;
    }
    cout << endl;
    */
    int i = 1;
    int ans[n+1] = {0};
    while(i <= n)
    {
        ans[rating[i].sc] = query(rating[i].fr.sc);
        int j = i;
        while(j <= n && rating[j].fr.fr == rating[i].fr.fr && rating[j].fr.sc == rating[i].fr.sc)
            {
                ans[rating[j++].sc] = ans[rating[i].sc];
                update(rating[i].fr.sc);
            }
        i = j;
    }
    forn(i,1,n+1)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
