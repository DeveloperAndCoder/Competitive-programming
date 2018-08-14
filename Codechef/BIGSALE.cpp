#include<iostream>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        double p[n],q[n],dis[n];
        forn(i,0,n) cin >> p[i] >> q[i] >> dis[i];
        double np,loss=0;
        forn(i,0,n)
        {
            np = ((p[i]*dis[i]/100.0) + p[i]);
            np = np - np*dis[i]/100.0;
            loss += (p[i]-np)*q[i];
        }
        cout << fixed << loss << '\n';
    }
    return 0;
}
