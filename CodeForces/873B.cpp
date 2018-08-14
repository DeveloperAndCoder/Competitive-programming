#include<iostream>
#include<map>
#include<vector>
#define forn(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int cnt = 0,m = 0;
    map<int, int> len;
    len[0] = -1;
    forn(i,0,n)
    {
        if(a[i] == '0') cnt++;
        else cnt--;
        if(len.count(cnt))
            m = max(m, i-len[cnt]);
        else
            len[cnt] = i;
    }
    cout << m;
    return 0;
}
