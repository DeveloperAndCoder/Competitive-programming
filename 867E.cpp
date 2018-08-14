#include<iostream>
using namespace std;
int find_min(int a[], int n)
{
    int i=0;
    int min_i = 0;
    while(a[i]==0&&i<n)
          {
              i++;
          }
    min_i=i;
    for(; i < n; i++)
    {
        if(a[i] == 0)
            continue;
        if(a[i] < a[min_i])
            min_i = i;
    }
    return min_i;
}

int find_max(int a[], int ind, int n)
{
    int m_i = ind;
    int i = 0;
    for(i = ind+1; i < n; i++)
    {
        if(a[i] > a[m_i])
            m_i = i;
    }
    return m_i;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i;
    for(i = 0; i < n; i++)
        cin >> a[i];
    int p = 0;
    while(1)
    {
        if (n == 0)
            break;
        int ind = find_min(a, n);
        int m_ind = find_max(a, ind, n);
       // cout << "ind = " << ind << " m_ind = " << m_ind << endl;
        if(ind == n-1)
        {
            a[ind] = 0;
            n--;
            continue;
        }
        if(a[m_ind] == 0)
        {
            break;
        }
        p += a[m_ind] - a[ind];
        a[m_ind] = 0;
        a[ind] = 0;
    }
    cout << p;
}
