#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <map>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001
#define N 1000001

using namespace std;

int main()
{
    string color[] = {"purple", "green", "blue", "orange", "red", "yellow"};
    map<string, string> gem;
    gem["purple"] = "Power";
    gem["green"] = "Time";
    gem["blue"] = "Space";
    gem["orange"] = "Soul";
    gem["red"] = "Reality";
    gem["yellow"] = "Mind";
    map<string, bool> present;
    forn(i,0,6)
    present[color[i]] = false;
    int n;
    cin >> n;
    forn(i,0,n)
    {
        string s;
        cin >> s;
        present[s] = true;
    }
/*
    forn(i,0,6)
    {
        cout << present[color[i]] << " " << gem[color[i]] << endl;
        //if(i == 6) return 0;
    }
    exit(0);
    */
    vector<string> ans;
    forn(i,0,6)
    {
        if(!present[color[i]])
            ans.pb(gem[color[i]]);
    }
    cout << ans.size() << endl;
    forn(i,0,ans.size())
    {
        cout << ans[i] << endl;
    }
}
