#include<iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int r = n*m/k;
    int rem = n*m%k;
    int i = 1, j = 1;
    bool rev = 0;
    while(k > 1)
    {
        cout << r << " ";
        int l;
        for(l = 1; l <= r; l++)
        {
            if(j > m)
            {
                j = m;
                i++;
                rev = !rev;
            }
            else if(j < 1)
            {
                j = 1;
                i++;
                rev = !rev;
            }
            cout << i << " " << j << " ";
            rev ? j-- : j++;
        }
        cout << endl;
        k--;
    }
    cout << r+rem << " ";
    int l;
        for(l = 1; l <= r+rem; l++)
        {
            if(j > m)
            {
                j = m;
                i++;
                rev = !rev;
            }
            else if(j < 1)
            {
                j = 1;
                i++;
                rev = !rev;
            }
            cout << i << " " << j << " ";
            rev ? j-- : j++;
        }
    return 0;
}
