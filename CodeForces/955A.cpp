#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<stack>

#define forn(i,a,n) for(int i = 0; i < n; i++)
#define ll long long
#define eb emplace_back
#define mem(array,value) memset(array, value, sizeof(array))

using namespace std;

int main()
{
    string hh,mm;
    cin >> hh >> mm;
    int h,d,c,n;
    cin >> h >> d >> c >> n;
    double ans = (ceil((h+0.0)/n))*c;
    //cout << ans << " " << ceil((h+0.0)/n) << endl;
    int diff=0;
    if(hh[0] == '2')
    {
        ans *= 0.8;
        cout << ans;
        return 0;
    }
    while(hh[0] != '2')
    {
        if(mm[1] != '9')
        mm[1]++;
        else
        {
            if(mm[0] != '5')
            {
                mm[0]++;
                mm[1]='0';
            }
            else
            {
                if(hh[1] == '9')
                {
                    hh[1] = '0';
                    hh[0]++;
                    mm[0] = '0';
                    mm[1] = '0';
                }
                else
                {
                    hh[1]++;
                    mm[0] = '0';
                    mm[1] = '0';
                }
            }
        }
       // cout << hh << " " << mm << endl;
        diff++;
    }
    ans = min(ans, ceil(((diff*d)+h+0.0)/n)*c*0.8);
    cout << setprecision(12) << fixed << ans;
    return 0;
}
