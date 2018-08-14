#include<iostream>

using namespace std;

int calc(int curr)
{
    int ans = 0;
    int pow = 1;
    while(curr)
    {
        ans = ans+(curr&1)*pow;
        pow *= 10;
        curr>>=1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int curr = 1;
    int decode = 1;
    int ans = 0;
    while(decode <= n)
    {
        ans++;
        curr++;
        decode = calc(curr);
    }
    cout << ans;
    return 0;
}
