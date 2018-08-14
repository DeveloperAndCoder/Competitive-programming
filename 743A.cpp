#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    string comp;
    cin >> comp;
    if (comp[a-1] == comp[b-1])
        cout << "0";
    else
    {
        int i = a-2;
        int min = 1000000;
       while(i >= 0 && (comp[i] == comp[a-1]))
            i--;
       if(i>=0)
       {
           if(min > (a-1-i))
            min = a-1-i;
       }
       i = a;
        while(i <=n-1 && (comp[i] == comp[a-1]))
            i++;
        if(i <= n-1)
        {
            if(min > (i - (a-1)))
                min = i - (a-1);
        }
        i = b;
        while(i <=n-1 && (comp[i] == comp[b-1]))
            i++;
        if(i <= n-1)
        {
            if(min > (i - (b-1)))
                min = i - (b-1);
        }
        i = b-2;
        while(i >= 0 && (comp[i] == comp[b-1]))
            i--;
        if(i >= 0)
        {
            if(min > (b-1-i))
                min = b-1-i;
        }
        cout << min;
    }
    return 0;
}
