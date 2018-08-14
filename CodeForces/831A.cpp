#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int curr,prev;
    bool les = false;
    bool eq = false;
    for(int i = 0; i < n; i++)
    {
        cin >> curr;
        if(i == 0)
        {
            prev = curr;
            continue;
        }

        if(prev > curr)
        {
            les = true;
        }
        else if(prev < curr)
        {
            if(les || eq)
            {
                cout << "NO";
                return 0;
            }
        }
        else if (prev == curr)
        {
            if(les)
            {
                cout << "NO";
                return 0;
            }
            eq = true;
        }

            prev = curr;

    }
    cout << "YES";
    return 0;
}
