#include<iostream>
#include<math.h>
using namespace std;
int num(int a[], int n, int i);
int main()
{
    int n, m;
    cin >> n >> m;
    bool x;

    int row_1[n] = {0};
    int row_0[n] = {0};
    int col_1[m] = {0};
    int col_0[m] = {0};

    int A[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
         cin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(A[i][j])
                row_1[i]++;
            else
                row_0[i]++;
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(A[i][j])
            {
                col_1[j]++;
            }
            else
            {
                col_0[j]++;
            }
        }
    }
    /*
    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << row_1[i] << " ";
        cout << "\n";
    for(int i = 0; i < n; i++)
        cout << row_0[i] << " ";
        cout << "\n";
    for(int i = 0; i < m; i++)
        cout << col_1[i] << " ";
        cout << "\n";
        for(int i = 0; i < m; i++)
        cout << col_0[i] << " ";
        cout << "\n";cout << "\n";cout << "\n";
        */

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += num(row_1, n, i);
        ans += num(row_0, n, i);
    }
    for(int i = 0; i < m; i++)
    {
        ans += num(col_1, m, i);
        ans += num(col_0, m, i);
    }
    cout << ans+n*m;
}
int num(int a[], int n, int i)
{
    return (a[i]*(a[i]-1))/2;
}
