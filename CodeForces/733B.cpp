// Not Correct :-()

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int l[n],r[n];
    long long int i;
    long long int suml = 0, sumr = 0;
    for(i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        suml+=l[i];
        sumr+=r[i];
    }
    long long int maxi;
    long long int pos = 0;
    long long int testi = 0;
    long long int test_sum = abs(l[0]-r[0]);
     for(i = 1; i < n; i++)
        {
            if(abs(l[i] - r[i]) > test_sum)
            {
                test_sum = abs(l[i]-r[i]);
                testi = i;
            }
        }
    if(suml > sumr)
    {
        maxi = -100;
        for(i = 0; i < n; i++)
        {
            if(r[i]-l[i] > maxi)
            {
                maxi = r[i]-l[i];
                pos = i;
            }
        }
        if(maxi >= 0)
        {
        if((sumr + l[testi] - r[testi]) - (suml + r[testi] - l[testi]) > (suml + r[pos] - l[pos]) - (sumr + l[pos] - r[pos]))
            pos = testi;
        }
            else
                pos = -1;
    }
    else
    {
        maxi = -100;
        for(i = 0; i < n; i++)
        {
            if(l[i] - r[i] > maxi)
            {
                maxi = l[i]-r[i];
                pos = i;
            }
        }
   //     cout << maxi << endl;
        if(maxi >= 0)
        {
            if((suml + r[testi] - l[testi] - (sumr + l[testi] - r[testi])) > ((suml + r[pos] - l[pos]) - (sumr + l[pos] - r[pos])))
            pos = testi;
        }
            else
                pos = -1;
    }
    //cout << testi << " "<<(sumr + l[testi] - r[testi]) - (suml + r[testi] - l[testi])<<" "<<(sumr + l[pos] - r[pos]) - (suml + r[pos] - l[testi])<<endl;
    //cout << sumr << " "<< suml <<" "<< l[testi] << " "<<r[testi]<<endl;
    cout << pos + 1;
    return 0;
}
