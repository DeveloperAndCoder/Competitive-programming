#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l=0,r=0;
    int x,y;
    while(n--)
    {
        cin >> x >> y;
        if(x > 0)
            r++;
        else
            l++;
    }
    if(r > 1 && l > 1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
