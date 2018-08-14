#include<iostream>
#include<string>
using namespace std;

int main()
{
    char s[9][3][3];
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
            for(int k = 0; k < 3; k++)
        {
            cin >> s[i][j][k];
            //cout << s[i][j] << " ";
        }
   // cout << endl;
    }
    for(int j = 0; j < 3; j++)
 {for(int i = 3; i < 6; i++)
 for(int k = 0; k < 3; k++)
    {
        cin >> s[i][j][k];
        //cout << s[i][j] << " ";
    }
    //cout << endl;
}
    for(int j = 0; j < 3; j++)
    for(int i = 6; i < 9; i++)
        for(int k = 0; k < 3; k++)
    {
        cin >> s[i][j][k];
     //   cout << s[i][j];
    }
    /*for(int j = 0; j < 3; j++)
    {for(int i = 6; i < 9; i++)
    {
        cout << s[i][j] << " ";
    }cout << '\n';}
    for(int j = 0; j < 3; j++)
    {for(int i = 0; i < 3; i++)
    {
        cout << s[i][j] << " ";
    }cout << '\n';}
    for(int j = 0; j < 3; j++)
    {for(int i = 6; i < 9; i++)
    {
        cout << s[i][j] << " ";
    }cout << '\n';}
    cout << "\n\n\n";
    */int x,y;
    cin >> x >> y;

    while(x > 3)
        x -= 3;
    while(y > 3)
        y -= 3;
    x--;
    y--;
    int pos = x*3+y;
    bool changed = false;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
    {
        if(s[pos][i][j] == '.')
        {
            s[pos][i][j] = '!';
            changed = true;
        }
    }
    if(changed)
    {
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 3; i++)
        {
         for(int k = 0; k < 3; k++)
            {
                cout << s[i][j][k];
            }
            cout << " ";
        }
        cout << '\n';
    }
   cout << '\n';
    for(int j = 0; j < 3; j++)
    {
        for(int i = 3; i < 6; i++)
        {
         for(int k = 0; k < 3; k++)
            {
            cout << s[i][j][k];
            }
            cout << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int j = 0; j < 3; j++)
    {
        for(int i = 6; i < 9; i++)
        {
         for(int k = 0; k < 3; k++)
            {
            cout << s[i][j][k];
            }
            cout << " ";
        }
        cout << '\n';
    }
    }
    else
    {
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                for(int k = 0; k < 3; k++)

                {
                    if(s[i][j][k] == '.')
                        cout << "!";
                    else
                        cout << s[i][j][k];
                }
            cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    for(int j = 0; j < 3; j++)
        {
            for(int i = 3; i < 6; i++)
            {
                for(int k = 0; k < 3; k++)

                {
                    if(s[i][j][k] == '.')
                        cout << "!";
                    else
                        cout << s[i][j][k];
                }
            cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    for(int j = 0; j < 3; j++)
        {
            for(int i = 6; i < 9; i++)
            {
                for(int k = 0; k < 3; k++)

                {
                    if(s[i][j][k] == '.')
                        cout << "!";
                    else
                        cout << s[i][j][k];
                }
            cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
