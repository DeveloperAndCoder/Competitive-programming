#include<iostream>
using namespace std;

int ooo(long long n)
{
    int cnt = 0;
    while(n)
    {
        if(n&1) cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int a, b;
        cin >> a >> b;
        int n1 = ooo(a);
        int n2 = ooo(b-1);

        if(a == b) cout << 0;
        else if(b == 0) cout << -1;
        else if(b == 1 && a != 0) cout << -1;
        else if(n1 > n2) cout << 2;
        else cout << n2-n1+1;
        cout << endl;
    }
    return 0;
}
