#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int alice = 0;
    int sum1 = sum;
    sum /= 2;
    int i = 0;
    while(alice <= sum && i < n)
    {
        alice += a[i];
        i++;
    }
    i--;
    //cout << "alice = " << alice << " " << sum1 << " " << i << endl;
    if(alice-a[i] <= sum1-alice)
    {
        cout << i+1 << " " << n-i-1;
    }
    else
    {
        alice -= a[i];
        cout << i << " " << n-i;
    }
    return 0;
}
