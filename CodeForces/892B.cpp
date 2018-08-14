#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int range[n];
    for(int i = 0; i < n; i++)
        cin >> range[i];
    for(int i = 0; i < n; i++)
    {
        if(i-range[i] >= 0)
            range[i] = i-range[i];
        else
            range[i] = 0;
    }
    bool alive[n];
    for(int i =  0; i < n; i++)
        alive[i] = true;
    int minr = n;
    for(int i = n-1; i>=0; i--)
    {
        if(minr <= i)
        {
            alive[i] = false;
        }
        minr = min(minr, range[i]);
    }
    /*
    for(int i = 0; i < n; i++)
        cout << range[i] << " ";
    cout << endl;
    */
    int c = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(alive[i] == true)
            c++;
    }
    cout << c;
    return 0;
}
