#include<iostream>
#include<algorithm>

using namespace std;

#define fori \
for(int i = 0; i < n; i++)
#define ll long long
#define un unsigned

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    fori
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    if(k != 1)
        cout << arr[k-1];
    else
        cout << arr[0];
    return 0;
}
