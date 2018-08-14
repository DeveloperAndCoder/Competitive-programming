// Accepted

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
        int max_h = 0;
    for(int i = 0; i < n; i++)
    {
        max_h = h[i];
        for(int j = i+1; j < n; j++)
        {
            if(h[j] > max_h)
            {
                max_h = h[j];
            }
        }
        if(max_h != h[i])
            max_h++;
            cout << max_h -h[i] << " ";
    }
        return 0;
}
