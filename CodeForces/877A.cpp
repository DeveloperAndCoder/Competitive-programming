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
            if(s[i] == 'D')
                {
                    if(i+4 < s.length())
                    {
                        if(s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'i' && s[i+4] == 'l')
                        {
                            if(ans)
                            {
                                ans = false;
                                break;
                            }
                            else
                            {
                                i = i + 5;
                                ans = true;
                            }
                        }
                    }
                }
            if(s[i] == 'O')
                {
                    if(i+3 < s.length())
                    {
                        if(s[i+1] == 'l' && s[i+2] == 'y' && s[i+3] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                break;
                            }
                            else
                            {
                                i = i + 4;
                                ans = true;
                            }
                        }
                    }
                }
                if(s[i] == 'S')
                {
                    if(i+4 < s.length())
                    {
                        if(s[i+1] == 'l' && s[i+2] == 'a' && s[i+3] == 'v' && s[i+4] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                break;
                            }
                            else
                            {
                                i = i + 5;
                                ans = true;
                            }
                        }
                    }
                }
            if(s[i] == 'A')
                {
                    if(i+2 < s.length())
                    {
                        if(s[i+1] == 'n' && s[i+2] == 'n')
                        {
                            if(ans)
                            {
                                ans = false;
                                break;
                            }
                            else
                            {
                                i = i + 3;
                                ans = true;
                            }
                        }
                    }
                }
            if(s[i] == 'N')
                {
                    if(i+5 < s.length())
                    {
                        if(s[i+1] == 'i' && s[i+2] == 'k' && s[i+3] == 'i' && s[i+4] == 't' && s[i+5] == 'a')
                        {
                            if(ans)
                            {
                                ans = false;
                                break;
                            }
                            else
                            {
                                i = i + 6;
                                ans = true;
                            }
                        }
                    }
                }
    }
        if(ans)
            cout << "YES";
        else
            cout << "NO";
    return 0;
}
