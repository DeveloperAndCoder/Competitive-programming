#include<iostream>
#include<string>
//"Danil", "Olya", "Slava", "Ann" and "Nikita".
using namespace std;

int main()
{
    string s;
    cin >> s;
    unsigned int i = 0;
    bool ans = false;
    for(i = 0; i < s.length(); i++)
    {
        switch(s[i])
        {
            case 'D':
                {
                    if(i+4 < s.length())
                    {
                        if(s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'i' && s[i+4] == 'l')
                        {
                            if(ans)
                            {
                                ans = false;
                                goto hell;
                            }
                            else
                                ans = true;
                        }
                    }
                    break;
                }
            case 'O':
                {
                    if(i+3 < s.length())
                    {
                        if(s[i+1] == 'l' && s[i+2] == 'y' && s[i+3] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                goto hell;
                            }
                            else
                                ans = true;
                        }
                    }
                    break;
                }
                case 'S':
                {
                    if(i+4 < s.length())
                    {
                        if(s[i+1] == 'l' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                goto hell;
                            }
                            else
                                ans = true;
                        }
                    }
                    break;
                }
            case 'A':
                {
                    if(i+2 < s.length())
                    {
                        if(s[i+1] == 'n' && s[i+2] == 'n')
                        {
                            if(ans)
                            {
                                ans = false;
                                goto hell;
                            }
                            else
                                ans = true;
                        }
                    }
                    break;
                }
            case 'N':
                {
                    if(i+5 < s.length())
                    {
                        if(s[i+1] == 'i' && s[i+2] == 'k' && s[i+3] == 'i' && s[i+4] == 't' && s[i+5] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                goto hell;
                            }
                            else
                                ans = true;
                        }
                    }
                    break;
                }
            default:
                {
                    break;
                }
        }
    }
    hell:
        if(ans)
            cout << "YES";
        else
            cout << "NO";
    return 0;
}
