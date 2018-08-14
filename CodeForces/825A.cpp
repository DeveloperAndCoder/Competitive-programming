//Accepted!

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string c;
    cin >> c;
    int count1 = 0, count0 = 0;
    if(n == 1)
    {
        cout << c[0];
        return  0;
    }
    else
    {
        if(c[0] == '1')
        count1++;
        else
        count0++;
        for(int i = 1; i < n; i++)
        {
            if(c[i] == '1' && c[i-1] == '1')
            count1++;
            else if(c[i] == '1' && c[i-1] == '0')
            {
                if(count0 > 1)
                {
                    for(int i = 0; i < count0 - 1; i++)
                        cout << 0;
                }
                count0 = 0;
                count1++;
            }
            else if(c[i] == '0' && c[i-1] == '0')
            {
                count0++;
            }
            else if(c[i] == '0' && c[i-1] == '1')
            {
                cout << count1;
                count1=0;
                count0++;
            }
        }
        if(count1 > 0)
        cout << count1;
        else if(count0 > 1)
        {
            for(int i = 0; i < count0; i++)
                cout << 0;
        }
        else
        cout << c[n-1];
    }
    return 0;
}
