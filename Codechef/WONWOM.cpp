#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define forn(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int compare(const string& s1, const string& s2)
{
    string a = s1+s2;
    string b = s2+s1;
    if(a > b) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    forn(i,0,n) cin >> s[i];
    sort(s.begin(), s.end(), compare);

    forn(i,0,n) cout << s[i];
}
