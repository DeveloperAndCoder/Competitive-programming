#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
    double x0,y0,x1,y1,x2,y2;
    cin >> setprecision(20) >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    double l1,l2,l3,l;
    l1 = sqrt((y1-y0)*(y1-y0)+(x1-x0)*(x1-x0));
    l2 = sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
    l3 = sqrt((y2-y0)*(y2-y0)+(x2-x0)*(x2-x0));
    double sing, cosi, tang, ans, alpha,theta;
    if(l1 == l2)
    {
        l = l1;
        sing = l3/(2*l2);
        cosi = sqrt(1-(sing)*(sing));
        tang = sing/cosi;
        ans = l1*tang/2;
        alpha = atan(tang);
        alpha*=2;
        alpha = 180-alpha;
        ans *= (360/alpha);
    }
    else if(l1 == l3)
    {
        l = l3;
        sing = l2/(2*l1);
        cosi = sqrt(1-(sing)*(sing));
        tang = sing/cosi;
        ans = l1*tang/2;
        alpha = atan(tang);
        alpha*=2;
        alpha = 180-alpha;
        ans *= (360/alpha);
    }
    else
    {
        cout << l1 << " " << l2 << " " << l3 << endl;
        l = l2;
        sing = l1/(2*l2);
        cosi = sqrt(1-(sing)*(sing));
        theta = asin(sing);
        theta *= 2;
        tang = l1/((2*l2)*(sqrt(1-(l1/(2*l2))*(l1/(2*l2)))));
        ans = l2*tang/2;
        alpha = 180-theta;
        ans *= (360/alpha);
    }
    cout << "alpha = " << alpha << " theta = " << theta << '\n';
    cout << setprecision(20) << ans;
    return 0;
}
