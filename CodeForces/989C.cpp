#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(int i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

char arr[50][50];

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int n = 0, m = 0;
    vector<char> v(4);
    v[0] = 'a';
    v[1] = 'b';
    v[2]='c';
    v[3] = 'd';
    while(!v.empty())
    {
        int i = 0;
        while(n == 0 && i < 50)
        {
            if(a == 0) v.erase(find(v.begin(), v.end(), 'a'));
            if(b == 0) v.erase(find(v.begin(), v.end(), 'b'));
            if(c == 0) v.erase(find(v.begin(), v.end(), 'c'));
            if(d == 0) v.erase(find(v.begin(), v.end(), 'd'));
            grid[n][i] = v[i%v.size()];
            if(v[i%v.size()] == 'a') a--;
            else if(v[i%v.size()] == 'b') b--;
            else if(v[i%v.size()] == 'c') c--;
            else if(v[i%v.size()] == 'd') d--;
            i++;
        }
        while(n != 0 && i < 50)
        {

        }
        n++;
    }
}
