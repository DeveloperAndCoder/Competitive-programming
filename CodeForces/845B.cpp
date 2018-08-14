#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    int sum_1 = (int)(arr[0]-48 + arr[1]-48 + arr[2]-48);
    int sum_2 = (int)(arr[3]-48 + arr[4]-48 + arr[5]-48);
    //cout << sum_1 << "\n" << sum_2 << "\n";
    int m;
    if(sum_1 < sum_2)
    {
        m = min(arr[0],min(arr[1],arr[2]));
        sum_1 -= (m-48);
    }
    else if(sum_1 > sum_2)
    {
        m = min(arr[3],min(arr[4],arr[5]));
        sum_2 -= (m-48);
    }
   // cout << sum_1 << "\n" << sum_2 << "\n";
    if(abs(sum_1-sum_2) == 0)
    cout << 0;
    else if(abs(sum_1-sum_2) <= 9 && abs(sum_1-sum_2) >= 1)
    cout << 1;
    else if(abs(sum_1-sum_2) >= 10 && abs(sum_1-sum_2) <= 19)
    cout << 2;
    else
    cout << 3;
    return 0;
}
