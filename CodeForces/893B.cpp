#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = 1;
    int k = 1, y = 1;
    int ans = x;
    while(x <= n)
    {
        x=y;
        x <<= 1;
        x = x|1;
        y=x;
       // cout << x;
        x <<= k;
      //  cout << " " << x << endl;
        if(ans < x && n%x==0)
            ans = x;
        k++;
    }
    cout << ans;
    return 0;
}
