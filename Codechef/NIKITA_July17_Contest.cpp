#include<iostream>
#include<stdio.h>
using namespace std;

int space_in_word (string s)
{
    int len = s.length();
    int i = 0;
    int count = 0;
    for (i; i < len; i++)
        if (s[i] == ' ')
            count++;
        return count;
}

void reorder (string* s)
{
    int len = (*s).length();
    int i = 0;
    bool x = false;
    cout << (int)(*s)[0] << " s[0] ";
    if((int)(*s)[0] >= 97)
        (*s)[0]-=32;
    for (i  = 0; i < len; i++)
    {
        if ((*s)[i] == ' ')
        {
            continue;
            x = true;
        }
        if (x)
        {
            if((*s)[i] > 90)
                (*s)[i] -= 32;
                x = false;
        }
        else
        {
            if((*s)[i] <= 90)
                (*s)[i] += 32;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++)
    {
       // cout << "taking input ";
        getline(cin,s[i]);
       // cout << s[i] << endl;
    }
    for(int test = 0; test < n; test++)
    {
        int space = space_in_word(s[test]);
        if(space == 0)
        {
            reorder(&s[test]);
            cout << s[test];
        }
        else if(space == 1)
        {
            reorder(&s[test]);
            cout << s[test][0];
            int i = 0;
            while(s[test][i] != ' ')
            {
                cout << "in";
                i++;
            }
            i++;
            for(int k = i; k < s[test].length(); k++)
                cout << s[test][k];
        }
        else if(space == 2)
        {
            reorder(&s[test]);
            cout << s[test][0];
            int i = 0;
            while(s[test][i] != ' ')
            {
                i++;
            }
            i++;
            cout << s[test][i] << ". ";
            while(s[test][i] != ' ')
                i++;
            i++;
            for(int k = i; k < s[test].length(); k++)
                cout << s[test][k];
        }
        cout << endl;
    }
}
