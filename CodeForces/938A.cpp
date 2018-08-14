#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define eb emplace_back
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    boost;
    int n;
    string s;
    cin >> n >> s;
    int len = s.length();
    int i = 0;
    while(i < len)
    {
        cout << s[i];
        int j = i;
        while(j < len && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y'))
            j++;
        if(j == i)
            j++;
        i = j;
    }
    return 0;
}
