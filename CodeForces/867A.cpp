#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ftos = 0;
    int stof = 0;
    char curr,past;
    cin >> past;
    n--;
    while(n--)
    {
        cin >> curr;
        if(curr == 'F' && past == 'S')
        {
            stof++;
        }
        else if(curr == 'S' && past == 'F')
        {
            ftos++;
        }
        past = curr;
    }
    if(stof > ftos)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
