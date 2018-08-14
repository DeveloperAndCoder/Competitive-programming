#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<math.h>

#define forn(i,a,b) for(int i = a;i < b; i++)

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    int x[n];
    forn(i,0,n) cin >> x[i];
    vector<double> y(n, -1);
    forn(i,0,n)
    {
        int j;
        int maxi = -1;
        int ma = -1;
        for(j = i-1; j >= 0; j--)
        {
            //cout << "compare ";
            //cout << x[j]-r <<  " " <<x[i] << " " << x[j]+r<<endl;
            if((x[i]+r >= x[j]-r && x[i]+r <= x[j]+r) || (x[i]-r >= x[j]-r && x[i]-r <= x[j]+r) )
                {
                        ma = y[j];
                        maxi = j;
                        double base = abs(x[i]-x[maxi]);
                        double hyp = 2*r;
                        y[i] = max(y[i], y[maxi]+sqrt(hyp*hyp - base*base));
                }
        }
        if(maxi >= 0)
        {
            //cout << i << " " << j << "\n";
        }
        else
        {
            y[i] = r;
        }
    }
    forn(i,0,n) cout << setprecision(20) << y[i] << " ";
    return 0;
}
