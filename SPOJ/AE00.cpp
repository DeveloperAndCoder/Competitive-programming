#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int w = 1;
    long long ans = 0LL;
    for(w = 1; w <= n; w++)
    {
        if(n/w < w) break;
        ans += n/w;
        ans -= (w-1);
    }
    cout << ans;
    return 0;
}
