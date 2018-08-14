#include<iostream>
#include<stdlib.h>

using namespace std;
int partition_(int a[], int b[], int s[], int diff[],  int p, int r);
void swap_(int a[], int b[], int s[],int diff[], int i, int j);
void quick_sort(int a[], int b[], int s[], int diff[],  int p, int r)
{
    if (p >= r)
        return;
    int q = partition_(a,b,s,diff,p,r);
    quick_sort(a,b,s,diff,p,q-1);
    quick_sort(a,b,s,diff,q+1,r);
}

int partition_(int a[], int b[], int s[], int diff[], int p, int r)
{
    if(r-p <= 0)
        return 0;
    //int pivot  = rand() % (p-r) + p;
    int pivot = diff[r];
    //swap_(a,b,s,diff,pivot,r);
    int i = p-1;
    for(int j = p; j < r; j++)
    {
        if(diff[j] <= pivot)
        {
            i++;
            swap_(a,b,s,diff,i,j);
        }
    }
    swap_(a,b,s,diff,i+1,r);
    return i+1;
}

void swap_(int a[], int b[], int s[], int diff[], int i, int j)
{
    if(i==j)
        return;
    int temp = diff[i];
    diff[i] = diff[j];
    diff[j] = temp;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    temp = b[i];
    b[i] = b[j];
    b[j] = temp;

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    return;
}

int main()
{
    int n,s1;
    cin >> n >> s1;
    int s[n], a[n], b[n];
    int i = 0, j = 0;

    for(i = 0; i < n; i++)
        cin >> s[i] >> a[i] >> b[i];

    int diff[n];
    for(i = 0; i < n; i++)
        diff[i] = (abs(a[i] - b[i]))*s[i];

    quick_sort(a , b, s, diff, 0, n-1);

    //Testing sort.
    cout << "\n\n\n";
    for(int i = 0; i < n; i++)
        cout << s[i] << " " << a[i] << " " << b[i] << endl;         //Passed.

        cout << "\n\n\n";
    int pizza = 0;
    for(i = 0; i < n; i++)
        pizza += s[i];
    if(pizza % s1 == 0)
        pizza = pizza/s1;
    else{
        pizza = pizza/s1;
        pizza++;
    }

    int na = 0;
    int nb = 0;
    int happy = 0;


    /*for(i = n-1; i >= 0; i--)
    {

        cout << "i = "<<i << ":\n";
        if(a[i] > b[i])
        {
            if(na < s[i])
            na += s1;
            if(na+nb <= pizza*s1)
                happy += s[i] * a[i];
            else
                {
                    na-=s1;
                    happy += na*a[i];
                    happy += (s[i]-na)*b[i];
                    nb += s[i] - na;
                }
            cout << "1.na = " << na << "nb = " << nb <<" happy = " << happy << endl;
        }
        else
        {
            if(nb < s[i])
            nb += s1;
            if(na+nb <= pizza*s1)
                happy += s[i] * a[i];
            else
                {
                    nb-=s1;
                    happy += nb*b[i];
                    happy += (s[i]-nb)*a[i];
                    na += s[i] - nb;
                }
                cout << "na = " << na << "nb = " << nb <<" happy = " << happy << endl;
        }
    }
    */
    cout << "pizza = " << pizza << endl;
    int x1 = 0;
    int x2 = 0;
    int p = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] > b[i])
        {
            if(x1 > s[i])
                x1 -= s[i];
            else
            {
                if(p < pizza)
                {
                    x1 += s1;
                    happy += a[i] * s[i];
                    x1 -= s[i];
                    p++;
                }
                else
                {
                    happy += a[i] * (x1);
                    happy += b[i] * (s[i]-x1);
                    x1 = 0;
                    x2 -= (s[i]-x1);
                }
            }
        }
        else
        {
            if(x2 > s[i])
                x2 -= s[i];
            else
            {
                if(p < pizza)
                {
                    x2 += s1;
                    happy += b[i] * s[i];
                    x2 -= s[i];
                    p++;
                }
                else
                {
                    happy += b[i] * (x2);
                    happy += a[i] * (s[i]-x2);
                    x2 = 0;
                    x1 -= (s[i]-x2);
                }
            }
        }
    }
    cout << happy;

    return 0;
}
