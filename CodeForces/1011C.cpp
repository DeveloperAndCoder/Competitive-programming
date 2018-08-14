#include <iostream>
#include <cmath>
#include <iomanip>

#define eps 0.0000001
using namespace std;

bool isok(int n, int m, int a[], int b[], double fuel)
{
    double weight = m + fuel;
    double req = weight/a[0];
    if(fuel < req || fuel-req < -eps) return false;
        fuel -= req;
    weight -= req;
    for(int i = 1; i < n; i++)
    {
        double req = (weight/b[i]);
        if(fuel < req || fuel-req < -eps) return false;
        fuel -= req;
        weight -= req;
        req = weight/a[i];
        if(fuel < req || fuel-req < -eps) return false;
        fuel -= req;
        weight -= req;
    }
    req = weight/b[0];
    if(fuel < req || fuel-req < -eps) return false;
        fuel -= req;
    weight -= req;
    return true;
}

double solve(int n, int m, int a[], int b[])
{
    double low = 0, high = 1e9;
    while(abs(high-low) > eps && low < high)
    {
        double mid = low + (high-low + 0.0)/2;
      //  cout << mid << endl;
        if(isok(n,m,a,b,mid))
            high = mid;
        else {
                if(mid == 1e9) return -1;
                low = mid+eps;
        }
    }
    //cout << "low = " << low << " high = " << high << endl;
    return low;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    double ans = solve(n,m,a,b);
    if(ans == -1) cout << -1;
    else
    cout << fixed << setprecision(7) << ans;
    return 0;
}
