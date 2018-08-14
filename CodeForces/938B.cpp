#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define eb emplace_back
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    forn(i,0,n) cin >> a[i];
    bool prize[1000001];
    memset(prize, false, sizeof(prize));
    forn(i,0,n) prize[a[i]] = true;
    int pos1 = 1;
    int pos2 = 1000000;
    int pic = 0;
    int sec = 0;
    while(pic < n)
    {
        if(pos1 > 1)
        sec++;
        if(pos1 == pos2)
        {
            if(prize[pos1])
                pic++;
            pos1++;
            pos2--;
            continue;
        }
        if(prize[pos1])
        {
            pic++;
        }
        if(prize[pos2])
        {
            pic++;
        }
        pos1++;
        pos2--;
        //cout << pic << endl;
    }
    cout << sec;
    return 0;
}
