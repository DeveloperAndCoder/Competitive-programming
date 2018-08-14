#include<iostream>
using namespace std;
int main()
{
    unsigned int cards[5];
    unsigned int sum = 0,maxi = 0;
    for (int i = 0; i < 5; i++)
        cin >> cards[i];
    for(int i = 0; i < 5; i++)
        sum+=cards[i];
    unsigned int rep[5] = {0};
    unsigned int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if(cards[i] == cards[j])
            {
                count++;
            }
        }
        count++;
        if(count > 1)
        {
            if(count == 2)
                rep[i] = 2*cards[i];
            else
                rep[i] = 3*cards[i];
        }
        count = 0;
    }

    for(int i = 0; i < 5; i++)
    {
        if(maxi < rep[i])
            maxi=rep[i];
    }
    cout << sum - maxi;
    return 0;
}
