#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <iomanip>

#define forn(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool prime(int n)
{
    if(n == 2) return true;
    if(n%2 == 0) return false;
    for(int i = 3; i <= sqrt(n)+1; i+= 2)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for(int m = 1; m <= 1000; m++)
    {
        int c = n*m+1;
        if(!prime(c))
        {
            cout << m;
            return 0;
        }
    }
    return 0;
}
