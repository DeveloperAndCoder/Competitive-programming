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
#define forn(i,a,b) for(ll i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1000001

using namespace std;

void initialize(int Arr[], int Size[], int n)
{
    forn(i,0,n)
    {
        Arr[i] = i;
        Size[i] = 1;
    }
    return;
}

int root(int Arr[], int n, int i)
{
    while(i != Arr[i]) {
        Arr[i] = Arr[Arr[i]];
        i = Arr[i];
    }
    return i;
}

void weighted_union(int Arr[], int Size[], int n, int A, int B)
{
    int rootA = root(Arr, n, A);
    int rootB = root(Arr, n, B);
    if(Size[rootA] < Size[rootB])
    {
        Arr[rootA] = rootB;
        Size[rootB] += Size[rootA];
    }
    else
    {
        Arr[rootB] = rootA;
        Size[rootA] += rootB;
    }
    return;
}

int main()
{
    boost;
    int n, m;
    cin >> n >> m;
    int Arr[n], Size[n];
    initialize(Arr, Size, n);
    forn(i,0,m)
    {
        int a,b;
        cin >> a >> b;
        weighted_union(Arr, Size, n, a, b);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int A, B;
        cin >> A >> B;
        if(root(Arr, n, A) == root(Arr, n, B)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
