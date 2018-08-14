#include<iostream>

using namespace std;

int main()
{
    int n, c, max=0;
    cin >> n >> c;
    int price[n];
    int i=0;
    for(i;i<n;i++)
        cin >> price[i];
    for(i = 0;i < n-1; i++)
    {
        if(max < (price[i]-price[i+1]-c))
            max = price[i]-price[i+1]-c;
    }
    cout << max;
}
