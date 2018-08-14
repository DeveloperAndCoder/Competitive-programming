#include<iostream>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        int i = 1;
        int ans = 0;
        while(n >= 10)
        {
            ans += 9*i;
            i *= 10;
            n -= 9;
        }
        ans += n*i;
        cout << ans+1 << endl;
    }
    return 0;
}
