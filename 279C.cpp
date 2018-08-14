/*
ANURAG SHAH
IIT JODHPUR
*/
#include<iostream>
#include<cstring>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n];
    forn(i,0,n) cin >> a[i];
    int dec[n],inc[n];
    memset(dec,0,sizeof(dec));
    memset(inc, 0, sizeof(inc));
    bool in = 0;
    int i = 1;
    while(i < n)
    {
        if(a[i] > a[i-1])
        {
            if(!in || i == 1)
            {
                inc[i] = inc[i-1]+1;
                in = 1;
            }
            else
            {
                inc[i] = inc[i-1];
            }
            dec[i]=dec[i-1];
        }
        else if(a[i] < a[i-1])
        {
            if(in || i == 1)
            {
                dec[i]=dec[i-1]+1;
                in = 0;
            }
            else
            {
                dec[i] = dec[i-1];
            }
            inc[i]=inc[i-1];
        }
        else
        {
            inc[i]=inc[i-1];
            dec[i]=dec[i-1];
        }
        i++;
    }
    forn(i,0,n) cout << inc[i] << " ";
    cout << endl;
    forn(i,0,n) cout << dec[i] << " ";
    cout << endl;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        if(l==r)
        {
            cout << "Yes\n";
            continue;
        }
        l--;r--;
        int x1 = inc[r]-inc[l];
        int x2 = dec[r]-dec[l];
        if(x1 >= 0 && x1 <= 1 && x2 <= 1 && x2 >= 0)
        {
            if(x1 == 0 || x2 == 0)
            {
                cout << "Yes\n";
            }
            else
            {
                while(r-1 >= l && a[r] == a[r-1])
                    r--;
                if(a[r]-a[r-1] > 0)
                {
                    cout << "No\n";
                }
                else
                {
                    cout << "Yes\n";
                }
            }
        }
        else
        {
            cout << "No\n";
        }
    }
}
