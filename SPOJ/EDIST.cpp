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
#define MAX 1000001
#define N 1000001

using namespace std;

int dp[2001][2001], ans = 0;

int lcs(const string &A, const string &B, int i, int j)
{
    //cout << i << " " <<  j << endl;
    if(i < 0 || j < 0)
    {
        if(j >= 0) return j+1;
        else if(i >= 0) return i+1;
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(A[i] == B[j])
    {
        dp[i][j] = lcs(A,B,i-1,j-1);
    }
    else
    {
        dp[i][j] = min(lcs(A,B,i-1,j-1), min(lcs(A,B,i,j-1), lcs(A,B,i-1,j)))+1;
    }
    return dp[i][j];
}

int main()
{
    boost;
    int t;
    cin >> t;
    while(t--)
    {
        forn(i,0,2001)
        forn(j,0,2001)
        dp[i][j] = -1;
        string A,B;
        cin >> A >> B;
        int n1 = A.size(), n2 = B.size();
        int n = abs(n1-n2);
        int m = min(n1,n2);
        cout << lcs(A, B, A.size()-1, B.size()-1) << endl;
    }
    return 0;
}
