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
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int test;
    cin >> test;
    int n[10], a[10], k;
    while(test--)
    {
        for(int i = 0; i < 10; i++)
        cin >> n[i];
        cin >> k;

        bool solved = false;

        for(int i = 0; i < 10; i++) a[i] = i;

        do
        {
            int k1 = 0;
            forn(i,0,10)
            {
                k1 += n[i]*a[i];
            }
            if(k1 <= k)
            {
                solved = true;
                print(a, 10);
                break;
            }
        }while(next_permutation(a, a+10));

        if(!solved) cout << -1;
        cout << endl;
    }
    return 0;
}
