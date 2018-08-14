#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double r,d;
    cin >> r >> d;
    double limit = r - d;
    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        double xi,yi,ri;
        cin >> xi >> yi >> ri;
        double dist = sqrt(xi*xi + yi*yi);
        if(dist-ri >= limit && dist+ri <= r)
            ans++;
    }
    cout << ans;
    return 0;
}
