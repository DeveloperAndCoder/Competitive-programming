#include<iostream>

using namespace std;

int main()
{
    int b,g,r;
    cin >> r >> b >> g;
    int mn,mx;
    mn = min(r,min(b,g));
    int ans = 0;
    ans = mn;
    r -= mn;
    b -= mn;
    g -= mn;
    mx = 0;
    mn = 0;
    if(r && b)
    {
        mn = min(r,b);
        mx = max(r,b);
    }
    else if(b && g)
    {
        mn = min(b,g);
        mx = max(b,g);
    }
    else if(r && g)
    {
        mn = min(r,g);
        mx = max(r,g);
    }
 // cout << r << " " << b << " " << g << " " << mx <<  " " << mn << " " << ans << endl;
        int add;
      add = min(mx/2, mn);
      if(add == mx/2)
      {
        mx %= 2;
        mn -= add;
      }
      else
      {
          mx -= add;
          mn = 0;
      }
      ans += add;
 //     cout << add << endl;
  if(mx && mn>1) ans++;
    cout << ans;
    return 0;
}
