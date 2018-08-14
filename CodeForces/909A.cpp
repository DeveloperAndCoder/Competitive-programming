#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main()
{
    string n,sn;
    cin >> n >> sn;
    string ans;
    ans.push_back(n[0]);
    int len = 1;
    while(len < n.size() && n[len]<sn[0])
    {
        ans.push_back(n[len]);
        len++;
    }
    ans.push_back(sn[0]);
    cout << ans;
}
